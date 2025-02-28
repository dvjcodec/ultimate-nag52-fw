
/**
* AUTOGENERATED BY convert.py
* DO NOT EDIT THIS FILE!
*
* IF MODIFICATIONS NEED TO BE MADE, MODIFY can_data.txt!
*
* CAN Defintiion for ECU 'GS'
*/

#ifdef EGS52_MODE

#ifndef __ECU_GS_H_
#define __ECU_GS_H_

#include <stdint.h>
    
#define GS_218_CAN_ID 0x0218
#define GS_338_CAN_ID 0x0338
#define GS_418_CAN_ID 0x0418
#define GS_CUSTOM_558_CAN_ID 0x0558

/** Goal Gang */
enum class GS_218h_GZC {
	G_N = 0, // Destination "N"
	G_D1 = 1, // Destination "1"
	G_D2 = 2, // Destination "2"
	G_D3 = 3, // Destination "3"
	G_D4 = 4, // Destination "4"
	G_D5 = 5, // Destination "5"
	G_D6 = 6, // Destination "6"
	G_D7 = 7, // Destination "7"
	G_D_CVT = 8, // Destination "infinitely forward
	G_R_CVT = 9, // Goal "infinitely reverse"
	G_R3 = 10, // Destination "R3"
	G_R = 11, // Destination "R"
	G_R2 = 12, // Destination "R2"
	G_P = 13, // Destination "P"
	G_ABBRUCH = 14, // circuit break
	G_SNV = 15, // signal not available
};

/** actual gear */
enum class GS_218h_GIC {
	G_N = 0, // Actual rang "N"
	G_D1 = 1, // actual gear "1"
	G_D2 = 2, // actual gear "2"
	G_D3 = 3, // Actual Rang "3"
	G_D4 = 4, // Actual rang "4"
	G_D5 = 5, // Actual rang "5"
	G_D6 = 6, // actual gear "6"
	G_D7 = 7, // Actual rang "7"
	G_D_CVT = 8, // Actual ranging "infinitely forward
	G_R_CVT = 9, // Actual "infinitely reverse"
	G_R3 = 10, // Actual ranging "R3"
	G_R = 11, // Actual rang "R"
	G_R2 = 12, // Actual rang "R2"
	G_P = 13, // Actual rang "P"
	G_KRAFTFREI = 14, // power-free
	G_SNV = 15, // signal not available
};

/** Driving program for AAD */
enum class GS_218h_FPC_AAD {
	SPORT = 0, // Sports (standard)
	KOMFORT = 1, // comfort
	UNKNOWN = 2, // not defined
	SNV = 3, // signal not available
};

/** Status Error Check */
enum class GS_218h_FEHLPRF_ST {
	WAIT = 0, // error check not completely run through
	OK = 1, // Completely traject error test, result i. O.
	ERROR = 2, // Error detected, enter current environmental data
	UNKNOWN = 3, // not defined
};

/** Driving program */
enum class GS_418h_FPC {
	C_MGFB_WT = 2, // "C", message "Activate gearbox, parking brake!" warning
	C_MGSNN = 3, // "C", message "Gearbox, shift lever according to N!"
	C_MGBB = 4, // "C", message "Activate gear, brake!"
	C_MGGEA = 6, // "C", message "Request gearbox, gear again!"
	C_MGZSN = 7, // "C", Message "Transmission, Insert to Start N!"
	A_MGFB_WT = 10, // "A", message "Activate gearbox, parking brake!" warning
	A_MGSNN = 11, // "A", message "Gear, shift lever to N!"
	A_MGBB = 12, // "A", message "Activate gearbox, brake!"
	A_MGGEA = 14, // "A", message "Request transmission, gear again!"
	A_MGZSN = 15, // "A", Message "Transmission, Insert to Start N!"
	S_MGFB_WT = 18, // "S", message "Activate gearbox, parking brake!" warning
	S_MGSNN = 19, // "S", message "Gear, shift lever after N!"
	S_MGBB = 20, // "S", message "Activate gearbox, brake!"
	S_MGGEA = 22, // "S", message "Request transmission, gear again!"
	S_MGZSN = 23, // "S", message "Transmission, insert it to start n!"
	HOCH = 24, // switching recommendation "Upsheet"
	RUNTER = 25, // Shift recommendation "Down"
	BLANK = 32, // "" (blank)
	BLANK_MGN = 64, // "" (blank), message "Enter transmission, n!"
	A = 65, // "A"
	C = 67, // "C"
	F = 70, // Error Mark "F"
	M = 77, // "M"
	S = 83, // "S"
	W = 87, // "W"
	_ = 95, // "_" (Underscore)
	BLANK_MGW = 96, // "" (blank), message "Check out gear, workshop!"
	A_MGN = 97, // "A", message "Insert transmission, n!"
	C_MGN = 99, // "C", message "Insert transmission, n!"
	M_MGN = 109, // "M", message "Transmission, n insert!"
	S_MGN = 115, // "S", message "Insert transmission, n!"
	W_MGN = 119, // "W", message "Transmission, n insert!"
	__MGN = 127, // "_" (undercore), message "Transmission, n insert!"
	A_MGW = 129, // "A", message "Check out gear, workshop!"
	C_MGW = 131, // "C", message "Check out gear, workshop!"
	F_MGW = 134, // Error Mark "F", Message "Check Gear, Workshop!"
	M_MGW = 141, // "M", message "Check out transmission, workshop!"
	S_MGW = 147, // "S", message "Check out gear, workshop!"
	W_MGW = 151, // "W", message "Get gear, workshop visit!"
	__MGW = 159, // "_" (Underscore), message "Check out gear, workshop!"
	SNV = 255, // passive value
};

