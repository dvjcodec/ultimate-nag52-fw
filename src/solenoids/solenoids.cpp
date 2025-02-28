#include "solenoids.h"
#include "esp_log.h"
#include "esp_adc_cal.h"
#include "pins.h"

esp_adc_cal_characteristics_t adc1_cal;
bool all_calibrated = false;

Solenoid::Solenoid(const char *name, gpio_num_t pwm_pin, uint32_t frequency, ledc_channel_t channel, ledc_timer_t timer)
{
    this->channel = channel;
    this->timer = timer;
    this->ready = true; // Assume ready unless error!
    this->name = name;
    this->adc_reading = 0;
    this->adc_reading_mutex = portMUX_INITIALIZER_UNLOCKED;
    this->vref = 0;
    this->vref_calibrated = false;
    this->default_freq = frequency;

    ledc_timer_config_t timer_cfg = {
        .speed_mode = ledc_mode_t::LEDC_HIGH_SPEED_MODE, // Low speed timer mode
        .duty_resolution = LEDC_TIMER_12_BIT,
        .timer_num = timer,
        .freq_hz = frequency,
        .clk_cfg = LEDC_AUTO_CLK};
    // Set the timer configuration
    esp_err_t res = ledc_timer_config(&timer_cfg);
    if (res != ESP_OK)
    {
        this->ready = false;
        ESP_LOGE("SOLENOID", "Solenoid %s timer init failed. Status code %d!", name, res);
        return;
    }

    // Set PWM channel configuration
    ledc_channel_config_t channel_cfg = {
        .gpio_num = pwm_pin,
        .speed_mode = ledc_mode_t::LEDC_HIGH_SPEED_MODE,
        .channel = channel,
        .intr_type = LEDC_INTR_DISABLE, // Disable fade interrupt
        .timer_sel = timer,
        .duty = 0,
        .hpoint = 0};

    res = ledc_channel_config(&channel_cfg);
    if (res != ESP_OK)
    {
        this->ready = false;
        ESP_LOGE("SOLENOID", "Solenoid %s channel init failed. Status code %d!", name, res);
        return;
    }
    ESP_LOGI("SOLENOID", "Solenoid %s init OK!", name);
}

void Solenoid::write_pwm(uint8_t pwm)
{
    esp_err_t res = ledc_set_duty_and_update(ledc_mode_t::LEDC_HIGH_SPEED_MODE, this->channel, (uint32_t)pwm << 4, 0); // Convert from 8bit to 12bit
    if (res != ESP_OK) {
        ESP_LOGE("SOLENOID", "Solenoid %s failed to set duty to %d!", name, pwm);
    }
}

void Solenoid::write_pwm_percent_with_voltage(uint16_t percent, uint16_t curr_v_mv) {
    if (percent == 0) {
        this->write_pwm_percent(0);
    }
    uint16_t want_percent = (float)percent * solenoid_vref / (float)curr_v_mv;;
    if (want_percent > 1000) {
        want_percent = 1000; // Clamp to max
    }
    ESP_LOGI("SOLENOID", "WPPWV (%s) converting %u to %d", this->name, percent, want_percent);
    this->write_pwm_percent(want_percent);

}

uint16_t Solenoid::get_vref() const {
    return this->vref;
}

void Solenoid::write_pwm_percent(uint16_t percent) {
    uint32_t clamped = (percent > 1000) ? 1000 : percent;
    uint32_t request = (255 * clamped) / 1000;
    this->write_pwm(request);
}

uint8_t Solenoid::get_pwm()
{   
    return ledc_get_duty(LEDC_HIGH_SPEED_MODE, this->channel) >> 4;
}

uint16_t Solenoid::get_current_estimate()
{
    portENTER_CRITICAL(&this->adc_reading_mutex);
    uint16_t r = this->adc_reading - this->vref; // Vref is static noise on the line, discount it
    portEXIT_CRITICAL(&this->adc_reading_mutex);
    /**
     * Calibration data from ADC:
     * 65535 - 3300 mv (6.6A)
     * 0 - 0mV (0A)
     * 
     * With 0.005Ohm shunt resistor and INA180A3 amplifier:
     * 3000mV = 6000mA
     * 1500mV = 3000mA
     * 0mV = 0mA
     */

    // Convert ADC reading to approx mV
    // Voltage = ADC_READING * 0.0487
    // Current = Voltage * 2
    //
    // So basically current = ADC_READING * 0.0974
    return r*0.0974;
}

