#ifndef CAN_ECUS_H
#define CAN_ECUS_H

#include <eforce/can.h>

#ifdef __cplusplus
extern "C" {
#endif

enum { ECUA_Status_id = 0x090 };
enum { ECUA_Status_timeout = 500 };
enum { ECUA_Limits_id = 0x191 };
enum { ECUA_Limits_timeout = 500 };
enum { ECUA_ACPMeas_id = 0x392 };
enum { ECUA_ACPMeas_timeout = 100 };
enum { ECUA_Estimation_id = 0x394 };
enum { ECUA_Estimation_timeout = 500 };
enum { ECUA_AMSOverall_id = 0x49A };
enum { ECUB_Status_id = 0x0A0 };
enum { ECUB_Status_timeout = 1000 };
enum { ECUB_Cooling_id = 0x4A4 };
enum { ECUB_TEMPSuspR_id = 0x4A8 };
enum { ECUB_TEMPAux_id = 0x4AA };
enum { ECUF_Status_id = 0x0C0 };
enum { ECUF_Status_timeout = 1000 };
enum { ECUF_STW_id = 0x1C1 };
enum { ECUF_STW_timeout = 50 };
enum { ECUF_TEMPSuspF_id = 0x4C3 };
enum { ECUF_REQCalibSTW_id = 0x4CD };
enum { ECUP_Status_id = 0x040 };
enum { ECUP_Status_timeout = 500 };
enum { ECUP_Pedals_id = 0x141 };
enum { ECUP_Pedals_timeout = 50 };
enum { ECUP_Pressure_id = 0x142 };
enum { ECUP_REQCalibPedal_id = 0x44D };
enum { ECUP_DiagPos_id = 0x54E };
enum { ECUP_DiagPos_timeout = 250 };
enum { ECUS_Status_id = 0x0B0 };
enum { ECUS_Status_timeout = 500 };
enum { IMU_Status_id = 0x060 };
enum { IMU_Status_timeout = 1000 };
enum { MCR_GeneralReport_id = 0x110 };
enum { MCR_ThermalMeasuresA_id = 0x313 };
enum { MCR_ThermalMeasuresB_id = 0x314 };
enum { VDCU_Status_id = 0x050 };
enum { VDCU_Status_timeout = 500 };
enum { VDCU_Controller_id = 0x351 };
enum { VDCU_Controller_timeout = 50 };
enum { VDCU_Body_id = 0x352 };
enum { VDCU_Body_timeout = 50 };
enum { VDCU_WheelFz_id = 0x355 };
enum { VDCU_WheelFz_timeout = 50 };
enum { VDCU_Param_id = 0x358 };
enum { VDCU_Param_timeout = 100 };
enum { VDCU_Param_ACK_id = 0x359 };
enum { VDCU_Param_ACK_timeout = 20 };
enum { VDCU_REQCalibDis_id = 0x45D };
enum { VDCU_SOC_id = 0x55B };
enum { VDCU_SOC_timeout = 50 };

enum ECUP_CAL_PedalIndex {
    /* None */
    ECUP_CAL_PedalIndex_None = 0,
    /* Minimum apps position */
    ECUP_CAL_PedalIndex_AppsMin = 1,
    /* Maximum apps position */
    ECUP_CAL_PedalIndex_AppsMax = 2,
    /* Minimum brake position */
    ECUP_CAL_PedalIndex_BrakeMin = 3,
    /* Maximum brake position */
    ECUP_CAL_PedalIndex_BrakeMax = 4,
    /* Maximum regenerative position */
    ECUP_CAL_PedalIndex_RegenMax = 5,
};

enum ECUP_CalibrationIndex {
    /* FIX THIS SHIT */
    ECUP_CalibrationIndex_dummy = 1,
};

enum ECUB_Batt_code {
    /* No power drawn nor charged */
    ECUB_Batt_code_IDLE = 0,
    /* Charging with balancing */
    ECUB_Batt_code_CHARGING = 1,
    /* Charging without balancing */
    ECUB_Batt_code_FAST_CHARGING = 2,
    /* Only balancing */
    ECUB_Batt_code_BALANCING = 3,
    /* Is being discharged */
    ECUB_Batt_code_DISCHARGING = 4,
    /* Fully charged */
    ECUB_Batt_code_FULL = 5,
    /* Is in error state */
    ECUB_Batt_code_ERROR = 6,
};

enum ECUB_CarState {
    /* SDC interrupted -> not ready for start */
    ECUB_CarState_NOT_READY = 0,
    /* Fatal error \w SDC latching */
    ECUB_CarState_LATCHED = 1,
    /* Ready for TSON button */
    ECUB_CarState_TS_READY = 2,
    /* ACP is being precharged -> waiting for ECUA status */
    ECUB_CarState_PRECHARGE = 3,
    /* Ready for START */
    ECUB_CarState_TS_ON = 4,
    /* Waiting for completion of RTDS */
    ECUB_CarState_WAITING_FOR_RTDS = 5,
    /* Drive! */
    ECUB_CarState_STARTED = 6,
};

enum ECUB_GLV_PowerSource {
    /* ACP */
    ECUB_GLV_PowerSource_ACP = 0,
    /* GLV battery */
    ECUB_GLV_PowerSource_GLV_BATTERY = 1,
    /* Service box input */
    ECUB_GLV_PowerSource_SERVICE_INPUT = 2,
};

enum ECUB_Notready_reason {
    /* No error */
    ECUB_Notready_reason_NONE = 0,
    /* Vehicle was latched at the startup */
    ECUB_Notready_reason_LATCH_START = 1,
    /* Vehicle was latched due to BSPD error */
    ECUB_Notready_reason_LATCH_BSPD = 2,
    /* Vehicle was latched due to AMS error */
    ECUB_Notready_reason_LATCH_AMS = 3,
    /* Error in SDC chain */
    ECUB_Notready_reason_SDC_FAILURE = 4,
    /* Motor controller CAN timeout */
    ECUB_Notready_reason_TIMEOUT_MC = 5,
    /* AMS CAN timeout */
    ECUB_Notready_reason_TIMEOUT_ECUA = 6,
    /* ECU Front CAN timeout */
    ECUB_Notready_reason_TIMEOUT_ECUF = 7,
    /* Pedal unit CAN timeout */
    ECUB_Notready_reason_TIMEOUT_ECUP = 8,
    /* VDCU CAN timeout */
    ECUB_Notready_reason_TIMEOUT_VDCU = 9,
    /* Fault on PWM_fault pins */
    ECUB_Notready_reason_PWM_FAULT = 10,
};

enum VDCU_CAL_DisIndex {
    /* None */
    VDCU_CAL_DisIndex_None = 0,
    /* Front right displacement sensor calibration */
    VDCU_CAL_DisIndex_DisFR = 1,
    /* Front left displacement sensor calibration */
    VDCU_CAL_DisIndex_DisFL = 2,
    /* Rear right displacement sensor calibration */
    VDCU_CAL_DisIndex_DisRR = 3,
    /* Rear left displacement sensor calibration */
    VDCU_CAL_DisIndex_DisRL = 4,
};

enum VDCU_VDCU_Param {
    /* Torque gain (0-100) */
    VDCU_VDCU_Param_Trq_Gain = 0,
    /* Maximum torque for front axle (0-100) */
    VDCU_VDCU_Param_Trq_MaxFront = 1,
    /* Maximum torque for rear axle (0-100) */
    VDCU_VDCU_Param_Trq_MaxRear = 2,
    /* Maximum power in kW (0-140) */
    VDCU_VDCU_Param_PwrLim = 3,
    /* Maximum regenerative power in kW (0-40) */
    VDCU_VDCU_Param_Gen_PwrLim = 4,
    /* Pedal map selector (0-4) */
    VDCU_VDCU_Param_Ped_MAP = 5,
    /* Torque distribution to rear (0-100) */
    VDCU_VDCU_Param_TV_Distrib = 10,
    /* Torque vectoring gain on front axle (0-200) */
    VDCU_VDCU_Param_TV_Front_Gain = 11,
    /* Torque vectoring gain on rear axle (0-200) */
    VDCU_VDCU_Param_TV_Rear_Gain = 12,
    /* Torque  vectoring speed decline (0-100) */
    VDCU_VDCU_Param_TV_Speed_Decline = 13,
    /* Slip ratio controller slip setpoint (4-20) */
    VDCU_VDCU_Param_TC_Slip_SP = 16,
    /* Yaw rate controller reference gain (0-200) */
    VDCU_VDCU_Param_YC_Ref_Gain = 19,
    /* Yaw controller output gain (0-200) */
    VDCU_VDCU_Param_YC_Gain = 20,
    /* Field weakening (0-100) */
    VDCU_VDCU_Param_FieldWeak = 23,
    /* Request for reverse [0,1] (not a parameter) */
    VDCU_VDCU_Param_Reverse_REQ = 25,
    /* Racing mode (0-11) (OFF,accel, skid, autox, endu, fun, amateur, transport ...) */
    VDCU_VDCU_Param_RaceMode_REQ = 26,
    /* TorqueVectoring (distribution) enable */
    VDCU_VDCU_Param_TV_EN = 29,
    /* ENABLE regenerative braking [0,1] */
    VDCU_VDCU_Param_Gen_EN = 28,
    /* ENABLE unlimited performance [0,1] */
    VDCU_VDCU_Param_Boost_EN = 29,
    /* Torque speed limitation ramp (0-100) */
    VDCU_VDCU_Param_Trq_Speed_Decline = 32,
    /* Slip ratio controller threshold (0-10) */
    VDCU_VDCU_Param_TC_Threshold = 35,
    /* Slip ratio controller Kp gain (0-200) */
    VDCU_VDCU_Param_TC_Kp = 36,
    /* Slip ratio controller Ki gain (0-200) */
    VDCU_VDCU_Param_TC_Ki = 37,
    /* Slip ratio controller Kb gain(0-100) */
    VDCU_VDCU_Param_TC_Kb = 38,
    /* Yaw controller Speed limitation ramp (0-100) */
    VDCU_VDCU_Param_YC_Speed_Decline = 40,
    /* Yaw controller Kp gain (0-200) */
    VDCU_VDCU_Param_YC_Kp = 41,
    /* Yaw controller Ki gain (0-200) */
    VDCU_VDCU_Param_YC_Ki = 42,
    /* Yaw controller Kb gain (0-100) */
    VDCU_VDCU_Param_YC_Kb = 43,
    /* Feedforward gain (0-200) */
    VDCU_VDCU_Param_FeedForward_Gain = 44,
    /* Power limiting speed ramp (0-100) */
    VDCU_VDCU_Param_PwrLim_Ramp_Decline = 50,
};

enum VDCU_VDCU_State {
    /* Waiting for RTD */
    VDCU_VDCU_State_STANDBY = 0,
    /* Torque enabled */
    VDCU_VDCU_State_TORQUE_EN = 1,
    /* Error state */
    VDCU_VDCU_State_ERROR = 2,
};

enum ECUF_CAL_STWIndex {
    /* None */
    ECUF_CAL_STWIndex_None = 0,
    /* Left position (output is positive) */
    ECUF_CAL_STWIndex_STWLeft = 1,
    /* Center position */
    ECUF_CAL_STWIndex_STWCenter = 2,
    /* Right position (output is negative) */
    ECUF_CAL_STWIndex_STWRight = 3,
};

enum ECUA_AIRsState {
    /* Awaiting detection of car or charger */
    ECUA_AIRsState_pendingChargerDetect = 0,
    /* Awaiting SDC completion to begin precharge */
    ECUA_AIRsState_ready = 1,
    /* Startup check */
    ECUA_AIRsState_startupCheck = 2,
    /* Precharge relay is being closed */
    ECUA_AIRsState_prechargeClosing = 3,
    /* HV- relay is being closed */
    ECUA_AIRsState_hvMClosing = 4,
    /* Precharge part 1: blind delay */
    ECUA_AIRsState_precharging = 5,
    /* Precharge part 2: wait for ΔV to approach zero */
    ECUA_AIRsState_waitingForVdiff = 6,
    /* HV+ relay is being closed */
    ECUA_AIRsState_hvPClosing = 7,
    /* Precharge is finishing */
    ECUA_AIRsState_endPrecharge = 8,
    /* TS is charged and active */
    ECUA_AIRsState_tsActive = 9,
    /* A fatal error occured and the AMS is latched */
    ECUA_AIRsState_fatalError = 10,
    /* Precharge failed, cooling down before retrying */
    ECUA_AIRsState_cooldown = 12,
    /* HV- failed to close, cooling down before retrying */
    ECUA_AIRsState_hvmCooldown = 13,
};

enum ECUA_StateAMS {
    /* without_fault */
    ECUA_StateAMS_All_OK = 0,
    /* All_fucked */
    ECUA_StateAMS_SHIT = 1,
};

/*
 * Base status of ECUA and its subsystems (AMS)
 */
typedef struct ECUA_Status_t {
	/* Lead from ECUB (1 = open) */
	uint8_t	SDC_IN_Open;

	/* True if HV interlock is closed */
	uint8_t	SDC_HV_ILOCK;

	/* True if SDC is not broken by IMD */
	uint8_t	SDC_IMD;

	/* AMS = ECUA+BMS */
	uint8_t	SDC_AMS;

	/* SDC out to final stretch (BSPD etc...) */
	uint8_t	SDC_OUT;

	/* End of SDC (input to AIRS) */
	uint8_t	SDC_END;

	/* HW latch engaged (caused by IMD or AMS) */
	uint8_t	LATCH_SDC_AMS;

	/* State of AIRs */
	enum ECUA_AIRsState	AIRsState;

	/* AIRs error code */
	uint8_t	AIRs_errno;

	/* Fault of ACP overtemperature */
	uint8_t	FT_ACP_OT;

	/* Fault of AIRs */
	uint8_t	FT_AIRS;

	/* Fault of DCDC GLV converter */
	uint8_t	FT_DCDC;

	/* FAN1 dead */
	uint8_t	FT_FAN1;

	/* FAN2 dead */
	uint8_t	FT_FAN2;

	/* FAN3 dead */
	uint8_t	FT_FAN3;

	/* Fault HV overvoltage */
	uint8_t	FT_HV_OV;

	/* Fault HV undervoltage */
	uint8_t	FT_HV_UV;

	/* Fault of GLV (undervoltage measurement) */
	uint8_t	FT_GLV_UV;

	/* Fault of GLV (overvoltage measurement) */
	uint8_t	FT_GLV_OV;

	/* Internal ECUA/BMS faults */
	uint8_t	FT_AMS;

	/* If any error is present */
	uint8_t	FT_ANY;

	/* Warning for cell tempreature (near limits) */
	uint8_t	WARN_TEMP_Cell;

	/* Warning for dc-dc temperature (near limits) */
	uint8_t	WARN_TEMP_DCDC;

	/* Warning for balancer temperature (near limits) */
	uint8_t	WARN_TEMP_Bal;

	/* ACP is attached to charger? */
	uint8_t	charger_attached;

	/* 24V power output is active */
	uint8_t	DCDC_GLV_EN;

	/* Fans are active */
	uint8_t	FANS_EN;

	/* Message up counter for safety */
	uint8_t	SEQ;
} ECUA_Status_t;

/*
 * ACP power limits that are calculated in time based on temperature and votlages.
 * 
 * For example if undervoltage the PWR_OUT should be some few kW value to let the driver decide to risk.
 * If ACP is full PWR_IN should be 0.
 */
typedef struct ECUA_Limits_t {
	/* ACP output power maximum limit */
	uint16_t	PWR_OUT;

	/* ACP input power maximum limit */
	uint16_t	PWR_IN;
} ECUA_Limits_t;

/*
 * Main ACP measurements
 */
typedef struct ECUA_ACPMeas_t {
	/* HV before AIRs */
	uint16_t	Volt_HV_in;

	/* HV at output of ACP */
	uint16_t	Volt_HV_out;

	/* HV Current (positive if energy flowing outwards) */
	uint16_t	Curr_HV_out;

	/* LV Current */
	uint8_t	Curr_DCDC_out;

	/* Fans current */
	uint8_t	Curr_FANS;
} ECUA_ACPMeas_t;

/*
 * Calculated data in ACP
 */
typedef struct ECUA_Estimation_t {
	/* Charge lost in motoring */
	uint16_t	Charge_OUT;

	/* Charge reccuperated */
	uint16_t	Charge_IN;

	/* State of charge estimation */
	uint8_t	SOC;
} ECUA_Estimation_t;

/*
 * AMS Overal data
 * 
 * Auch ein bisschen redundant
 */
typedef struct ECUA_AMSOverall_t {
	/* Maximum cell voltage over ACP */
	uint16_t	Volt_Max;

	/* Minimum cell voltage over ACP */
	uint16_t	Volt_Min;

	/* Maximum cell temperature over ACP */
	int8_t	Temp_Min;

	/* Minimum cell temperature over ACP */
	int8_t	Temp_Max;

	/* Maximum cell index */
	uint8_t	Temp_Max_Index;

	/* Minimum cell index */
	uint8_t	Volt_Min_index;
} ECUA_AMSOverall_t;

/*
 * ECUB Status report
 */
typedef struct ECUB_Status_t {
	/* Shutdown circuit - Front */
	uint8_t	SDC_FRONT;

	/* Shutdown circuit - Shutdown button left */
	uint8_t	SDC_SDBL;

	/* Shutdown circuit - Shutdown button right */
	uint8_t	SDC_SDBR;

	/* Shutdown circuit - High voltage disconnect */
	uint8_t	SDC_HVD;

	/* Shutdown circuit - Brake plausibility device */
	uint8_t	SDC_BSPD;

	/* Shutdown circuit - Motor controller rear */
	uint8_t	SDC_MCUR;

	/* Shutdown circuit - Accumulator management system */
	uint8_t	SDC_AMS;

	/* Shutdown circuit - Tractive system master switch */
	uint8_t	SDC_TSMS;

	/* Current vehicle state */
	enum ECUB_CarState	CarState;

	/* Reason for latest not-ready CarState */
	enum ECUB_Notready_reason	CarState_Notready;

	/* Current powering source */
	enum ECUB_GLV_PowerSource	PowerSource;

	/* Module 1 detected */
	uint8_t	Det_MOD1;

	/* Module 2 detected */
	uint8_t	Det_MOD2;

	/* Module 3 detected */
	uint8_t	Det_MOD3;

	/* Module 4 detected */
	uint8_t	Det_MOD4;

	/* Fault temperature shutdown for driver on PWR_ECUF_EN, PWR_ECUA_EN */
	uint8_t	FT_PWR1_OT;

	/* Fault temperature shutdown for driver on PWR_ECUMF_EN, PWR_ECUMR_EN */
	uint8_t	FT_PWR2_OT;

	/* Fault temperature shutdown for driver on WP1_EN, WP2_EN */
	uint8_t	FT_PWR3_OT;

	/* Fault temperature shutdown for driver on EM, FAN3_EN */
	uint8_t	FT_PWR4_OT;

	/* Fault temperature shutdown for driver on FAN1_EN, FAN2_EN */
	uint8_t	FT_PWR5_OT;

	/* Fault temperature shutdown for driver on RTDS, SDB LED R i L, BrakeLight */
	uint8_t	FT_L2_OT;

	/* If any error present */
	uint8_t	FT_ANY;

	/* Fault temperature shutdown for driver on WS, AUX1,2,3 */
	uint8_t	FT_L1_OT;

	/* Fault ECUF power (Short to VCC) */
	uint8_t	FT_PWR_ECUF_OC;

	/* Fault ECUA power (Short to VCC) */
	uint8_t	FT_PWR_ECUA_OC;

	/* Fault MCF power (Short to VCC) */
	uint8_t	FT_PWR_MCF_OC;

	/* Fault MCR power (Short to VCC) */
	uint8_t	FT_PWR_MCR_OC;

	/* Fault of CAN Bus (CAN errors or controller mode is error) */
	uint8_t	FT_CAN1;

	/* Fault of CAN Bus (CAN errors or controller mode is error) */
	uint8_t	FT_CAN2;

	/* Power to ECUF enabled */
	uint8_t	PWR_ECUF_EN;

	/* Power to ECUA enabled */
	uint8_t	PWR_ECUA_EN;

	/* Power to MCUF enabled */
	uint8_t	PWR_MCUF_EN;

	/* Power to MCUR enabled */
	uint8_t	PWR_MCUR_EN;

	/* Power to Energy Meter enabled */
	uint8_t	PWR_EM_EN;

	/* Power to Waterpump 1 enabled */
	uint8_t	PWR_WP1_EN;

	/* Power to Waterpump 2 enabled */
	uint8_t	PWR_WP2_EN;

	/* Power to FAN1 enabled */
	uint8_t	PWR_FAN1_EN;

	/* Power to FAN2 enabled */
	uint8_t	PWR_FAN2_EN;

	/* Power to FAN3 enabled */
	uint8_t	PWR_FAN3_EN;

	/* Power to Wheel speed sensor enabled */
	uint8_t	PWR_WS_EN;

	/* Power to aux1 enabled aka LIDK1 (Low I Don't Know #1) */
	uint8_t	PWR_AUX1_EN;

	/* Power to aux2 enabled aka LIDK2 */
	uint8_t	PWR_AUX2_EN;

	/* Power to aux3 enabled aka LIDK3 */
	uint8_t	PWR_AUX3_EN;

	/* Ready to drive sound enabled */
	uint8_t	RTDS_EN;

	/* Shutdown button right led enabled */
	uint8_t	SDBR_LED_EN;

	/* Shutdown button left led enabled */
	uint8_t	SDBL_LED_EN;

	/* Brakelight enabled */
	uint8_t	BrakeLight_EN;

	/* TSAL ""Test"" or ""Override"" totally not a hack enabled */
	uint8_t	TSAL_Override;

	/* Message up counter for safety check */
	uint8_t	SEQ;
} ECUB_Status_t;

/*
 * PWM for each fan and waterpump
 */
typedef struct ECUB_Cooling_t {
	/* Waterpump cooler circuit PWM duty */
	uint8_t	WP1;

	/* Waterpump cooler circuit PWM duty */
	uint8_t	WP2;

	/* Cooler FAN in PWM duty */
	uint8_t	FAN1;

	/* Cooler FAN in PWM duty */
	uint8_t	FAN2;

	/* Cooler FAN in PWM duty */
	uint8_t	FAN3;

	/* Warning - Motor temperature over nominal threshold */
	uint8_t	WARN_MOT_FR_TEMP;

	/* Warning - Motor temperature over nominal threshold */
	uint8_t	WARN_MOT_FL_TEMP;

	/* Warning - Motor temperature over nominal threshold */
	uint8_t	WARN_MOT_RR_TEMP;

	/* Warning - Motor temperature over nominal threshold */
	uint8_t	WARN_MOT_RL_TEMP;

	/* Warning - Motor controller temperature over nominal threshold */
	uint8_t	WARN_MCU_FR_TEMP;

	/* Warning - Motor controller temperature over nominal threshold */
	uint8_t	WARN_MCU_FL_TEMP;

	/* Warning - Motor controller temperature over nominal threshold */
	uint8_t	WARN_MCU_RR_TEMP;

	/* Warning - Motor controller temperature over nominal threshold */
	uint8_t	WARN_MCU_RL_TEMP;

	/* Warning - Brake temperature over nominal threshold */
	uint8_t	WARN_Brake_RR_TEMP;

	/* Warning - Brake temperature over nominal threshold */
	uint8_t	WARN_Brake_RL_TEMP;

	/* Fault - motor overtemperature */
	uint8_t	FT_MOT_FR_OT;

	/* Fault - motor overtemperature */
	uint8_t	FT_MOT_FL_OT;

	/* Fault - motor overtemperature */
	uint8_t	FT_MOT_RR_OT;

	/* Fault - motor overtemperature */
	uint8_t	FT_MOT_RL_OT;

	/* Fault - motor controller overtemperature */
	uint8_t	FT_MCU_FR_OT;

	/* Fault - motor controller overtemperature */
	uint8_t	FT_MCU_FL_OT;

	/* Fault - motor controller overtemperature */
	uint8_t	FT_MCU_RR_OT;

	/* Fault - motor controller overtemperature */
	uint8_t	FT_MCU_RL_OT;

	/* Fault - brake overtemperature */
	uint8_t	FT_Brake_RR_OT;

	/* Fault - brake overtemperature */
	uint8_t	FT_Brake_RL_OT;
} ECUB_Cooling_t;

/*
 * Rear suspension temperatures
 * 
 */
typedef struct ECUB_TEMPSuspR_t {
	/* Rear right brake caliper temperature */
	uint8_t	BrakeCal_RR;

	/* Rear left brake caliper temperature */
	uint8_t	BrakeCal_RL;

	/* Rear right tire inboard temperature */
	uint8_t	TireI_RR;

	/* Rear right tire center temperature */
	uint8_t	TireC_RR;

	/* Rear right tire outboard temperature */
	uint8_t	TireO_RR;

	/* Rear left tire inboard temperature */
	uint8_t	TireI_RL;

	/* Rear left tire center temperature */
	uint8_t	TireC_RL;

	/* Rear left tire inboard temperature */
	uint8_t	TireO_RL;
} ECUB_TEMPSuspR_t;

/*
 * Auxiliary temperature measurements - cooling system
 */
typedef struct ECUB_TEMPAux_t {
	/*  */
	uint8_t	Cooling1_NTC;

	/*  */
	uint8_t	Cooling2_NTC;

	/*  */
	uint8_t	Cooling3_NTC;

	/*  */
	uint8_t	Cooling4_NTC;
} ECUB_TEMPAux_t;

/*
 * Summary of unit status and faults
 */
typedef struct ECUF_Status_t {
	/* Shutdown circuit from SDB_Cockpit */
	uint8_t	SDC_SDBC;

	/* Inertia switch shutdown circuit */
	uint8_t	SDC_Inertia;

	/* Front Wheel Interlock (Connetore Italiano Supreme) */
	uint8_t	SDC_FWIL;

	/* Power to ECUP is enabled */
	uint8_t	PWR_ECUP_EN;

	/* Power to ECUG is enabled */
	uint8_t	PWR_ECUG_EN;

	/* Power to DTLG is enabled */
	uint8_t	PWR_DTLG_EN;

	/* Power to ECUS is enabled */
	uint8_t	PWR_ECUS_EN;

	/* Power to Dash is enabled */
	uint8_t	PWR_DASH_EN;

	/* Power to front brake fans is enabled */
	uint8_t	PWR_FAN_BrakeF_EN;

	/* Warning - Brake temperature over nominal threshold */
	uint8_t	WARN_Brake_FR_TEMP;

	/* Warning - Brake temperature over nominal threshold */
	uint8_t	WARN_Brake_FL_TEMP;

	/* ECUP enabled but no current is drawn */
	uint8_t	FT_PWR_ECUP;

	/* ECUG enabled but no current is drawn */
	uint8_t	FT_PWR_ECUG;

	/* ECUS enabled but no current is drawn */
	uint8_t	FT_PWR_ECUS;

	/* DTLG enabled but no current is drawn */
	uint8_t	FT_PWR_DTLG;

	/* DASH enabled but no current is drawn */
	uint8_t	FT_PWR_DASH;

	/* FAN enabled but no current is drawn */
	uint8_t	FT_PWR_FAN_BrakeF;

	/* STW sensor disconnected or destroyed */
	uint8_t	FT_STW_Sensor;

	/* Fault of steering wheel calibration */
	uint8_t	FT_STW_Cal;

	/* Fault of suspension displacement sensor FR */
	uint8_t	FT_DisFR;

	/* Fault of suspension displacement sensor FL */
	uint8_t	FT_DisFL;

	/* Fault of suspension displacement sensor RR */
	uint8_t	FT_DisRR;

	/* Fault of suspension displacement sensor RL */
	uint8_t	FT_DisRL;

	/* Fault of suspension displacement sensor FR calibration */
	uint8_t	FT_DisFR_Cal;

	/* Fault of suspension displacement sensor FL calibration */
	uint8_t	FT_DisFL_Cal;

	/* Fault of suspension displacement sensor RR calibration */
	uint8_t	FT_DisRR_Cal;

	/* Fault of suspension displacement sensor RL calibration */
	uint8_t	FT_DisRL_Cal;

	/* Fault - brake overtemperature */
	uint8_t	FT_Brake_FR_OT;

	/* Fault - brake overtemperature */
	uint8_t	FT_Brake_FL_OT;

	/* GLV Voltage at ECUF input */
	uint8_t	Volt_GLV_In;
} ECUF_Status_t;

/*
 * Steering wheel angle measurements.
 */
typedef struct ECUF_STW_t {
	/* Steering wheel angle. Left positive */
	int16_t	Angle;

	/* Steering wheel angularspeed. Left positive */
	int16_t	AngularSpeed;

	/* Steering wheel measurement fault */
	uint8_t	FT_STW;

	/* Message up counter for safety */
	uint8_t	SEQ;
} ECUF_STW_t;

/*
 * Front suspension temperatures
 */
typedef struct ECUF_TEMPSuspF_t {
	/* Front right brake caliper temperature */
	uint8_t	BrakeCal_FR;

	/* Front left brake caliper temperature */
	uint8_t	BrakeCal_FL;

	/* Front right tire inboard temperature */
	uint8_t	TireI_FR;

	/* Front right tire center temperature */
	uint8_t	TireC_FR;

	/* Front right tire outboard temperature */
	uint8_t	TireO_FR;

	/* Front left tire inboard  temperature */
	uint8_t	TireI_FL;

	/* Front left tire center temperature */
	uint8_t	TireC_FL;

	/* Front left tire outboard temperature */
	uint8_t	TireO_FL;
} ECUF_TEMPSuspF_t;

/*
 * Request calibration of steering wheel
 */
typedef struct ECUF_REQCalibSTW_t {
	/* Which steering wheel position to calibrate */
	enum ECUF_CAL_STWIndex	which;
} ECUF_REQCalibSTW_t;

/*
 * ECUP Status message
 */
typedef struct ECUP_Status_t {
	/* SDC is powered after BOTS */
	uint8_t	SDC_BOTS;

	/* If any error is present */
	uint8_t	FT_ANY;

	/* Accelerator pedals plausible */
	uint8_t	APPS_Plausible;

	/* Brake Pedal Plausibility Check (software bspd) */
	uint8_t	BPPC_Latch;

	/* Brake active (Signal mainly for brakelight) */
	uint8_t	BrakeActive;

	/* Brake active for the purposes of BSPD */
	uint8_t	BrakeActive_BSPD;
} ECUP_Status_t;

/*
 * Pedal values and valid flags
 */
typedef struct ECUP_Pedals_t {
	/* Normalized accelerator value */
	uint16_t	APPS_pos;

	/* Normalized brake encoder value */
	uint16_t	Brake_pos;

	/* There is some error with sensor or calibration */
	uint8_t	FT_APPS_pos;

	/* There is some error with sensor or calibration */
	uint8_t	FT_Brake_Pos;

	/* Message counter for safety */
	uint8_t	SEQ;
} ECUP_Pedals_t;

/*
 * Brake pressures sensor
 */
typedef struct ECUP_Pressure_t {
	/* Brake front pressure */
	uint16_t	BrakeF;

	/* Brake rear pressure */
	uint16_t	BrakeR;

	/* Fault of brake pressure sensor front */
	uint8_t	FT_BrakeF;

	/* Fault of brake pressure sensor rear */
	uint8_t	FT_BrakeR;
} ECUP_Pressure_t;

/*
 * Request calibration.
 * Assign pedal max/min to its' current position.
 */
typedef struct ECUP_REQCalibPedal_t {
	/* Calibration index to set */
	enum ECUP_CAL_PedalIndex	which;
} ECUP_REQCalibPedal_t;

/*
 * Raw diagnostic positional data of pedals
 */
typedef struct ECUP_DiagPos_t {
	/* Raw read value of accelerator position sensor 1 */
	uint16_t	Acc1_raw;

	/* Raw read value of accelerator position sensor 2 */
	uint16_t	Acc2_raw;

	/* Raw read value of brake position sensor */
	uint16_t	BrkPos_raw;

	/* Raw calculated value of brake pedal plausability check (BPPC) */
	uint16_t	BPPC_raw;
} ECUP_DiagPos_t;

/*
 * Status of ECUS unit
 */
typedef struct ECUS_Status_t {
	/* Upcounter, ++ on each message transmission */
	uint8_t	SEQ;
} ECUS_Status_t;

/*
 * Calibration, configuration
 */
typedef struct IMU_Status_t {
	/*  */
	uint8_t	State;

	/* Fault for ACC calibration */
	uint8_t	FT_ACC_Cal;

	/* Fault for Gyro calibration */
	uint8_t	FT_Gyro_Cal;

	/* Fault for mount calibration */
	uint8_t	FT_Mount_Cal;
} IMU_Status_t;

/*
 * Actual settings and states, system faults.
 */
typedef struct MCR_GeneralReport_t {
	/* Shutdown circuit - point at input. */
	uint8_t	SDC_IN;

	/* Shutdown circuit - point after channel B motor's sensor connector. */
	uint8_t	SDC_MSCB;

	/* Shutdown circuit - point after channel B motor's power connector. */
	uint8_t	SDC_MPCB;

	/* Shutdown circuit - point after high voltage connector. */
	uint8_t	SDC_HVC;

	/* Shutdown circuit - point after channel A motor's power connector. */
	uint8_t	SDC_MPCA;

	/* Shutdown circuit - point after channel A motor's sensor connector. */
	uint8_t	SDC_MSCA;

	/* True means discharge resistor is connected. */
	uint8_t	DISCH;

	/* True means active auxiliary power output channel A. */
	uint8_t	POA;

	/* Power supply for POA. log.1 = 12V, log.0 = input voltage (24V). */
	uint8_t	POA_PS;

	/* True means active auxiliary power output channel B. */
	uint8_t	POB;

	/* Power supply for POB. log.1 = 12V, log.0 = input voltage (24V). */
	uint8_t	POB_PS;

	/* True means channel A PWM is active. */
	uint8_t	PWMA;

	/* True means field weakening is allowed for channel A. */
	uint8_t	FWA;

	/* True means generation mode is allowed for channel A. */
	uint8_t	GENA;

	/* Default direction for positive requests values.  */
	uint8_t	DIRA;

	/* True means channel B PWM is active. */
	uint8_t	PWMB;

	/* True means field weakening is allowed for channel B. */
	uint8_t	FWB;

	/* True means generation mode is allowed for channel B. */
	uint8_t	GENB;

	/* Default direction for positive requests values.  */
	uint8_t	DIRB;

	/* Heart beat. */
	uint8_t	HB;
} MCR_GeneralReport_t;

/*
 * Thermal measures for channel A.
 */
typedef struct MCR_ThermalMeasuresA_t {
	/* Temperature of IGBT's heat sink. */
	uint8_t	TIGBT;

	/* Temperature estimation of IGBT chip. */
	uint8_t	TIGBTJ;

	/* Temperature of motor's connector. */
	uint8_t	TMOTCON;

	/* Temperature of motor's temp. sensor. */
	uint8_t	TMOTSEN;

	/* Temperature estimation of motor's winding. */
	uint8_t	TMOTWIN;

	/* Temperature of capacitor bank. */
	uint8_t	TCAP;

	/* Motor performance capacity utilization rate. */
	uint8_t	TMOTI2T;
} MCR_ThermalMeasuresA_t;

/*
 * Thermal measures for channel B.
 */
typedef struct MCR_ThermalMeasuresB_t {
	/* Temperature of IGBT's heat sink. */
	uint8_t	TIGBT;

	/* Temperature estimation of IGBT chip. */
	uint8_t	TIGBTJ;

	/* Temperature of motor's connector. */
	uint8_t	TMOTCON;

	/* Temperature of motor's temp. sensor. */
	uint8_t	TMOTSEN;

	/* Temperature estimation of motor's winding. */
	uint8_t	TMOTWIN;

	/* Temperature of capacitor bank. */
	uint8_t	TCAP;

	/* Motor performance capacity utilization rate. */
	uint8_t	TMOTI2T;
} MCR_ThermalMeasuresB_t;

/*
 * VDCU systems status
 */
typedef struct VDCU_Status_t {
	/* VDCU State machine */
	enum VDCU_VDCU_State	State;

	/* Torque vectoring enabled */
	uint8_t	TV_ENABLED;

	/* Slip ratio control enabled (traction control) */
	uint8_t	TC_ENABLED;

	/* Yaw controller enabled */
	uint8_t	YC_ENABLED;

	/* Fault of displacement sensor calibration */
	uint8_t	FT_Dis_Cal;

	/*  */
	uint8_t	FT_Sensor;

	/* Derating due to components temperature */
	uint8_t	TEMP_derating;

	/* Derating due to ACP limits */
	uint8_t	ACP_derating;

	/* Discharge is active */
	uint8_t	Disch_ACT;

	/* Reverse is activated */
	uint8_t	Reverse_ACT;

	/* Slip ratio control is limiting torque */
	uint8_t	TC_ACT;

	/* Yaw controller is producing yaw torque */
	uint8_t	YC_ACT;
} VDCU_Status_t;

/*
 * Overal actual values of motor torques
 */
typedef struct VDCU_Controller_t {
	/* Torque request overal */
	int16_t	TRQ_Req;

	/* Longitudinal torque distribution overall */
	uint8_t	TRQ_Dist_Long;

	/* Lateral torque distribution overall */
	int8_t	TRQ_Dist_Lat;

	/* Yaw torque request overall */
	int16_t	TRQ_Yaw_Req;

	/* YawRate reference value */
	int16_t	YawRate_Ref;
} VDCU_Controller_t;

/*
 * Formula Body actual values
 */
typedef struct VDCU_Body_t {
	/* Reference speed estimated */
	int16_t	Speed_Ref;

	/* Slip angle */
	int8_t	Slip_angle;

	/* Roll angle relative to road */
	int8_t	Roll;

	/* Pitch angle relative to road */
	int8_t	Pitch;

	/* Heave angle relative to road */
	int8_t	Heave;
} VDCU_Body_t;

/*
 * Calculated and calibrated wheel loads. Using accelerometer, configuration and suspension displacement sensors
 */
typedef struct VDCU_WheelFz_t {
	/* FR Wheel load calibrated */
	uint16_t	FR;

	/* FL Wheel load calibrated */
	uint16_t	FL;

	/* RR Wheel load calibrated */
	uint16_t	RR;

	/* RL Wheel load calibrated */
	uint16_t	RL;
} VDCU_WheelFz_t;

/*
 * Parameters changed in ECUS are muxed and sent after every change. Acknowledge is expected in next 20ms. If not acknowledged parameters are resend unitl 5th time. Whole parameters are boadcasted in a loop. The acknowledges parameters data are then displayed.
 */
typedef struct VDCU_Param_t {
	/* Parameter multiplexer */
	enum VDCU_VDCU_Param	Param_ID;

	/* Parameter data signal */
	int16_t	Param;

	/* Up counter for every corresponding parameter change */
	uint8_t	SEQ_PARAM;

	/* Message up counter for safety */
	uint8_t	SEQ;
} VDCU_Param_t;

/*
 * ECUS is displaying and evaluating the parameters that are only sent and acknowledged. That means that the initial parameter set is sent from ECUS and should be acknowledged of the actual used values by unit
 */
typedef struct VDCU_Param_ACK_t {
	/* Parameter multiplexer */
	uint8_t	Param_ID;

	/* Parameter used data signal */
	int16_t	Param;

	/* Up counter for every corresponding parameter change acknowledgement */
	uint8_t	SEQ_Param;
} VDCU_Param_ACK_t;

/*
 * Request for displacement sensor calibration
 */
typedef struct VDCU_REQCalibDis_t {
	/* 1-FR, 2-FL, 3-RR, 4-RL */
	enum VDCU_CAL_DisIndex	which;

	/* Measured wheel load at scales on water level surface */
	int16_t	load;

	/* ??? */
	int16_t	scale;
} VDCU_REQCalibDis_t;

/*
 * SOC Estimation
 */
typedef struct VDCU_SOC_t {
	/* SOC of ACP */
	uint8_t	SOC;
} VDCU_SOC_t;

void candbInit(void);

int ECUA_decode_Status_s(const uint8_t* bytes, size_t length, ECUA_Status_t* data_out);
int ECUA_decode_Status(const uint8_t* bytes, size_t length, uint8_t* SDC_IN_Open_out, uint8_t* SDC_HV_ILOCK_out, uint8_t* SDC_IMD_out, uint8_t* SDC_AMS_out, uint8_t* SDC_OUT_out, uint8_t* SDC_END_out, uint8_t* LATCH_SDC_AMS_out, enum ECUA_AIRsState* AIRsState_out, uint8_t* AIRs_errno_out, uint8_t* FT_ACP_OT_out, uint8_t* FT_AIRS_out, uint8_t* FT_DCDC_out, uint8_t* FT_FAN1_out, uint8_t* FT_FAN2_out, uint8_t* FT_FAN3_out, uint8_t* FT_HV_OV_out, uint8_t* FT_HV_UV_out, uint8_t* FT_GLV_UV_out, uint8_t* FT_GLV_OV_out, uint8_t* FT_AMS_out, uint8_t* FT_ANY_out, uint8_t* WARN_TEMP_Cell_out, uint8_t* WARN_TEMP_DCDC_out, uint8_t* WARN_TEMP_Bal_out, uint8_t* charger_attached_out, uint8_t* DCDC_GLV_EN_out, uint8_t* FANS_EN_out, uint8_t* SEQ_out);
int ECUA_get_Status(ECUA_Status_t* data_out);
void ECUA_Status_on_receive(int (*callback)(ECUA_Status_t* data));

int ECUA_decode_Limits_s(const uint8_t* bytes, size_t length, ECUA_Limits_t* data_out);
int ECUA_decode_Limits(const uint8_t* bytes, size_t length, uint16_t* PWR_OUT_out, uint16_t* PWR_IN_out);
int ECUA_get_Limits(ECUA_Limits_t* data_out);
void ECUA_Limits_on_receive(int (*callback)(ECUA_Limits_t* data));

int ECUA_decode_ACPMeas_s(const uint8_t* bytes, size_t length, ECUA_ACPMeas_t* data_out);
int ECUA_decode_ACPMeas(const uint8_t* bytes, size_t length, uint16_t* Volt_HV_in_out, uint16_t* Volt_HV_out_out, uint16_t* Curr_HV_out_out, uint8_t* Curr_DCDC_out_out, uint8_t* Curr_FANS_out);
int ECUA_get_ACPMeas(ECUA_ACPMeas_t* data_out);
void ECUA_ACPMeas_on_receive(int (*callback)(ECUA_ACPMeas_t* data));

int ECUA_decode_Estimation_s(const uint8_t* bytes, size_t length, ECUA_Estimation_t* data_out);
int ECUA_decode_Estimation(const uint8_t* bytes, size_t length, uint16_t* Charge_OUT_out, uint16_t* Charge_IN_out, uint8_t* SOC_out);
int ECUA_get_Estimation(ECUA_Estimation_t* data_out);
void ECUA_Estimation_on_receive(int (*callback)(ECUA_Estimation_t* data));

int ECUA_decode_AMSOverall_s(const uint8_t* bytes, size_t length, ECUA_AMSOverall_t* data_out);
int ECUA_decode_AMSOverall(const uint8_t* bytes, size_t length, uint16_t* Volt_Max_out, uint16_t* Volt_Min_out, int8_t* Temp_Min_out, int8_t* Temp_Max_out, uint8_t* Temp_Max_Index_out, uint8_t* Volt_Min_index_out);
int ECUA_get_AMSOverall(ECUA_AMSOverall_t* data_out);
void ECUA_AMSOverall_on_receive(int (*callback)(ECUA_AMSOverall_t* data));

int ECUB_decode_Status_s(const uint8_t* bytes, size_t length, ECUB_Status_t* data_out);
int ECUB_decode_Status(const uint8_t* bytes, size_t length, uint8_t* SDC_FRONT_out, uint8_t* SDC_SDBL_out, uint8_t* SDC_SDBR_out, uint8_t* SDC_HVD_out, uint8_t* SDC_BSPD_out, uint8_t* SDC_MCUR_out, uint8_t* SDC_AMS_out, uint8_t* SDC_TSMS_out, enum ECUB_CarState* CarState_out, enum ECUB_Notready_reason* CarState_Notready_out, enum ECUB_GLV_PowerSource* PowerSource_out, uint8_t* Det_MOD1_out, uint8_t* Det_MOD2_out, uint8_t* Det_MOD3_out, uint8_t* Det_MOD4_out, uint8_t* FT_PWR1_OT_out, uint8_t* FT_PWR2_OT_out, uint8_t* FT_PWR3_OT_out, uint8_t* FT_PWR4_OT_out, uint8_t* FT_PWR5_OT_out, uint8_t* FT_L2_OT_out, uint8_t* FT_ANY_out, uint8_t* FT_L1_OT_out, uint8_t* FT_PWR_ECUF_OC_out, uint8_t* FT_PWR_ECUA_OC_out, uint8_t* FT_PWR_MCF_OC_out, uint8_t* FT_PWR_MCR_OC_out, uint8_t* FT_CAN1_out, uint8_t* FT_CAN2_out, uint8_t* PWR_ECUF_EN_out, uint8_t* PWR_ECUA_EN_out, uint8_t* PWR_MCUF_EN_out, uint8_t* PWR_MCUR_EN_out, uint8_t* PWR_EM_EN_out, uint8_t* PWR_WP1_EN_out, uint8_t* PWR_WP2_EN_out, uint8_t* PWR_FAN1_EN_out, uint8_t* PWR_FAN2_EN_out, uint8_t* PWR_FAN3_EN_out, uint8_t* PWR_WS_EN_out, uint8_t* PWR_AUX1_EN_out, uint8_t* PWR_AUX2_EN_out, uint8_t* PWR_AUX3_EN_out, uint8_t* RTDS_EN_out, uint8_t* SDBR_LED_EN_out, uint8_t* SDBL_LED_EN_out, uint8_t* BrakeLight_EN_out, uint8_t* TSAL_Override_out, uint8_t* SEQ_out);
int ECUB_get_Status(ECUB_Status_t* data_out);
void ECUB_Status_on_receive(int (*callback)(ECUB_Status_t* data));

int ECUB_decode_Cooling_s(const uint8_t* bytes, size_t length, ECUB_Cooling_t* data_out);
int ECUB_decode_Cooling(const uint8_t* bytes, size_t length, uint8_t* WP1_out, uint8_t* WP2_out, uint8_t* FAN1_out, uint8_t* FAN2_out, uint8_t* FAN3_out, uint8_t* WARN_MOT_FR_TEMP_out, uint8_t* WARN_MOT_FL_TEMP_out, uint8_t* WARN_MOT_RR_TEMP_out, uint8_t* WARN_MOT_RL_TEMP_out, uint8_t* WARN_MCU_FR_TEMP_out, uint8_t* WARN_MCU_FL_TEMP_out, uint8_t* WARN_MCU_RR_TEMP_out, uint8_t* WARN_MCU_RL_TEMP_out, uint8_t* WARN_Brake_RR_TEMP_out, uint8_t* WARN_Brake_RL_TEMP_out, uint8_t* FT_MOT_FR_OT_out, uint8_t* FT_MOT_FL_OT_out, uint8_t* FT_MOT_RR_OT_out, uint8_t* FT_MOT_RL_OT_out, uint8_t* FT_MCU_FR_OT_out, uint8_t* FT_MCU_FL_OT_out, uint8_t* FT_MCU_RR_OT_out, uint8_t* FT_MCU_RL_OT_out, uint8_t* FT_Brake_RR_OT_out, uint8_t* FT_Brake_RL_OT_out);
int ECUB_get_Cooling(ECUB_Cooling_t* data_out);
void ECUB_Cooling_on_receive(int (*callback)(ECUB_Cooling_t* data));

int ECUB_decode_TEMPSuspR_s(const uint8_t* bytes, size_t length, ECUB_TEMPSuspR_t* data_out);
int ECUB_decode_TEMPSuspR(const uint8_t* bytes, size_t length, uint8_t* BrakeCal_RR_out, uint8_t* BrakeCal_RL_out, uint8_t* TireI_RR_out, uint8_t* TireC_RR_out, uint8_t* TireO_RR_out, uint8_t* TireI_RL_out, uint8_t* TireC_RL_out, uint8_t* TireO_RL_out);
int ECUB_get_TEMPSuspR(ECUB_TEMPSuspR_t* data_out);
void ECUB_TEMPSuspR_on_receive(int (*callback)(ECUB_TEMPSuspR_t* data));

int ECUB_decode_TEMPAux_s(const uint8_t* bytes, size_t length, ECUB_TEMPAux_t* data_out);
int ECUB_decode_TEMPAux(const uint8_t* bytes, size_t length, uint8_t* Cooling1_NTC_out, uint8_t* Cooling2_NTC_out, uint8_t* Cooling3_NTC_out, uint8_t* Cooling4_NTC_out);
int ECUB_get_TEMPAux(ECUB_TEMPAux_t* data_out);
void ECUB_TEMPAux_on_receive(int (*callback)(ECUB_TEMPAux_t* data));

int ECUF_decode_Status_s(const uint8_t* bytes, size_t length, ECUF_Status_t* data_out);
int ECUF_decode_Status(const uint8_t* bytes, size_t length, uint8_t* SDC_SDBC_out, uint8_t* SDC_Inertia_out, uint8_t* SDC_FWIL_out, uint8_t* PWR_ECUP_EN_out, uint8_t* PWR_ECUG_EN_out, uint8_t* PWR_DTLG_EN_out, uint8_t* PWR_ECUS_EN_out, uint8_t* PWR_DASH_EN_out, uint8_t* PWR_FAN_BrakeF_EN_out, uint8_t* WARN_Brake_FR_TEMP_out, uint8_t* WARN_Brake_FL_TEMP_out, uint8_t* FT_PWR_ECUP_out, uint8_t* FT_PWR_ECUG_out, uint8_t* FT_PWR_ECUS_out, uint8_t* FT_PWR_DTLG_out, uint8_t* FT_PWR_DASH_out, uint8_t* FT_PWR_FAN_BrakeF_out, uint8_t* FT_STW_Sensor_out, uint8_t* FT_STW_Cal_out, uint8_t* FT_DisFR_out, uint8_t* FT_DisFL_out, uint8_t* FT_DisRR_out, uint8_t* FT_DisRL_out, uint8_t* FT_DisFR_Cal_out, uint8_t* FT_DisFL_Cal_out, uint8_t* FT_DisRR_Cal_out, uint8_t* FT_DisRL_Cal_out, uint8_t* FT_Brake_FR_OT_out, uint8_t* FT_Brake_FL_OT_out, uint8_t* Volt_GLV_In_out);
int ECUF_get_Status(ECUF_Status_t* data_out);
void ECUF_Status_on_receive(int (*callback)(ECUF_Status_t* data));

int ECUF_decode_STW_s(const uint8_t* bytes, size_t length, ECUF_STW_t* data_out);
int ECUF_decode_STW(const uint8_t* bytes, size_t length, int16_t* Angle_out, int16_t* AngularSpeed_out, uint8_t* FT_STW_out, uint8_t* SEQ_out);
int ECUF_get_STW(ECUF_STW_t* data_out);
void ECUF_STW_on_receive(int (*callback)(ECUF_STW_t* data));

int ECUF_decode_TEMPSuspF_s(const uint8_t* bytes, size_t length, ECUF_TEMPSuspF_t* data_out);
int ECUF_decode_TEMPSuspF(const uint8_t* bytes, size_t length, uint8_t* BrakeCal_FR_out, uint8_t* BrakeCal_FL_out, uint8_t* TireI_FR_out, uint8_t* TireC_FR_out, uint8_t* TireO_FR_out, uint8_t* TireI_FL_out, uint8_t* TireC_FL_out, uint8_t* TireO_FL_out);
int ECUF_get_TEMPSuspF(ECUF_TEMPSuspF_t* data_out);
void ECUF_TEMPSuspF_on_receive(int (*callback)(ECUF_TEMPSuspF_t* data));

int ECUF_send_REQCalibSTW_s(const ECUF_REQCalibSTW_t* data);
int ECUF_send_REQCalibSTW(enum ECUF_CAL_STWIndex which);

int ECUP_decode_Status_s(const uint8_t* bytes, size_t length, ECUP_Status_t* data_out);
int ECUP_decode_Status(const uint8_t* bytes, size_t length, uint8_t* SDC_BOTS_out, uint8_t* FT_ANY_out, uint8_t* APPS_Plausible_out, uint8_t* BPPC_Latch_out, uint8_t* BrakeActive_out, uint8_t* BrakeActive_BSPD_out);
int ECUP_get_Status(ECUP_Status_t* data_out);
void ECUP_Status_on_receive(int (*callback)(ECUP_Status_t* data));

int ECUP_decode_Pedals_s(const uint8_t* bytes, size_t length, ECUP_Pedals_t* data_out);
int ECUP_decode_Pedals(const uint8_t* bytes, size_t length, uint16_t* APPS_pos_out, uint16_t* Brake_pos_out, uint8_t* FT_APPS_pos_out, uint8_t* FT_Brake_Pos_out, uint8_t* SEQ_out);
int ECUP_get_Pedals(ECUP_Pedals_t* data_out);
void ECUP_Pedals_on_receive(int (*callback)(ECUP_Pedals_t* data));

int ECUP_decode_Pressure_s(const uint8_t* bytes, size_t length, ECUP_Pressure_t* data_out);
int ECUP_decode_Pressure(const uint8_t* bytes, size_t length, uint16_t* BrakeF_out, uint16_t* BrakeR_out, uint8_t* FT_BrakeF_out, uint8_t* FT_BrakeR_out);
int ECUP_get_Pressure(ECUP_Pressure_t* data_out);
void ECUP_Pressure_on_receive(int (*callback)(ECUP_Pressure_t* data));

int ECUP_send_REQCalibPedal_s(const ECUP_REQCalibPedal_t* data);
int ECUP_send_REQCalibPedal(enum ECUP_CAL_PedalIndex which);

int ECUP_decode_DiagPos_s(const uint8_t* bytes, size_t length, ECUP_DiagPos_t* data_out);
int ECUP_decode_DiagPos(const uint8_t* bytes, size_t length, uint16_t* Acc1_raw_out, uint16_t* Acc2_raw_out, uint16_t* BrkPos_raw_out, uint16_t* BPPC_raw_out);
int ECUP_get_DiagPos(ECUP_DiagPos_t* data_out);
void ECUP_DiagPos_on_receive(int (*callback)(ECUP_DiagPos_t* data));

int ECUS_send_Status_s(const ECUS_Status_t* data);
int ECUS_send_Status(uint8_t SEQ);
int ECUS_Status_need_to_send(void);

int IMU_decode_Status_s(const uint8_t* bytes, size_t length, IMU_Status_t* data_out);
int IMU_decode_Status(const uint8_t* bytes, size_t length, uint8_t* State_out, uint8_t* FT_ACC_Cal_out, uint8_t* FT_Gyro_Cal_out, uint8_t* FT_Mount_Cal_out);
int IMU_get_Status(IMU_Status_t* data_out);
void IMU_Status_on_receive(int (*callback)(IMU_Status_t* data));

int MCR_decode_GeneralReport_s(const uint8_t* bytes, size_t length, MCR_GeneralReport_t* data_out);
int MCR_decode_GeneralReport(const uint8_t* bytes, size_t length, uint8_t* SDC_IN_out, uint8_t* SDC_MSCB_out, uint8_t* SDC_MPCB_out, uint8_t* SDC_HVC_out, uint8_t* SDC_MPCA_out, uint8_t* SDC_MSCA_out, uint8_t* DISCH_out, uint8_t* POA_out, uint8_t* POA_PS_out, uint8_t* POB_out, uint8_t* POB_PS_out, uint8_t* PWMA_out, uint8_t* FWA_out, uint8_t* GENA_out, uint8_t* DIRA_out, uint8_t* PWMB_out, uint8_t* FWB_out, uint8_t* GENB_out, uint8_t* DIRB_out, uint8_t* HB_out);
int MCR_get_GeneralReport(MCR_GeneralReport_t* data_out);
void MCR_GeneralReport_on_receive(int (*callback)(MCR_GeneralReport_t* data));

int MCR_decode_ThermalMeasuresA_s(const uint8_t* bytes, size_t length, MCR_ThermalMeasuresA_t* data_out);
int MCR_decode_ThermalMeasuresA(const uint8_t* bytes, size_t length, uint8_t* TIGBT_out, uint8_t* TIGBTJ_out, uint8_t* TMOTCON_out, uint8_t* TMOTSEN_out, uint8_t* TMOTWIN_out, uint8_t* TCAP_out, uint8_t* TMOTI2T_out);
int MCR_get_ThermalMeasuresA(MCR_ThermalMeasuresA_t* data_out);
void MCR_ThermalMeasuresA_on_receive(int (*callback)(MCR_ThermalMeasuresA_t* data));

int MCR_decode_ThermalMeasuresB_s(const uint8_t* bytes, size_t length, MCR_ThermalMeasuresB_t* data_out);
int MCR_decode_ThermalMeasuresB(const uint8_t* bytes, size_t length, uint8_t* TIGBT_out, uint8_t* TIGBTJ_out, uint8_t* TMOTCON_out, uint8_t* TMOTSEN_out, uint8_t* TMOTWIN_out, uint8_t* TCAP_out, uint8_t* TMOTI2T_out);
int MCR_get_ThermalMeasuresB(MCR_ThermalMeasuresB_t* data_out);
void MCR_ThermalMeasuresB_on_receive(int (*callback)(MCR_ThermalMeasuresB_t* data));

int VDCU_decode_Status_s(const uint8_t* bytes, size_t length, VDCU_Status_t* data_out);
int VDCU_decode_Status(const uint8_t* bytes, size_t length, enum VDCU_VDCU_State* State_out, uint8_t* TV_ENABLED_out, uint8_t* TC_ENABLED_out, uint8_t* YC_ENABLED_out, uint8_t* FT_Dis_Cal_out, uint8_t* FT_Sensor_out, uint8_t* TEMP_derating_out, uint8_t* ACP_derating_out, uint8_t* Disch_ACT_out, uint8_t* Reverse_ACT_out, uint8_t* TC_ACT_out, uint8_t* YC_ACT_out);
int VDCU_get_Status(VDCU_Status_t* data_out);
void VDCU_Status_on_receive(int (*callback)(VDCU_Status_t* data));

int VDCU_decode_Controller_s(const uint8_t* bytes, size_t length, VDCU_Controller_t* data_out);
int VDCU_decode_Controller(const uint8_t* bytes, size_t length, int16_t* TRQ_Req_out, uint8_t* TRQ_Dist_Long_out, int8_t* TRQ_Dist_Lat_out, int16_t* TRQ_Yaw_Req_out, int16_t* YawRate_Ref_out);
int VDCU_get_Controller(VDCU_Controller_t* data_out);
void VDCU_Controller_on_receive(int (*callback)(VDCU_Controller_t* data));

int VDCU_decode_Body_s(const uint8_t* bytes, size_t length, VDCU_Body_t* data_out);
int VDCU_decode_Body(const uint8_t* bytes, size_t length, int16_t* Speed_Ref_out, int8_t* Slip_angle_out, int8_t* Roll_out, int8_t* Pitch_out, int8_t* Heave_out);
int VDCU_get_Body(VDCU_Body_t* data_out);
void VDCU_Body_on_receive(int (*callback)(VDCU_Body_t* data));

int VDCU_decode_WheelFz_s(const uint8_t* bytes, size_t length, VDCU_WheelFz_t* data_out);
int VDCU_decode_WheelFz(const uint8_t* bytes, size_t length, uint16_t* FR_out, uint16_t* FL_out, uint16_t* RR_out, uint16_t* RL_out);
int VDCU_get_WheelFz(VDCU_WheelFz_t* data_out);
void VDCU_WheelFz_on_receive(int (*callback)(VDCU_WheelFz_t* data));

int VDCU_send_Param_s(const VDCU_Param_t* data);
int VDCU_send_Param(enum VDCU_VDCU_Param Param_ID, int16_t Param, uint8_t SEQ_PARAM, uint8_t SEQ);
int VDCU_Param_need_to_send(void);

int VDCU_decode_Param_ACK_s(const uint8_t* bytes, size_t length, VDCU_Param_ACK_t* data_out);
int VDCU_decode_Param_ACK(const uint8_t* bytes, size_t length, uint8_t* Param_ID_out, int16_t* Param_out, uint8_t* SEQ_Param_out);
int VDCU_get_Param_ACK(VDCU_Param_ACK_t* data_out);
void VDCU_Param_ACK_on_receive(int (*callback)(VDCU_Param_ACK_t* data));

int VDCU_send_REQCalibDis_s(const VDCU_REQCalibDis_t* data);
int VDCU_send_REQCalibDis(enum VDCU_CAL_DisIndex which, int16_t load, int16_t scale);

int VDCU_decode_SOC_s(const uint8_t* bytes, size_t length, VDCU_SOC_t* data_out);
int VDCU_decode_SOC(const uint8_t* bytes, size_t length, uint8_t* SOC_out);
int VDCU_get_SOC(VDCU_SOC_t* data_out);
void VDCU_SOC_on_receive(int (*callback)(VDCU_SOC_t* data));

#ifdef __cplusplus
}
#endif

#endif