/** Gear mechanics variant */
enum class GS_418h_MECH {
	GROSS = 0, // Nag, big gear
	KLEIN = 1, // NAG, small gearbox
	GROSS2 = 2, // NAG2, big gear
	KLEIN2 = 3, // NAG2, small gearbox
};

/** target gear */
enum class GS_418h_GZC {
	G_N = 0, // Destination "N"
	G_D1 = 1, // Destination "1"
	G_D2 = 2, // Destination "2"
	G_D3 = 3, // Destination "3"
	G_D4 = 4, // Destination "4"
	G_D5 = 5, // Destination "5"
	G_D6 = 6, // Destination "6"
	G_D7 = 7, // Destination "7"
	G_D_CVT = 8, // Destination "infinitely forward
	G_R_CVT = 9, // Goal "infinitely reverse"
	G_R3 = 10, // Destination "R3"
	G_R = 11, // Destination "R"
	G_R2 = 12, // Destination "R2"
	G_P = 13, // Destination "P"
	G_ABBRUCH = 14, // circuit break
	G_SNV = 15, // signal not available
};

/** actual gear */
enum class GS_418h_GIC {
	G_N = 0, // Actual rang "N"
	G_D1 = 1, // actual gear "1"
	G_D2 = 2, // actual gear "2"
	G_D3 = 3, // Actual Rang "3"
	G_D4 = 4, // Actual rang "4"
	G_D5 = 5, // Actual rang "5"
	G_D6 = 6, // actual gear "6"
	G_D7 = 7, // Actual rang "7"
	G_D_CVT = 8, // Actual ranging "infinitely forward
	G_R_CVT = 9, // Actual "infinitely reverse"
	G_R3 = 10, // Actual ranging "R3"
	G_R = 11, // Actual rang "R"
	G_R2 = 12, // Actual rang "R2"
	G_P = 13, // Actual rang "P"
	G_KRAFTFREI = 14, // power-free
	G_SNV = 15, // signal not available
};

/** gear selector lever position (NAG, KSG, CVT) */
enum class GS_418h_WHST {
	P = 0, // Gear selector lever in position "P"
	R = 1, // gear selector lever in position "R"
	N = 2, // Gear selector lever in position "N"
	D = 4, // gear selector lever in position "D"
	SNV = 7, // signal not available
};