void Solenoid::__set_current_internal(uint16_t c)
{
    portENTER_CRITICAL(&this->adc_reading_mutex);
    this->adc_reading = c;
    portEXIT_CRITICAL(&this->adc_reading_mutex);
}

void Solenoid::__set_vref(uint16_t ref)
{
    portENTER_CRITICAL(&this->adc_reading_mutex);
    this->vref = ref;
    this->vref_calibrated = true;
    portEXIT_CRITICAL(&this->adc_reading_mutex);
}

bool Solenoid::init_ok() const
{
    return this->ready;
}

Solenoid *sol_y3 = nullptr;
Solenoid *sol_y4 = nullptr;
Solenoid *sol_y5 = nullptr;

Solenoid *sol_mpc = nullptr;
Solenoid *sol_spc = nullptr;
Solenoid *sol_tcc = nullptr;

#define BYTES_PER_SAMPLE 2
#define NUM_SAMPLES 1024

char dma_buffer[BYTES_PER_SAMPLE*NUM_SAMPLES];


const i2s_config_t i2s_config = {
    .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_ADC_BUILT_IN),
    .sample_rate = 200000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_ALL_LEFT,
    .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_STAND_MSB),
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = NUM_SAMPLES,
    .use_apll = false,
    .tx_desc_auto_clear = false,
    .fixed_mclk = false
};

void read_solenoids_i2s(void*) {
    esp_log_level_set("I2S", esp_log_level_t::ESP_LOG_WARN); // Discard noisy I2S logs!
    // Y3, Y4, Y5, MPC, SPC, TCC
    adc1_channel_t solenoid_channels[6] = { ADC1_CHANNEL_0, ADC1_CHANNEL_3, ADC1_CHANNEL_7, ADC1_CHANNEL_6, ADC1_CHANNEL_4, ADC1_CHANNEL_5 };
    Solenoid* sol_order[6] = { sol_y3, sol_y4, sol_y5, sol_mpc, sol_spc, sol_tcc };
    uint8_t solenoid_id = 0;
    i2s_driver_install(I2S_NUM_0, &i2s_config, 0, nullptr);
    size_t bytes_read;
    #define SAMPLE_COUNT 3
    uint32_t samples[SAMPLE_COUNT];
    uint32_t sample_id;
    uint32_t avg;
    while(true) {
        i2s_set_adc_mode(ADC_UNIT_1, solenoid_channels[solenoid_id]);
        i2s_adc_enable(I2S_NUM_0);
        if (all_calibrated) {
            vTaskDelay(33 / portTICK_RATE_MS); // Approx 5 refreshes per second
        }
        sample_id = 0;
        avg = 0;
        while(sample_id < SAMPLE_COUNT) {
            bytes_read = 0;
            i2s_read(I2S_NUM_0, &dma_buffer, NUM_SAMPLES*BYTES_PER_SAMPLE, &bytes_read, portMAX_DELAY);
            uint32_t tmp = 0;
            for (int i = 0; i < BYTES_PER_SAMPLE*NUM_SAMPLES; i += BYTES_PER_SAMPLE) {
                tmp += (uint32_t)(dma_buffer[i] << 8 | dma_buffer[i+1]);
            }
            samples[sample_id] = tmp / NUM_SAMPLES;
            sample_id += 1;
        }
        for (uint8_t i = 0; i < SAMPLE_COUNT; i++) {
            avg += samples[i];
        }
        avg /= SAMPLE_COUNT;
        sol_order[solenoid_id]->__set_current_internal(avg);
        if (!all_calibrated) {
            sol_order[solenoid_id]->__set_vref(avg);
        }
        solenoid_id++;
        if (solenoid_id == 6) {
            solenoid_id = 0;
            all_calibrated = true;
        }
        // Configure ADC again and loop to read the next solenoid!
        i2s_adc_disable(I2S_NUM_0);
    }
}