typedef union {
	uint64_t raw;
	uint8_t bytes[8];

	/** Gets CAN ID of GS_218 */
	uint32_t get_canid(){ return GS_218_CAN_ID; }
    /** Sets Motor moments Toggle 40ms + -10 */
    void set_MTGL_EGS(bool value){ raw = (raw & 0x7fffffffffffffff) | ((uint64_t)value & 0x1) << 63; }

    /** Gets Motor moments Toggle 40ms + -10 */
    bool get_MTGL_EGS() const { return (bool)(raw >> 63 & 0x1); }
        
    /** Sets Engine torque request min */
    void set_MMIN_EGS(bool value){ raw = (raw & 0xbfffffffffffffff) | ((uint64_t)value & 0x1) << 62; }

    /** Gets Engine torque request min */
    bool get_MMIN_EGS() const { return (bool)(raw >> 62 & 0x1); }
        
    /** Sets Engine torque request max */
    void set_MMAX_EGS(bool value){ raw = (raw & 0xdfffffffffffffff) | ((uint64_t)value & 0x1) << 61; }

    /** Gets Engine torque request max */
    bool get_MMAX_EGS() const { return (bool)(raw >> 61 & 0x1); }
        
    /** Sets Ford. Engine torque. Conversion formula (To raw from real): y=(x-0.0)/1.00 */
    void set_M_EGS(uint16_t value){ raw = (raw & 0xe000ffffffffffff) | ((uint64_t)value & 0x1fff) << 48; }

    /** Gets Ford. Engine torque. Conversion formula (To real from raw): y=(1.00x)+0.0 */
    uint16_t get_M_EGS() const { return (uint16_t)(raw >> 48 & 0x1fff); }
        
    /** Sets Goal Gang */
    void set_GZC(GS_218h_GZC value){ raw = (raw & 0xffff0fffffffffff) | ((uint64_t)value & 0xf) << 44; }

    /** Gets Goal Gang */
    GS_218h_GZC get_GZC() const { return (GS_218h_GZC)(raw >> 44 & 0xf); }
        
    /** Sets actual gear */
    void set_GIC(GS_218h_GIC value){ raw = (raw & 0xfffff0ffffffffff) | ((uint64_t)value & 0xf) << 40; }

    /** Gets actual gear */
    GS_218h_GIC get_GIC() const { return (GS_218h_GIC)(raw >> 40 & 0xf); }
        
    /** Sets Best. (Transducer overbridge.-) clutch "slip" */
    void set_K_S_B(bool value){ raw = (raw & 0xffffff7fffffffff) | ((uint64_t)value & 0x1) << 39; }

    /** Gets Best. (Transducer overbridge.-) clutch "slip" */
    bool get_K_S_B() const { return (bool)(raw >> 39 & 0x1); }
        
    /** Sets Best. (Transducer overbridders.-) clutch "open" */
    void set_K_O_B(bool value){ raw = (raw & 0xffffffbfffffffff) | ((uint64_t)value & 0x1) << 38; }

    /** Gets Best. (Transducer overbridders.-) clutch "open" */
    bool get_K_O_B() const { return (bool)(raw >> 38 & 0x1); }
        
    /** Sets Best. (Transducer overbridge.-) clutch "closed" */
    void set_K_G_B(bool value){ raw = (raw & 0xffffffdfffffffff) | ((uint64_t)value & 0x1) << 37; }

    /** Gets Best. (Transducer overbridge.-) clutch "closed" */
    bool get_K_G_B() const { return (bool)(raw >> 37 & 0x1); }
        
    /** Sets terrain */
    void set_G_G(bool value){ raw = (raw & 0xffffffefffffffff) | ((uint64_t)value & 0x1) << 36; }

    /** Gets terrain */
    bool get_G_G() const { return (bool)(raw >> 36 & 0x1); }
        
    /** Sets Basic switch program O.K. */
    void set_GSP_OK(bool value){ raw = (raw & 0xfffffff7ffffffff) | ((uint64_t)value & 0x1) << 35; }

    /** Gets Basic switch program O.K. */
    bool get_GSP_OK() const { return (bool)(raw >> 35 & 0x1); }
        
    /** Sets driving resistance high */
    void set_FW_HOCH(bool value){ raw = (raw & 0xfffffffbffffffff) | ((uint64_t)value & 0x1) << 34; }

    /** Gets driving resistance high */
    bool get_FW_HOCH() const { return (bool)(raw >> 34 & 0x1); }
        
    /** Sets circuit */
    void set_SCHALT(bool value){ raw = (raw & 0xfffffffdffffffff) | ((uint64_t)value & 0x1) << 33; }

    /** Gets circuit */
    bool get_SCHALT() const { return (bool)(raw >> 33 & 0x1); }
        
    /** Sets hand switching mode */
    void set_HSM(bool value){ raw = (raw & 0xfffffffeffffffff) | ((uint64_t)value & 0x1) << 32; }

    /** Gets hand switching mode */
    bool get_HSM() const { return (bool)(raw >> 32 & 0x1); }
        
    /** Sets gear ok */
    void set_GET_OK(bool value){ raw = (raw & 0xffffffff7fffffff) | ((uint64_t)value & 0x1) << 31; }

    /** Gets gear ok */
    bool get_GET_OK() const { return (bool)(raw >> 31 & 0x1); }
        
    /** Sets Ball start */
    void set_KS(bool value){ raw = (raw & 0xffffffffbfffffff) | ((uint64_t)value & 0x1) << 30; }

    /** Gets Ball start */
    bool get_KS() const { return (bool)(raw >> 30 & 0x1); }
        
    /** Sets reasonable release */
    void set_ALF(bool value){ raw = (raw & 0xffffffffdfffffff) | ((uint64_t)value & 0x1) << 29; }

    /** Gets reasonable release */
    bool get_ALF() const { return (bool)(raw >> 29 & 0x1); }
        
    /** Sets GS in the emergency */
    void set_GS_NOTL(bool value){ raw = (raw & 0xffffffffefffffff) | ((uint64_t)value & 0x1) << 28; }

    /** Gets GS in the emergency */
    bool get_GS_NOTL() const { return (bool)(raw >> 28 & 0x1); }
        
    /** Sets Overtemperature gearbox */
    void set_UEHITZ_GET(bool value){ raw = (raw & 0xfffffffff7ffffff) | ((uint64_t)value & 0x1) << 27; }

    /** Gets Overtemperature gearbox */
    bool get_UEHITZ_GET() const { return (bool)(raw >> 27 & 0x1); }
        
    /** Sets Kickdown */
    void set_KD(bool value){ raw = (raw & 0xfffffffffbffffff) | ((uint64_t)value & 0x1) << 26; }

    /** Gets Kickdown */
    bool get_KD() const { return (bool)(raw >> 26 & 0x1); }
        
    /** Sets Driving program for AAD */
    void set_FPC_AAD(GS_218h_FPC_AAD value){ raw = (raw & 0xfffffffffcffffff) | ((uint64_t)value & 0x3) << 24; }

    /** Gets Driving program for AAD */
    GS_218h_FPC_AAD get_FPC_AAD() const { return (GS_218h_FPC_AAD)(raw >> 24 & 0x3); }
        
    /** Sets Engine torque Request Parity (just parity) */
    void set_MPAR_EGS(bool value){ raw = (raw & 0xffffffffff7fffff) | ((uint64_t)value & 0x1) << 23; }

    /** Gets Engine torque Request Parity (just parity) */
    bool get_MPAR_EGS() const { return (bool)(raw >> 23 & 0x1); }
        
    /** Sets engagement mode / drive torque control */
    void set_DYN1_EGS(bool value){ raw = (raw & 0xffffffffffbfffff) | ((uint64_t)value & 0x1) << 22; }

    /** Gets engagement mode / drive torque control */
    bool get_DYN1_EGS() const { return (bool)(raw >> 22 & 0x1); }
        
    /** Sets engagement mode / drive torque control */
    void set_DYN0_AMR_EGS(bool value){ raw = (raw & 0xffffffffffdfffff) | ((uint64_t)value & 0x1) << 21; }

    /** Gets engagement mode / drive torque control */
    bool get_DYN0_AMR_EGS() const { return (bool)(raw >> 21 & 0x1); }
        
    /** Sets Convertible bridging clutch load-free */
    void set_K_LSTFR(bool value){ raw = (raw & 0xfffffffffffbffff) | ((uint64_t)value & 0x1) << 18; }

    /** Gets Convertible bridging clutch load-free */
    bool get_K_LSTFR() const { return (bool)(raw >> 18 & 0x1); }
        
    /** Sets MOT_NAUS-ConfirmMbit */
    void set_MOT_NAUS_CNF(bool value){ raw = (raw & 0xfffffffffffdffff) | ((uint64_t)value & 0x1) << 17; }

    /** Gets MOT_NAUS-ConfirmMbit */
    bool get_MOT_NAUS_CNF() const { return (bool)(raw >> 17 & 0x1); }
        
    /** Sets Engine Emergency Switch Off */
    void set_MOT_NAUS(bool value){ raw = (raw & 0xfffffffffffeffff) | ((uint64_t)value & 0x1) << 16; }

    /** Gets Engine Emergency Switch Off */
    bool get_MOT_NAUS() const { return (bool)(raw >> 16 & 0x1); }
        
    /** Sets Kriech torque (FFH at EGS, CVT) or Calid / CVN. Conversion formula (To raw from real): y=(x-0.0)/1.00 */
    void set_MKRIECH(uint8_t value){ raw = (raw & 0xffffffffffff00ff) | ((uint64_t)value & 0xff) << 8; }

    /** Gets Kriech torque (FFH at EGS, CVT) or Calid / CVN. Conversion formula (To real from raw): y=(1.00x)+0.0 */
    uint8_t get_MKRIECH() const { return (uint8_t)(raw >> 8 & 0xff); }
        
    /** Sets Status Error Check */
    void set_FEHLPRF_ST(GS_218h_FEHLPRF_ST value){ raw = (raw & 0xffffffffffffff3f) | ((uint64_t)value & 0x3) << 6; }

    /** Gets Status Error Check */
    GS_218h_FEHLPRF_ST get_FEHLPRF_ST() const { return (GS_218h_FEHLPRF_ST)(raw >> 6 & 0x3); }
        
    /** Sets CALID / CVN transmission active */
    void set_CALID_CVN_AKT(bool value){ raw = (raw & 0xffffffffffffffdf) | ((uint64_t)value & 0x1) << 5; }

    /** Gets CALID / CVN transmission active */
    bool get_CALID_CVN_AKT() const { return (bool)(raw >> 5 & 0x1); }
        
    /** Sets error number or counter for calid / CVN transmission. Conversion formula (To raw from real): y=(x-0.0)/1.00 */
    void set_FEHLER(uint8_t value){ raw = (raw & 0xffffffffffffffe0) | ((uint64_t)value & 0x1f) << 0; }

    /** Gets error number or counter for calid / CVN transmission. Conversion formula (To real from raw): y=(1.00x)+0.0 */
    uint8_t get_FEHLER() const { return (uint8_t)(raw >> 0 & 0x1f); }
        
} GS_218;