bool init_all_solenoids()
{
    // Read calibration for ADC1
    esp_adc_cal_characterize(adc_unit_t::ADC_UNIT_1, adc_atten_t::ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 0, &adc1_cal);

    sol_y3 = new Solenoid("Y3", PIN_Y3_PWM, 1000, ledc_channel_t::LEDC_CHANNEL_0, ledc_timer_t::LEDC_TIMER_0);
    sol_y4 = new Solenoid("Y4", PIN_Y4_PWM, 1000, ledc_channel_t::LEDC_CHANNEL_1, ledc_timer_t::LEDC_TIMER_0);
    sol_y5 = new Solenoid("Y5", PIN_Y5_PWM, 1000, ledc_channel_t::LEDC_CHANNEL_2, ledc_timer_t::LEDC_TIMER_0);
    sol_mpc = new Solenoid("MPC", PIN_MPC_PWM, 1000, ledc_channel_t::LEDC_CHANNEL_3, ledc_timer_t::LEDC_TIMER_1);
    sol_spc = new Solenoid("SPC", PIN_SPC_PWM, 1000, ledc_channel_t::LEDC_CHANNEL_4, ledc_timer_t::LEDC_TIMER_1);
    sol_tcc = new Solenoid("TCC", PIN_TCC_PWM, 100, ledc_channel_t::LEDC_CHANNEL_5, ledc_timer_t::LEDC_TIMER_2);

    esp_err_t res = ledc_fade_func_install(0);
    if (res != ESP_OK) {
        ESP_LOGE("SOLENOID", "FATAL. Could not load insert LEDC fade function %s", esp_err_to_name(res));
        return false;
    }
    if (!(
        sol_tcc->init_ok() && 
        sol_mpc->init_ok() && 
        sol_spc->init_ok() && 
        sol_y3->init_ok() && 
        sol_y4->init_ok() && 
        sol_y5->init_ok())
    ) { // Init error, don't do anything else
        return false;
    }

    xTaskCreate(read_solenoids_i2s, "I2S-Reader", 8192, nullptr, 3, nullptr);
    
    while(!all_calibrated) {
        vTaskDelay(2);
    }
    ESP_LOGI("SOLENOID", 
        "Solenoid calibration readings: Y3: %d, Y4: %d, Y5: %d, MPC: %d, SPC: %d, TCC: %d",
            sol_y3->get_vref(),
            sol_y4->get_vref(),
            sol_y5->get_vref(),
            sol_mpc->get_vref(),
            sol_spc->get_vref(),
            sol_tcc->get_vref()
    );

#define SOL_THRESHOLD_ADC 500

    if (sol_y3->get_vref() > 500) {
        ESP_LOGE("SOLENOID", "SOLENOID Y3 is drawing too much current at idle! (ADC Reading: %d, threshold: %d). Short circuit!?", sol_y3->get_vref(), SOL_THRESHOLD_ADC);
        return false;
    }
    if (sol_y4->get_vref() > 500) {
        ESP_LOGE("SOLENOID", "SOLENOID Y4 is drawing too much current at idle! (ADC Reading: %d, threshold: %d). Short circuit!?", sol_y4->get_vref(), SOL_THRESHOLD_ADC);
        return false;
    }
    if (sol_y5->get_vref() > 500) {
        ESP_LOGE("SOLENOID", "SOLENOID Y5 is drawing too much current at idle! (ADC Reading: %d, threshold: %d). Short circuit!?", sol_y5->get_vref(), SOL_THRESHOLD_ADC);
        return false;
    }
    if (sol_mpc->get_vref() > 500) {
        ESP_LOGE("SOLENOID", "SOLENOID MPC is drawing too much current at idle! (ADC Reading: %d, threshold: %d). Short circuit!?", sol_mpc->get_vref(), SOL_THRESHOLD_ADC);
        return false;
    }
    if (sol_spc->get_vref() > 500) {
        ESP_LOGE("SOLENOID", "SOLENOID SPC is drawing too much current at idle! (ADC Reading: %d, threshold: %d). Short circuit!?", sol_spc->get_vref(), SOL_THRESHOLD_ADC);
        return false;
    }
    if (sol_tcc->get_vref() > 500) {
        ESP_LOGE("SOLENOID", "SOLENOID TCC is drawing too much current at idle! (ADC Reading: %d, threshold: %d). Short circuit!?", sol_tcc->get_vref(), SOL_THRESHOLD_ADC);
        return false;
    }
    return true;
}