typedef union {
	uint64_t raw;
	uint8_t bytes[8];

	/** Gets CAN ID of GS_338 */
	uint32_t get_canid(){ return GS_338_CAN_ID; }
    /** Sets Transmission output speed (only 463/461, other FFFFH). Conversion formula (To raw from real): y=(x-0.0)/1.00 */
    void set_NAB(uint16_t value){ raw = (raw & 0x0000ffffffffffff) | ((uint64_t)value & 0xffff) << 48; }

    /** Gets Transmission output speed (only 463/461, other FFFFH). Conversion formula (To real from raw): y=(1.00x)+0.0 */
    uint16_t get_NAB() const { return (uint16_t)(raw >> 48 & 0xffff); }
        
    /** Sets Turbine speed (EGS52-NAG, VGS-NAG2). Conversion formula (To raw from real): y=(x-0.0)/1.00 */
    void set_NTURBINE(uint16_t value){ raw = (raw & 0xffffffffffff0000) | ((uint64_t)value & 0xffff) << 0; }

    /** Gets Turbine speed (EGS52-NAG, VGS-NAG2). Conversion formula (To real from raw): y=(1.00x)+0.0 */
    uint16_t get_NTURBINE() const { return (uint16_t)(raw >> 0 & 0xffff); }
        
} GS_338;



typedef union {
	uint64_t raw;
	uint8_t bytes[8];

	/** Gets CAN ID of GS_418 */
	uint32_t get_canid(){ return GS_418_CAN_ID; }
    /** Sets drive */
    void set_FSC(char value){ raw = (raw & 0x00ffffffffffffff) | ((uint64_t)value & 0xff) << 56; }

    /** Gets drive */
    char get_FSC() const { return (char)(raw >> 56 & 0xff); }
        
    /** Sets Driving program */
    void set_FPC(GS_418h_FPC value){ raw = (raw & 0xff00ffffffffffff) | ((uint64_t)value & 0xff) << 48; }

    /** Gets Driving program */
    GS_418h_FPC get_FPC() const { return (GS_418h_FPC)(raw >> 48 & 0xff); }
        
    /** Sets Gear oil temperature. Conversion formula (To raw from real): y=(x-0.0)/1.00 */
    void set_T_GET(uint8_t value){ raw = (raw & 0xffff00ffffffffff) | ((uint64_t)value & 0xff) << 40; }

    /** Gets Gear oil temperature. Conversion formula (To real from raw): y=(1.00x)+0.0 */
    uint8_t get_T_GET() const { return (uint8_t)(raw >> 40 & 0xff); }
        
    /** Sets four-wheel drive */
    void set_ALLRAD(bool value){ raw = (raw & 0xffffff7fffffffff) | ((uint64_t)value & 0x1) << 39; }

    /** Gets four-wheel drive */
    bool get_ALLRAD() const { return (bool)(raw >> 39 & 0x1); }
        
    /** Sets Front drive [1], rear drive [0] */
    void set_FRONT(bool value){ raw = (raw & 0xffffffbfffffffff) | ((uint64_t)value & 0x1) << 38; }

    /** Gets Front drive [1], rear drive [0] */
    bool get_FRONT() const { return (bool)(raw >> 38 & 0x1); }
        
    /** Sets circuit */
    void set_SCHALT(bool value){ raw = (raw & 0xffffffdfffffffff) | ((uint64_t)value & 0x1) << 37; }

    /** Gets circuit */
    bool get_SCHALT() const { return (bool)(raw >> 37 & 0x1); }
        
    /** Sets Stepless transmission [1], stage gear [0] */
    void set_CVT(bool value){ raw = (raw & 0xffffffefffffffff) | ((uint64_t)value & 0x1) << 36; }

    /** Gets Stepless transmission [1], stage gear [0] */
    bool get_CVT() const { return (bool)(raw >> 36 & 0x1); }
        
    /** Sets Gear mechanics variant */
    void set_MECH(GS_418h_MECH value){ raw = (raw & 0xfffffff3ffffffff) | ((uint64_t)value & 0x3) << 34; }

    /** Gets Gear mechanics variant */
    GS_418h_MECH get_MECH() const { return (GS_418h_MECH)(raw >> 34 & 0x3); }
        
    /** Sets Create brake when switching on */
    void set_ESV_BRE(bool value){ raw = (raw & 0xfffffffdffffffff) | ((uint64_t)value & 0x1) << 33; }

    /** Gets Create brake when switching on */
    bool get_ESV_BRE() const { return (bool)(raw >> 33 & 0x1); }
        
    /** Sets Kickdown */
    void set_KD(bool value){ raw = (raw & 0xfffffffeffffffff) | ((uint64_t)value & 0x1) << 32; }

    /** Gets Kickdown */
    bool get_KD() const { return (bool)(raw >> 32 & 0x1); }
        
    /** Sets target gear */
    void set_GZC(GS_418h_GZC value){ raw = (raw & 0xffffffff0fffffff) | ((uint64_t)value & 0xf) << 28; }

    /** Gets target gear */
    GS_418h_GZC get_GZC() const { return (GS_418h_GZC)(raw >> 28 & 0xf); }
        
    /** Sets actual gear */
    void set_GIC(GS_418h_GIC value){ raw = (raw & 0xfffffffff0ffffff) | ((uint64_t)value & 0xf) << 24; }

    /** Gets actual gear */
    GS_418h_GIC get_GIC() const { return (GS_418h_GIC)(raw >> 24 & 0xf); }
        
    /** Sets Loss moment (FFH at KSG). Conversion formula (To raw from real): y=(x-0.0)/1.00 */
    void set_M_VERL(uint8_t value){ raw = (raw & 0xffffffffff00ffff) | ((uint64_t)value & 0xff) << 16; }

    /** Gets Loss moment (FFH at KSG). Conversion formula (To real from raw): y=(1.00x)+0.0 */
    uint8_t get_M_VERL() const { return (uint8_t)(raw >> 16 & 0xff); }
        
    /** Sets Factor wheel torque parity (straight parity) */
    void set_FMRADPAR(bool value){ raw = (raw & 0xffffffffffff7fff) | ((uint64_t)value & 0x1) << 15; }

    /** Gets Factor wheel torque parity (straight parity) */
    bool get_FMRADPAR() const { return (bool)(raw >> 15 & 0x1); }
        
    /** Sets Factor wheel torque Toggle 40ms + -10 */
    void set_FMRADTGL(bool value){ raw = (raw & 0xffffffffffffbfff) | ((uint64_t)value & 0x1) << 14; }

    /** Gets Factor wheel torque Toggle 40ms + -10 */
    bool get_FMRADTGL() const { return (bool)(raw >> 14 & 0x1); }
        
    /** Sets gear selector lever position (NAG, KSG, CVT) */
    void set_WHST(GS_418h_WHST value){ raw = (raw & 0xffffffffffffc7ff) | ((uint64_t)value & 0x7) << 11; }

    /** Gets gear selector lever position (NAG, KSG, CVT) */
    GS_418h_WHST get_WHST() const { return (GS_418h_WHST)(raw >> 11 & 0x7); }
        
    /** Sets Factor wheel torque (7ffh at KSG). Conversion formula (To raw from real): y=(x-0.0)/1.00 */
    void set_FMRAD(uint16_t value){ raw = (raw & 0xfffffffffffff800) | ((uint64_t)value & 0x7ff) << 0; }

    /** Gets Factor wheel torque (7ffh at KSG). Conversion formula (To real from raw): y=(1.00x)+0.0 */
    uint16_t get_FMRAD() const { return (uint16_t)(raw >> 0 & 0x7ff); }
        
} GS_418;



typedef union {
	uint64_t raw;
	uint8_t bytes[8];

	/** Gets CAN ID of GS_CUSTOM_558 */
	uint32_t get_canid(){ return GS_CUSTOM_558_CAN_ID; }
    /** Sets Duty cycle of modulating pressure solenoid. Conversion formula (To raw from real): y=(x-0.0)/1.00 */
    void set_MPC_DUTY(uint8_t value){ raw = (raw & 0x00ffffffffffffff) | ((uint64_t)value & 0xff) << 56; }

    /** Gets Duty cycle of modulating pressure solenoid. Conversion formula (To real from raw): y=(1.00x)+0.0 */
    uint8_t get_MPC_DUTY() const { return (uint8_t)(raw >> 56 & 0xff); }
        
    /** Sets Duty cycle of shift pressure solenoid. Conversion formula (To raw from real): y=(x-0.0)/1.00 */
    void set_SPC_DUTY(uint8_t value){ raw = (raw & 0xff00ffffffffffff) | ((uint64_t)value & 0xff) << 48; }

    /** Gets Duty cycle of shift pressure solenoid. Conversion formula (To real from raw): y=(1.00x)+0.0 */
    uint8_t get_SPC_DUTY() const { return (uint8_t)(raw >> 48 & 0xff); }
        
    /** Sets Duty cycle of torque convert solenoid. Conversion formula (To raw from real): y=(x-0.0)/1.00 */
    void set_TCC_DUTY(uint8_t value){ raw = (raw & 0xffff00ffffffffff) | ((uint64_t)value & 0xff) << 40; }

    /** Gets Duty cycle of torque convert solenoid. Conversion formula (To real from raw): y=(1.00x)+0.0 */
    uint8_t get_TCC_DUTY() const { return (uint8_t)(raw >> 40 & 0xff); }
        
    /** Sets Desired RPM slip of torque converter clutch. Conversion formula (To raw from real): y=(x-0.0)/1.00 (Unit: rpm) */
    void set_TCC_SLIP(uint16_t value){ raw = (raw & 0xffffffff0000ffff) | ((uint64_t)value & 0xffff) << 16; }

    /** Gets Desired RPM slip of torque converter clutch. Conversion formula (To real from raw): y=(1.00x)+0.0 (Unit: rpm) */
    uint16_t get_TCC_SLIP() const { return (uint16_t)(raw >> 16 & 0xffff); }
        
    /** Sets AI certainty of upshift. Conversion formula (To raw from real): y=(x-0.0)/1.00 (Unit: %) */
    void set_AI_UP(uint8_t value){ raw = (raw & 0xffffffffffff00ff) | ((uint64_t)value & 0xff) << 8; }

    /** Gets AI certainty of upshift. Conversion formula (To real from raw): y=(1.00x)+0.0 (Unit: %) */
    uint8_t get_AI_UP() const { return (uint8_t)(raw >> 8 & 0xff); }
        
    /** Sets AI certainty of downshift. Conversion formula (To raw from real): y=(x-0.0)/1.00 (Unit: %) */
    void set_AI_DN(uint8_t value){ raw = (raw & 0xffffffffffff00ff) | ((uint64_t)value & 0xff) << 8; }

    /** Gets AI certainty of downshift. Conversion formula (To real from raw): y=(1.00x)+0.0 (Unit: %) */
    uint8_t get_AI_DN() const { return (uint8_t)(raw >> 8 & 0xff); }
        
} GS_CUSTOM_558;



class ECU_GS {
	public:
        /**
         * @brief Imports the CAN frame given the CAN ID, CAN Contents, and current timestamp
         *
         * Returns true if the frame was imported successfully, and false if import failed (Due to non-matching CAN ID).
         *
         * NOTE: The endianness of the value cannot be guaranteed. It is up to the caller to correct the byte order!
         */
        bool import_frames(uint64_t value, uint32_t can_id, uint64_t timestamp_now) {
            switch(can_id) {
                case GS_218_CAN_ID:
                    LAST_FRAME_TIMES[0] = timestamp_now;
                    FRAME_DATA[0] = value;
                    return true;
                case GS_338_CAN_ID:
                    LAST_FRAME_TIMES[1] = timestamp_now;
                    FRAME_DATA[1] = value;
                    return true;
                case GS_418_CAN_ID:
                    LAST_FRAME_TIMES[2] = timestamp_now;
                    FRAME_DATA[2] = value;
                    return true;
                case GS_CUSTOM_558_CAN_ID:
                    LAST_FRAME_TIMES[3] = timestamp_now;
                    FRAME_DATA[3] = value;
                    return true;
                default:
                    return false;
            }
        }
        
        /** Sets data in pointer to GS_218
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_GS_218(uint64_t now, uint64_t max_expire_time, GS_218* dest) const {
            if (LAST_FRAME_TIMES[0] == 0 || dest == nullptr) { // CAN Frame has not been seen on bus yet / NULL pointer
                return false;
            } else if (now - LAST_FRAME_TIMES[0] > max_expire_time) { // CAN Frame has not refreshed in valid interval
                return false;
            } else { // CAN Frame is valid! return it
                dest->raw = FRAME_DATA[0];
                return true;
            }
        }
            
        /** Sets data in pointer to GS_338
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_GS_338(uint64_t now, uint64_t max_expire_time, GS_338* dest) const {
            if (LAST_FRAME_TIMES[1] == 0 || dest == nullptr) { // CAN Frame has not been seen on bus yet / NULL pointer
                return false;
            } else if (now - LAST_FRAME_TIMES[1] > max_expire_time) { // CAN Frame has not refreshed in valid interval
                return false;
            } else { // CAN Frame is valid! return it
                dest->raw = FRAME_DATA[1];
                return true;
            }
        }
            
        /** Sets data in pointer to GS_418
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_GS_418(uint64_t now, uint64_t max_expire_time, GS_418* dest) const {
            if (LAST_FRAME_TIMES[2] == 0 || dest == nullptr) { // CAN Frame has not been seen on bus yet / NULL pointer
                return false;
            } else if (now - LAST_FRAME_TIMES[2] > max_expire_time) { // CAN Frame has not refreshed in valid interval
                return false;
            } else { // CAN Frame is valid! return it
                dest->raw = FRAME_DATA[2];
                return true;
            }
        }
            
        /** Sets data in pointer to GS_CUSTOM_558
          * 
          * If this function returns false, then the CAN Frame is invalid or has not been seen
          * on the CANBUS network yet. Meaning it's data cannot be used.
          *
          * If the function returns true, then the pointer to 'dest' has been updated with the new CAN data
          */
        bool get_GS_CUSTOM_558(uint64_t now, uint64_t max_expire_time, GS_CUSTOM_558* dest) const {
            if (LAST_FRAME_TIMES[3] == 0 || dest == nullptr) { // CAN Frame has not been seen on bus yet / NULL pointer
                return false;
            } else if (now - LAST_FRAME_TIMES[3] > max_expire_time) { // CAN Frame has not refreshed in valid interval
                return false;
            } else { // CAN Frame is valid! return it
                dest->raw = FRAME_DATA[3];
                return true;
            }
        }
            
	private:
		uint64_t FRAME_DATA[4];
		uint64_t LAST_FRAME_TIMES[4];
};
#endif // __ECU_GS_H_

#endif // EGS52_MODE