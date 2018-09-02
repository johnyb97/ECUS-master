//by xorly

#ifndef _CANDB_STRUCTURE
	#define _CANDB_STRUCTURE
	#include <inttypes.h>
	#include <stdbool.h>

	typedef struct{
		const uint8_t id;
		const char *const text;
	}candb_descrition_map_t;

	typedef struct{
		const char *const name;
		const char *const comments;
	}description_t;

	typedef struct{
		const uint16_t value;
		const description_t description;
	}enum_element_t;

	typedef struct{
		const enum_element_t *const element;
	}enum_t;

	typedef union{
		uint32_t ui;
		int32_t si;
		float fl;
	}raw32_t ;

	typedef enum{
		CANDB_MSG_FIELD_TYPE_BOOL,
		CANDB_MSG_FIELD_TYPE_UINT,
		CANDB_MSG_FIELD_TYPE_INT,
		CANDB_MSG_FIELD_TYPE_FLOAT,
		CANDB_MSG_FIELD_TYPE_ENUM,
		CANDB_MSG_FIELD_TYPE_MUX,
	} candb_msg_field_type_t;

	struct candb_msg_field{
		const description_t description;
		const candb_msg_field_type_t type;
		const char *unit;
		const uint8_t bits;
		const uint8_t offset;
		const uint8_t count;
		uint32_t *const timestamp;
		const union{
			struct{
				const float min;
				const float max;
				const float factor;
				const float offset;
				raw32_t *const value;
			}num;
			struct{
				bool *const value;
			}bl;
			struct{
				const candb_descrition_map_t *const *const descriptions;
				uint16_t *const value;
			}en;
			struct{
				const struct candb_msg_field *const *const *const muxed_fields;
				const uint8_t min;
				const uint8_t max;
				uint8_t *const value;
			}mux;
		}type_specific;
	};

	typedef struct candb_msg_field candb_msg_field_t;

	struct candb_msg{
		uint32_t *const timestamp;
		const char *const sent_by;
		const candb_msg_field_t *const *const fields;
		void (**callback)(const struct candb_msg *msg);
		const description_t description;
		const uint16_t id;
		const uint16_t timeout;
		const uint16_t period;
		const uint8_t length;
	};

	typedef struct candb_msg candb_msg_t;
	typedef void(*candb_msg_callback_p)(const struct candb_msg *msg);

	extern const candb_msg_t  *const *const candb_messages;

	typedef enum{
		CANDB_ECUA_STATUS_FIELD_SDC_IN_OPEN=0, //Lead from ECUB (1 = open)
		CANDB_ECUA_STATUS_FIELD_SDC_HV_ILOCK=1, //True if HV interlock is closed
		CANDB_ECUA_STATUS_FIELD_SDC_IMD=2, //True if SDC is not broken by IMD
		CANDB_ECUA_STATUS_FIELD_SDC_AMS=3, //AMS = ECUA+BMS
		CANDB_ECUA_STATUS_FIELD_SDC_OUT=4, //SDC out to final stretch (BSPD etc...)
		CANDB_ECUA_STATUS_FIELD_SDC_END=5, //End of SDC (input to AIRS)
		CANDB_ECUA_STATUS_FIELD_LATCH_SDC_AMS=6, //HW latch engaged (caused by IMD or AMS)
		CANDB_ECUA_STATUS_FIELD_AIRSSTATE=7, //State of AIRs
		CANDB_ECUA_STATUS_FIELD_AIRS_ERRNO=8, //AIRs error code
		CANDB_ECUA_STATUS_FIELD_FT_ACP_OT=9, //Fault of ACP overtemperature
		CANDB_ECUA_STATUS_FIELD_FT_AIRS=10, //Fault of AIRs
		CANDB_ECUA_STATUS_FIELD_FT_DCDC=11, //Fault of DCDC GLV converter
		CANDB_ECUA_STATUS_FIELD_FT_FAN1=12, //FAN1 dead
		CANDB_ECUA_STATUS_FIELD_FT_FAN2=13, //FAN2 dead
		CANDB_ECUA_STATUS_FIELD_FT_FAN3=14, //FAN3 dead
		CANDB_ECUA_STATUS_FIELD_FT_HV_OV=15, //Fault HV overvoltage
		CANDB_ECUA_STATUS_FIELD_FT_HV_UV=16, //Fault HV undervoltage
		CANDB_ECUA_STATUS_FIELD_FT_GLV_UV=17, //Fault of GLV (undervoltage measurement)
		CANDB_ECUA_STATUS_FIELD_FT_GLV_OV=18, //Fault of GLV (overvoltage measurement)
		CANDB_ECUA_STATUS_FIELD_FT_AMS=19, //Internal ECUA/BMS faults
		CANDB_ECUA_STATUS_FIELD_FT_ANY=20, //If any error is present
		CANDB_ECUA_STATUS_FIELD_WARN_TEMP_CELL=21, //Warning for cell tempreature (near limits)
		CANDB_ECUA_STATUS_FIELD_WARN_TEMP_DCDC=22, //Warning for dc-dc temperature (near limits)
		CANDB_ECUA_STATUS_FIELD_WARN_TEMP_BAL=23, //Warning for balancer temperature (near limits)
		CANDB_ECUA_STATUS_FIELD_CHARGER_ATTACHED=24, //ACP is attached to charger?
		CANDB_ECUA_STATUS_FIELD_DCDC_GLV_EN=25, //24V power output is active
		CANDB_ECUA_STATUS_FIELD_FANS_EN=26, //Fans are active
		CANDB_ECUA_STATUS_FIELD_SEQ=27, //Message up counter for safety
	}candb_enum_ECUA_Status_FIELD_t;
	typedef enum{
		CANDB_ECUA_LIMITS_FIELD_PWR_OUT=0, //ACP output power maximum limit
		CANDB_ECUA_LIMITS_FIELD_PWR_IN=1, //ACP input power maximum limit
	}candb_enum_ECUA_Limits_FIELD_t;
	typedef enum{
		CANDB_ECUA_ACPMEAS_FIELD_VOLT_HV_IN=0, //HV before AIRs
		CANDB_ECUA_ACPMEAS_FIELD_VOLT_HV_OUT=1, //HV at output of ACP
		CANDB_ECUA_ACPMEAS_FIELD_CURR_HV_OUT=2, //HV Current (positive if energy flowing outwards)
		CANDB_ECUA_ACPMEAS_FIELD_CURR_DCDC_OUT=3, //LV Current
		CANDB_ECUA_ACPMEAS_FIELD_CURR_FANS=4, //Fans current
	}candb_enum_ECUA_ACPMeas_FIELD_t;
	typedef enum{
		CANDB_ECUA_ESTIMATION_FIELD_CHARGE_OUT=0, //Charge lost in motoring
		CANDB_ECUA_ESTIMATION_FIELD_CHARGE_IN=1, //Charge reccuperated
		CANDB_ECUA_ESTIMATION_FIELD_SOC=2, //State of charge estimation
	}candb_enum_ECUA_Estimation_FIELD_t;
	typedef enum{
		CANDB_ECUA_BALANCINGSTATUS_FIELD_ACTIVE=0, //description not provided
		CANDB_ECUA_BALANCINGSTATUS_FIELD_CELLINDEX=1, //description not provided
	}candb_enum_ECUA_BalancingStatus_FIELD_t;
	typedef enum{
		CANDB_ECUA_BALANCINGSTATUS2_FIELD_VTARGET=0, //description not provided
		CANDB_ECUA_BALANCINGSTATUS2_FIELD_ALLOWEDVDIFF=1, //description not provided
		CANDB_ECUA_BALANCINGSTATUS2_FIELD_TIMESINCELASTDCHG=2, //description not provided
	}candb_enum_ECUA_BalancingStatus2_FIELD_t;
	typedef enum{
		CANDB_ECUA_AMSVOLTS_FIELD_STACKID=0, //Index of stack in ACP - mx
		CANDB_ECUA_AMSVOLTS_FIELD_SETID=1, //Index of parallel cell group measurement  in stack - mx
		CANDB_ECUA_AMSVOLTS_FIELD_TIMESTAMP=2, //Timestamp of cell measurements
		CANDB_ECUA_AMSVOLTS_FIELD_VOLT=3, //Voltages of cell sets in parralel
	}candb_enum_ECUA_AMSVolts_FIELD_t;
	typedef enum{
		CANDB_ECUA_AMSTEMP_FIELD_STACKID=0, //Index of stack in ACP - mx
		CANDB_ECUA_AMSTEMP_FIELD_SETID=1, //Index of measurement in stack - mx
		CANDB_ECUA_AMSTEMP_FIELD_TEMP=2, //Temperature measurement
	}candb_enum_ECUA_AMSTemp_FIELD_t;
	typedef enum{
		CANDB_ECUA_AMSSTACK_FIELD_STACKID=0, //Index of stack in ACP - multiplexed
		CANDB_ECUA_AMSSTACK_FIELD_VOLT_MIN=1, //Maximum AMS stack cell voltage
		CANDB_ECUA_AMSSTACK_FIELD_VOLT_MAX=2, //Minimum AMS stack cell voltage
		CANDB_ECUA_AMSSTACK_FIELD_TEMP_MAX=3, //Maximum AMS stack cell temperature
		CANDB_ECUA_AMSSTACK_FIELD_TEMP_MIN=4, //Minimum AMS stack cell temperature
	}candb_enum_ECUA_AMSStack_FIELD_t;
	typedef enum{
		CANDB_ECUA_AMSOVERALL_FIELD_VOLT_MAX=0, //Maximum cell voltage over ACP
		CANDB_ECUA_AMSOVERALL_FIELD_VOLT_MIN=1, //Minimum cell voltage over ACP
		CANDB_ECUA_AMSOVERALL_FIELD_TEMP_MIN=2, //Maximum cell temperature over ACP
		CANDB_ECUA_AMSOVERALL_FIELD_TEMP_MAX=3, //Minimum cell temperature over ACP
		CANDB_ECUA_AMSOVERALL_FIELD_TEMP_MAX_INDEX=4, //Maximum cell index
		CANDB_ECUA_AMSOVERALL_FIELD_VOLT_MIN_INDEX=5, //Minimum cell index
	}candb_enum_ECUA_AMSOverall_FIELD_t;
	typedef enum{
		CANDB_ECUA_VOLTAGES_FIELD_UIN=0, //Voltage on accumulator stacks
		CANDB_ECUA_VOLTAGES_FIELD_UOUT=1, //Voltage on AIRs outut
	}candb_enum_ECUA_Voltages_FIELD_t;
	typedef enum{
		CANDB_CCU_CHARGERHEARTBEAT_FIELD_HBPRMB=0, //preambula (magic number)
		CANDB_CCU_CHARGERHEARTBEAT_FIELD_READY=1, //1 of AIRs are closed correctly, zero otherwise
	}candb_enum_CCU_ChargerHeartbeat_FIELD_t;
	typedef enum{
		CANDB_ECUB_STATUS_FIELD_SDC_FRONT=0, //Shutdown circuit - Front
		CANDB_ECUB_STATUS_FIELD_SDC_SDBL=1, //Shutdown circuit - Shutdown button left
		CANDB_ECUB_STATUS_FIELD_SDC_SDBR=2, //Shutdown circuit - Shutdown button right
		CANDB_ECUB_STATUS_FIELD_SDC_HVD=3, //Shutdown circuit - High voltage disconnect
		CANDB_ECUB_STATUS_FIELD_SDC_BSPD=4, //Shutdown circuit - Brake plausibility device
		CANDB_ECUB_STATUS_FIELD_SDC_MCUR=5, //Shutdown circuit - Motor controller rear
		CANDB_ECUB_STATUS_FIELD_SDC_AMS=6, //Shutdown circuit - Accumulator management system
		CANDB_ECUB_STATUS_FIELD_SDC_TSMS=7, //Shutdown circuit - Tractive system master switch
		CANDB_ECUB_STATUS_FIELD_CARSTATE=8, //Current vehicle state
		CANDB_ECUB_STATUS_FIELD_CARSTATE_NOTREADY=9, //Reason for latest not-ready CarState
		CANDB_ECUB_STATUS_FIELD_POWERSOURCE=10, //Current powering source
		CANDB_ECUB_STATUS_FIELD_DET_MOD1=11, //Module 1 detected
		CANDB_ECUB_STATUS_FIELD_DET_MOD2=12, //Module 2 detected
		CANDB_ECUB_STATUS_FIELD_DET_MOD3=13, //Module 3 detected
		CANDB_ECUB_STATUS_FIELD_DET_MOD4=14, //Module 4 detected
		CANDB_ECUB_STATUS_FIELD_FT_PWR1_OT=15, //Fault temperature shutdown for driver on PWR_ECUF_EN, PWR_ECUA_EN
		CANDB_ECUB_STATUS_FIELD_FT_PWR2_OT=16, //Fault temperature shutdown for driver on PWR_ECUMF_EN, PWR_ECUMR_EN
		CANDB_ECUB_STATUS_FIELD_FT_PWR3_OT=17, //Fault temperature shutdown for driver on WP1_EN, WP2_EN
		CANDB_ECUB_STATUS_FIELD_FT_PWR4_OT=18, //Fault temperature shutdown for driver on EM, FAN3_EN
		CANDB_ECUB_STATUS_FIELD_FT_PWR5_OT=19, //Fault temperature shutdown for driver on FAN1_EN, FAN2_EN
		CANDB_ECUB_STATUS_FIELD_FT_L2_OT=20, //Fault temperature shutdown for driver on RTDS, SDB LED R i L, BrakeLight
		CANDB_ECUB_STATUS_FIELD_FT_ANY=21, //If any error present
		CANDB_ECUB_STATUS_FIELD_FT_L1_OT=22, //Fault temperature shutdown for driver on WS, AUX1,2,3
		CANDB_ECUB_STATUS_FIELD_FT_PWR_ECUF_OC=23, //Fault ECUF power (Short to VCC)
		CANDB_ECUB_STATUS_FIELD_FT_PWR_ECUA_OC=24, //Fault ECUA power (Short to VCC)
		CANDB_ECUB_STATUS_FIELD_FT_PWR_MCF_OC=25, //Fault MCF power (Short to VCC)
		CANDB_ECUB_STATUS_FIELD_FT_PWR_MCR_OC=26, //Fault MCR power (Short to VCC)
		CANDB_ECUB_STATUS_FIELD_FT_CAN1=27, //Fault of CAN Bus (CAN errors or controller mode is error)
		CANDB_ECUB_STATUS_FIELD_FT_CAN2=28, //Fault of CAN Bus (CAN errors or controller mode is error)
		CANDB_ECUB_STATUS_FIELD_PWR_ECUF_EN=29, //Power to ECUF enabled
		CANDB_ECUB_STATUS_FIELD_PWR_ECUA_EN=30, //Power to ECUA enabled
		CANDB_ECUB_STATUS_FIELD_PWR_MCUF_EN=31, //Power to MCUF enabled
		CANDB_ECUB_STATUS_FIELD_PWR_MCUR_EN=32, //Power to MCUR enabled
		CANDB_ECUB_STATUS_FIELD_PWR_EM_EN=33, //Power to Energy Meter enabled
		CANDB_ECUB_STATUS_FIELD_PWR_WP1_EN=34, //Power to Waterpump 1 enabled
		CANDB_ECUB_STATUS_FIELD_PWR_WP2_EN=35, //Power to Waterpump 2 enabled
		CANDB_ECUB_STATUS_FIELD_PWR_FAN1_EN=36, //Power to FAN1 enabled
		CANDB_ECUB_STATUS_FIELD_PWR_FAN2_EN=37, //Power to FAN2 enabled
		CANDB_ECUB_STATUS_FIELD_PWR_FAN3_EN=38, //Power to FAN3 enabled
		CANDB_ECUB_STATUS_FIELD_PWR_WS_EN=39, //Power to Wheel speed sensor enabled
		CANDB_ECUB_STATUS_FIELD_PWR_AUX1_EN=40, //Power to aux1 enabled aka LIDK1 (Low I Don't Know #1)
		CANDB_ECUB_STATUS_FIELD_PWR_AUX2_EN=41, //Power to aux2 enabled aka LIDK2
		CANDB_ECUB_STATUS_FIELD_PWR_AUX3_EN=42, //Power to aux3 enabled aka LIDK3
		CANDB_ECUB_STATUS_FIELD_RTDS_EN=43, //Ready to drive sound enabled
		CANDB_ECUB_STATUS_FIELD_SDBR_LED_EN=44, //Shutdown button right led enabled
		CANDB_ECUB_STATUS_FIELD_SDBL_LED_EN=45, //Shutdown button left led enabled
		CANDB_ECUB_STATUS_FIELD_BRAKELIGHT_EN=46, //Brakelight enabled
		CANDB_ECUB_STATUS_FIELD_TSAL_OVERRIDE=47, //TSAL ""Test"" or ""Override"" totally not a hack enabled
		CANDB_ECUB_STATUS_FIELD_SEQ=48, //Message up counter for safety check
	}candb_enum_ECUB_Status_FIELD_t;
	typedef enum{
		CANDB_ECUB_WHEELSPEED_FIELD_WHR=0, //Wheel speed rear right
		CANDB_ECUB_WHEELSPEED_FIELD_WHL=1, //Wheel speed rear left
		CANDB_ECUB_WHEELSPEED_FIELD_TIMESTAMP=2, //Timestamp of measurement
		CANDB_ECUB_WHEELSPEED_FIELD_FT_WHR=3, //Fault of rear right wheel speed sensor
		CANDB_ECUB_WHEELSPEED_FIELD_FT_WHL=4, //Fault of rear left wheel speed sensor
		CANDB_ECUB_WHEELSPEED_FIELD_SEQ=5, //Message up counter for safety check
	}candb_enum_ECUB_Wheelspeed_FIELD_t;
	typedef enum{
		CANDB_ECUB_GLV_AMS_FIELD_BATTSTATE=0, //GLV Battery status
		CANDB_ECUB_GLV_AMS_FIELD_FT_BATT=1, //GLV Battery fault (overvoltage, undervoltage, overcurrent, overtemperature)
		CANDB_ECUB_GLV_AMS_FIELD_FT_AMS=2, //GLV battery AMS fault
		CANDB_ECUB_GLV_AMS_FIELD_FT_CHARGER=3, //GLV battery Charger fault
		CANDB_ECUB_GLV_AMS_FIELD_VOLT=4, //GLV Battery voltage
		CANDB_ECUB_GLV_AMS_FIELD_CURR=5, //GLV Battery current
		CANDB_ECUB_GLV_AMS_FIELD_CELLID=6, //Voltage GLV battery mux
		CANDB_ECUB_GLV_AMS_FIELD_VOLT_CELL=7, //Battery cell voltage
		CANDB_ECUB_GLV_AMS_FIELD_TEMP_CELL=8, //Battery cell temperature
	}candb_enum_ECUB_GLV_AMS_FIELD_t;
	typedef enum{
		CANDB_ECUB_COOLING_FIELD_WP1=0, //Waterpump cooler circuit PWM duty
		CANDB_ECUB_COOLING_FIELD_WP2=1, //Waterpump cooler circuit PWM duty
		CANDB_ECUB_COOLING_FIELD_FAN1=2, //Cooler FAN in PWM duty
		CANDB_ECUB_COOLING_FIELD_FAN2=3, //Cooler FAN in PWM duty
		CANDB_ECUB_COOLING_FIELD_FAN3=4, //Cooler FAN in PWM duty
		CANDB_ECUB_COOLING_FIELD_WARN_MOT_FR_TEMP=5, //Warning - Motor temperature over nominal threshold
		CANDB_ECUB_COOLING_FIELD_WARN_MOT_FL_TEMP=6, //Warning - Motor temperature over nominal threshold
		CANDB_ECUB_COOLING_FIELD_WARN_MOT_RR_TEMP=7, //Warning - Motor temperature over nominal threshold
		CANDB_ECUB_COOLING_FIELD_WARN_MOT_RL_TEMP=8, //Warning - Motor temperature over nominal threshold
		CANDB_ECUB_COOLING_FIELD_WARN_MCU_FR_TEMP=9, //Warning - Motor controller temperature over nominal threshold
		CANDB_ECUB_COOLING_FIELD_WARN_MCU_FL_TEMP=10, //Warning - Motor controller temperature over nominal threshold
		CANDB_ECUB_COOLING_FIELD_WARN_MCU_RR_TEMP=11, //Warning - Motor controller temperature over nominal threshold
		CANDB_ECUB_COOLING_FIELD_WARN_MCU_RL_TEMP=12, //Warning - Motor controller temperature over nominal threshold
		CANDB_ECUB_COOLING_FIELD_WARN_BRAKE_RR_TEMP=13, //Warning - Brake temperature over nominal threshold
		CANDB_ECUB_COOLING_FIELD_WARN_BRAKE_RL_TEMP=14, //Warning - Brake temperature over nominal threshold
		CANDB_ECUB_COOLING_FIELD_FT_MOT_FR_OT=15, //Fault - motor overtemperature
		CANDB_ECUB_COOLING_FIELD_FT_MOT_FL_OT=16, //Fault - motor overtemperature
		CANDB_ECUB_COOLING_FIELD_FT_MOT_RR_OT=17, //Fault - motor overtemperature
		CANDB_ECUB_COOLING_FIELD_FT_MOT_RL_OT=18, //Fault - motor overtemperature
		CANDB_ECUB_COOLING_FIELD_FT_MCU_FR_OT=19, //Fault - motor controller overtemperature
		CANDB_ECUB_COOLING_FIELD_FT_MCU_FL_OT=20, //Fault - motor controller overtemperature
		CANDB_ECUB_COOLING_FIELD_FT_MCU_RR_OT=21, //Fault - motor controller overtemperature
		CANDB_ECUB_COOLING_FIELD_FT_MCU_RL_OT=22, //Fault - motor controller overtemperature
		CANDB_ECUB_COOLING_FIELD_FT_BRAKE_RR_OT=23, //Fault - brake overtemperature
		CANDB_ECUB_COOLING_FIELD_FT_BRAKE_RL_OT=24, //Fault - brake overtemperature
	}candb_enum_ECUB_Cooling_FIELD_t;
	typedef enum{
		CANDB_ECUB_POWER_DIST_FIELD_VOLT_DCDC=0, //DCDC power rail voltage
		CANDB_ECUB_POWER_DIST_FIELD_VOLT_SBOX=1, //Service box 24V input voltage
		CANDB_ECUB_POWER_DIST_FIELD_CURR_ECUF=2, //Current for ECUF
		CANDB_ECUB_POWER_DIST_FIELD_CURR_ECUA=3, //Current for ECUA
		CANDB_ECUB_POWER_DIST_FIELD_CURR_ECUMF=4, //Current for ECUMF
		CANDB_ECUB_POWER_DIST_FIELD_CURR_ECUMR=5, //Current for ECUMR
	}candb_enum_ECUB_Power_dist_FIELD_t;
	typedef enum{
		CANDB_ECUB_TEMPSUSPR_FIELD_BRAKECAL_RR=0, //Rear right brake caliper temperature
		CANDB_ECUB_TEMPSUSPR_FIELD_BRAKECAL_RL=1, //Rear left brake caliper temperature
		CANDB_ECUB_TEMPSUSPR_FIELD_TIREI_RR=2, //Rear right tire inboard temperature
		CANDB_ECUB_TEMPSUSPR_FIELD_TIREC_RR=3, //Rear right tire center temperature
		CANDB_ECUB_TEMPSUSPR_FIELD_TIREO_RR=4, //Rear right tire outboard temperature
		CANDB_ECUB_TEMPSUSPR_FIELD_TIREI_RL=5, //Rear left tire inboard temperature
		CANDB_ECUB_TEMPSUSPR_FIELD_TIREC_RL=6, //Rear left tire center temperature
		CANDB_ECUB_TEMPSUSPR_FIELD_TIREO_RL=7, //Rear left tire inboard temperature
	}candb_enum_ECUB_TEMPSuspR_FIELD_t;
	typedef enum{
		CANDB_ECUB_TEMPAUX_FIELD_COOLING1_NTC=0, //description not provided
		CANDB_ECUB_TEMPAUX_FIELD_COOLING2_NTC=1, //description not provided
		CANDB_ECUB_TEMPAUX_FIELD_COOLING3_NTC=2, //description not provided
		CANDB_ECUB_TEMPAUX_FIELD_COOLING4_NTC=3, //description not provided
	}candb_enum_ECUB_TEMPAux_FIELD_t;
	typedef enum{
		CANDB_ECUP_STATUS_FIELD_SDC_BOTS=0, //SDC is powered after BOTS
		CANDB_ECUP_STATUS_FIELD_FT_ANY=1, //If any error is present
		CANDB_ECUP_STATUS_FIELD_APPS_PLAUSIBLE=2, //Accelerator pedals plausible
		CANDB_ECUP_STATUS_FIELD_BPPC_LATCH=3, //Brake Pedal Plausibility Check (software bspd)
		CANDB_ECUP_STATUS_FIELD_BRAKEACTIVE=4, //Brake active (Signal mainly for brakelight)
		CANDB_ECUP_STATUS_FIELD_BRAKEACTIVE_BSPD=5, //Brake active for the purposes of BSPD
	}candb_enum_ECUP_Status_FIELD_t;
	typedef enum{
		CANDB_ECUP_PEDALS_FIELD_APPS_POS=0, //Normalized accelerator value
		CANDB_ECUP_PEDALS_FIELD_BRAKE_POS=1, //Normalized brake encoder value
		CANDB_ECUP_PEDALS_FIELD_FT_APPS_POS=2, //There is some error with sensor or calibration
		CANDB_ECUP_PEDALS_FIELD_FT_BRAKE_POS=3, //There is some error with sensor or calibration
		CANDB_ECUP_PEDALS_FIELD_SEQ=4, //Message counter for safety
	}candb_enum_ECUP_Pedals_FIELD_t;
	typedef enum{
		CANDB_ECUP_PRESSURE_FIELD_BRAKEF=0, //Brake front pressure
		CANDB_ECUP_PRESSURE_FIELD_BRAKER=1, //Brake rear pressure
		CANDB_ECUP_PRESSURE_FIELD_FT_BRAKEF=2, //Fault of brake pressure sensor front
		CANDB_ECUP_PRESSURE_FIELD_FT_BRAKER=3, //Fault of brake pressure sensor rear
	}candb_enum_ECUP_Pressure_FIELD_t;
	typedef enum{
		CANDB_ECUP_DIAGPOS_FIELD_ACC1_RAW=0, //Raw read value of accelerator position sensor 1
		CANDB_ECUP_DIAGPOS_FIELD_ACC2_RAW=1, //Raw read value of accelerator position sensor 2
		CANDB_ECUP_DIAGPOS_FIELD_BRKPOS_RAW=2, //Raw read value of brake position sensor
		CANDB_ECUP_DIAGPOS_FIELD_BPPC_RAW=3, //Raw calculated value of brake pedal plausability check (BPPC)
	}candb_enum_ECUP_DiagPos_FIELD_t;
	typedef enum{
		CANDB_ECUP_DIAGPRESSURE_FIELD_BRAKEPRESSFRAW=0, //Front brake sensor raw data from ADC
		CANDB_ECUP_DIAGPRESSURE_FIELD_BRAKEPRESSRRAW=1, //Rear brake sensor raw data from ADC
	}candb_enum_ECUP_DiagPressure_FIELD_t;
	typedef enum{
		CANDB_ECUP_REQCALIBPEDAL_FIELD_WHICH=0, //Calibration index to set
	}candb_enum_ECUP_REQCalibPedal_FIELD_t;
	typedef enum{
		CANDB_VDCU_STATUS_FIELD_STATE=0, //VDCU State machine
		CANDB_VDCU_STATUS_FIELD_TV_ENABLED=1, //Torque vectoring enabled
		CANDB_VDCU_STATUS_FIELD_TC_ENABLED=2, //Slip ratio control enabled (traction control)
		CANDB_VDCU_STATUS_FIELD_YC_ENABLED=3, //Yaw controller enabled
		CANDB_VDCU_STATUS_FIELD_FT_DIS_CAL=4, //Fault of displacement sensor calibration
		CANDB_VDCU_STATUS_FIELD_FT_SENSOR=5, //description not provided
		CANDB_VDCU_STATUS_FIELD_TEMP_DERATING=6, //Derating due to components temperature
		CANDB_VDCU_STATUS_FIELD_ACP_DERATING=7, //Derating due to ACP limits
		CANDB_VDCU_STATUS_FIELD_DISCH_ACT=8, //Discharge is active
		CANDB_VDCU_STATUS_FIELD_REVERSE_ACT=9, //Reverse is activated
		CANDB_VDCU_STATUS_FIELD_TC_ACT=10, //Slip ratio control is limiting torque
		CANDB_VDCU_STATUS_FIELD_YC_ACT=11, //Yaw controller is producing yaw torque
	}candb_enum_VDCU_Status_FIELD_t;
	typedef enum{
		CANDB_VDCU_SOC_FIELD_SOC=0, //SOC of ACP
	}candb_enum_VDCU_SOC_FIELD_t;
	typedef enum{
		CANDB_VDCU_PARAM_FIELD_PARAM_ID=0, //Parameter multiplexer
		CANDB_VDCU_PARAM_FIELD_PARAM=1, //Parameter data signal
		CANDB_VDCU_PARAM_FIELD_SEQ_PARAM=2, //Up counter for every corresponding parameter change
		CANDB_VDCU_PARAM_FIELD_SEQ=3, //Message up counter for safety
	}candb_enum_VDCU_Param_FIELD_t;
	typedef enum{
		CANDB_VDCU_REQCALIBDIS_FIELD_WHICH=0, //1-FR, 2-FL, 3-RR, 4-RL
		CANDB_VDCU_REQCALIBDIS_FIELD_LOAD=1, //Measured wheel load at scales on water level surface
		CANDB_VDCU_REQCALIBDIS_FIELD_SCALE=2, //???
	}candb_enum_VDCU_REQCalibDis_FIELD_t;
	typedef enum{
		CANDB_VDCU_CONTROLLER_FIELD_TRQ_REQ=0, //Torque request overal
		CANDB_VDCU_CONTROLLER_FIELD_TRQ_DIST_LONG=1, //Longitudinal torque distribution overall
		CANDB_VDCU_CONTROLLER_FIELD_TRQ_DIST_LAT=2, //Lateral torque distribution overall
		CANDB_VDCU_CONTROLLER_FIELD_TRQ_YAW_REQ=3, //Yaw torque request overall
		CANDB_VDCU_CONTROLLER_FIELD_YAWRATE_REF=4, //YawRate reference value
	}candb_enum_VDCU_Controller_FIELD_t;
	typedef enum{
		CANDB_VDCU_BODY_FIELD_SPEED_REF=0, //Reference speed estimated
		CANDB_VDCU_BODY_FIELD_SLIP_ANGLE=1, //Slip angle
		CANDB_VDCU_BODY_FIELD_ROLL=2, //Roll angle relative to road
		CANDB_VDCU_BODY_FIELD_PITCH=3, //Pitch angle relative to road
		CANDB_VDCU_BODY_FIELD_HEAVE=4, //Heave angle relative to road
	}candb_enum_VDCU_Body_FIELD_t;
	typedef enum{
		CANDB_VDCU_WHEELFZ_FIELD_FR=0, //FR Wheel load calibrated
		CANDB_VDCU_WHEELFZ_FIELD_FL=1, //FL Wheel load calibrated
		CANDB_VDCU_WHEELFZ_FIELD_RR=2, //RR Wheel load calibrated
		CANDB_VDCU_WHEELFZ_FIELD_RL=3, //RL Wheel load calibrated
	}candb_enum_VDCU_WheelFz_FIELD_t;
	typedef enum{
		CANDB_VDCU_PARAM_ACK_FIELD_PARAM_ID=0, //Parameter multiplexer
		CANDB_VDCU_PARAM_ACK_FIELD_PARAM=1, //Parameter used data signal
		CANDB_VDCU_PARAM_ACK_FIELD_SEQ_PARAM=2, //Up counter for every corresponding parameter change acknowledgement
	}candb_enum_VDCU_Param_ACK_FIELD_t;
	typedef enum{
		CANDB_VDCU_LONGSLIP_FIELD_FR=0, //Longitudinal wheel slip FR
		CANDB_VDCU_LONGSLIP_FIELD_FL=1, //Longitudinal wheel slip FL
		CANDB_VDCU_LONGSLIP_FIELD_RR=2, //Longitudinal wheel slip RR
		CANDB_VDCU_LONGSLIP_FIELD_RL=3, //Longitudinal wheel slip RL
	}candb_enum_VDCU_LongSlip_FIELD_t;
	typedef enum{
		CANDB_VDCU_SLIPANGLE_FIELD_FR=0, //Slip angle on FR wheel
		CANDB_VDCU_SLIPANGLE_FIELD_FL=1, //Slip angle on FL wheel
		CANDB_VDCU_SLIPANGLE_FIELD_RR=2, //Slip angle on RR wheel
		CANDB_VDCU_SLIPANGLE_FIELD_RL=3, //Slip angle on RL wheel
	}candb_enum_VDCU_SlipAngle_FIELD_t;
	typedef enum{
		CANDB_ECUF_STATUS_FIELD_SDC_SDBC=0, //Shutdown circuit from SDB_Cockpit
		CANDB_ECUF_STATUS_FIELD_SDC_INERTIA=1, //Inertia switch shutdown circuit
		CANDB_ECUF_STATUS_FIELD_SDC_FWIL=2, //Front Wheel Interlock (Connetore Italiano Supreme)
		CANDB_ECUF_STATUS_FIELD_PWR_ECUP_EN=3, //Power to ECUP is enabled
		CANDB_ECUF_STATUS_FIELD_PWR_ECUG_EN=4, //Power to ECUG is enabled
		CANDB_ECUF_STATUS_FIELD_PWR_DTLG_EN=5, //Power to DTLG is enabled
		CANDB_ECUF_STATUS_FIELD_PWR_ECUS_EN=6, //Power to ECUS is enabled
		CANDB_ECUF_STATUS_FIELD_PWR_DASH_EN=7, //Power to Dash is enabled
		CANDB_ECUF_STATUS_FIELD_PWR_FAN_BRAKEF_EN=8, //Power to front brake fans is enabled
		CANDB_ECUF_STATUS_FIELD_WARN_BRAKE_FR_TEMP=9, //Warning - Brake temperature over nominal threshold
		CANDB_ECUF_STATUS_FIELD_WARN_BRAKE_FL_TEMP=10, //Warning - Brake temperature over nominal threshold
		CANDB_ECUF_STATUS_FIELD_FT_PWR_ECUP=11, //ECUP enabled but no current is drawn
		CANDB_ECUF_STATUS_FIELD_FT_PWR_ECUG=12, //ECUG enabled but no current is drawn
		CANDB_ECUF_STATUS_FIELD_FT_PWR_ECUS=13, //ECUS enabled but no current is drawn
		CANDB_ECUF_STATUS_FIELD_FT_PWR_DTLG=14, //DTLG enabled but no current is drawn
		CANDB_ECUF_STATUS_FIELD_FT_PWR_DASH=15, //DASH enabled but no current is drawn
		CANDB_ECUF_STATUS_FIELD_FT_PWR_FAN_BRAKEF=16, //FAN enabled but no current is drawn
		CANDB_ECUF_STATUS_FIELD_FT_STW_SENSOR=17, //STW sensor disconnected or destroyed
		CANDB_ECUF_STATUS_FIELD_FT_STW_CAL=18, //Fault of steering wheel calibration
		CANDB_ECUF_STATUS_FIELD_FT_DISFR=19, //Fault of suspension displacement sensor FR
		CANDB_ECUF_STATUS_FIELD_FT_DISFL=20, //Fault of suspension displacement sensor FL
		CANDB_ECUF_STATUS_FIELD_FT_DISRR=21, //Fault of suspension displacement sensor RR
		CANDB_ECUF_STATUS_FIELD_FT_DISRL=22, //Fault of suspension displacement sensor RL
		CANDB_ECUF_STATUS_FIELD_FT_DISFR_CAL=23, //Fault of suspension displacement sensor FR calibration
		CANDB_ECUF_STATUS_FIELD_FT_DISFL_CAL=24, //Fault of suspension displacement sensor FL calibration
		CANDB_ECUF_STATUS_FIELD_FT_DISRR_CAL=25, //Fault of suspension displacement sensor RR calibration
		CANDB_ECUF_STATUS_FIELD_FT_DISRL_CAL=26, //Fault of suspension displacement sensor RL calibration
		CANDB_ECUF_STATUS_FIELD_FT_BRAKE_FR_OT=27, //Fault - brake overtemperature
		CANDB_ECUF_STATUS_FIELD_FT_BRAKE_FL_OT=28, //Fault - brake overtemperature
		CANDB_ECUF_STATUS_FIELD_VOLT_GLV_IN=29, //GLV Voltage at ECUF input
	}candb_enum_ECUF_Status_FIELD_t;
	typedef enum{
		CANDB_ECUF_DASHBOARD_FIELD_TSON=0, //1-pressed / 0-not pressed
		CANDB_ECUF_DASHBOARD_FIELD_START=1, //1-pressed / 0-not pressed
		CANDB_ECUF_DASHBOARD_FIELD_WP_ON=2, //Waterpump override switch (SW1)
		CANDB_ECUF_DASHBOARD_FIELD_TCS_ON=3, //Traction control switch (SW2)
		CANDB_ECUF_DASHBOARD_FIELD_YC_ON=4, //Yaw control stabilization switch (SW3)
		CANDB_ECUF_DASHBOARD_FIELD_AMBIENTLIGHT=5, //Ambient light level
		CANDB_ECUF_DASHBOARD_FIELD_AMBIENTTEMP=6, //Ambient temperature
	}candb_enum_ECUF_Dashboard_FIELD_t;
	typedef enum{
		CANDB_ECUF_STW_FIELD_ANGLE=0, //Steering wheel angle. Left positive
		CANDB_ECUF_STW_FIELD_ANGULARSPEED=1, //Steering wheel angularspeed. Left positive
		CANDB_ECUF_STW_FIELD_FT_STW=2, //Steering wheel measurement fault
		CANDB_ECUF_STW_FIELD_SEQ=3, //Message up counter for safety
	}candb_enum_ECUF_STW_FIELD_t;
	typedef enum{
		CANDB_ECUF_DISSUSP_FIELD_FR=0, //Displacement of front right spring
		CANDB_ECUF_DISSUSP_FIELD_FL=1, //Displacement of front left spring
		CANDB_ECUF_DISSUSP_FIELD_RR=2, //Displacement of rear right spring
		CANDB_ECUF_DISSUSP_FIELD_RL=3, //Displacement of rear left spring
	}candb_enum_ECUF_DISSusp_FIELD_t;
	typedef enum{
		CANDB_ECUF_TEMPSUSPF_FIELD_BRAKECAL_FR=0, //Front right brake caliper temperature
		CANDB_ECUF_TEMPSUSPF_FIELD_BRAKECAL_FL=1, //Front left brake caliper temperature
		CANDB_ECUF_TEMPSUSPF_FIELD_TIREI_FR=2, //Front right tire inboard temperature
		CANDB_ECUF_TEMPSUSPF_FIELD_TIREC_FR=3, //Front right tire center temperature
		CANDB_ECUF_TEMPSUSPF_FIELD_TIREO_FR=4, //Front right tire outboard temperature
		CANDB_ECUF_TEMPSUSPF_FIELD_TIREI_FL=5, //Front left tire inboard  temperature
		CANDB_ECUF_TEMPSUSPF_FIELD_TIREC_FL=6, //Front left tire center temperature
		CANDB_ECUF_TEMPSUSPF_FIELD_TIREO_FL=7, //Front left tire outboard temperature
	}candb_enum_ECUF_TEMPSuspF_FIELD_t;
	typedef enum{
		CANDB_ECUF_REQCALIBSTW_FIELD_WHICH=0, //Which steering wheel position to calibrate
	}candb_enum_ECUF_REQCalibSTW_FIELD_t;
	typedef enum{
		CANDB_MCF_GENERALREPORT_FIELD_SDC_IN=0, //Shutdown circuit - point at input.
		CANDB_MCF_GENERALREPORT_FIELD_SDC_MSCB=1, //Shutdown circuit - point after channel B motor's sensor connector.
		CANDB_MCF_GENERALREPORT_FIELD_SDC_MPCB=2, //Shutdown circuit - point after channel B motor's power connector.
		CANDB_MCF_GENERALREPORT_FIELD_SDC_HVC=3, //Shutdown circuit - point after high voltage connector.
		CANDB_MCF_GENERALREPORT_FIELD_SDC_MPCA=4, //Shutdown circuit - point after channel A motor's power connector.
		CANDB_MCF_GENERALREPORT_FIELD_SDC_MSCA=5, //Shutdown circuit - point after channel A motor's sensor connector.
		CANDB_MCF_GENERALREPORT_FIELD_DISCH=6, //True means discharge resistor is connected.
		CANDB_MCF_GENERALREPORT_FIELD_POA=7, //True means active auxiliary power output channel A.
		CANDB_MCF_GENERALREPORT_FIELD_POA_PS=8, //Power supply for POA. log.1 = 12V, log.0 = input voltage (24V).
		CANDB_MCF_GENERALREPORT_FIELD_POB=9, //True means active auxiliary power output channel B.
		CANDB_MCF_GENERALREPORT_FIELD_POB_PS=10, //Power supply for POB. log.1 = 12V, log.0 = input voltage (24V).
		CANDB_MCF_GENERALREPORT_FIELD_PWMA=11, //True means channel A PWM is active.
		CANDB_MCF_GENERALREPORT_FIELD_FWA=12, //True means field weakening is allowed for channel A.
		CANDB_MCF_GENERALREPORT_FIELD_GENA=13, //True means generation mode is allowed for channel A.
		CANDB_MCF_GENERALREPORT_FIELD_DIRA=14, //Default direction for positive requests values. 
		CANDB_MCF_GENERALREPORT_FIELD_PWMB=15, //True means channel B PWM is active.
		CANDB_MCF_GENERALREPORT_FIELD_FWB=16, //True means field weakening is allowed for channel B.
		CANDB_MCF_GENERALREPORT_FIELD_GENB=17, //True means generation mode is allowed for channel B.
		CANDB_MCF_GENERALREPORT_FIELD_DIRB=18, //Default direction for positive requests values. 
		CANDB_MCF_GENERALREPORT_FIELD_HB=19, //Heart beat.
	}candb_enum_MCF_GeneralReport_FIELD_t;
	typedef enum{
		CANDB_MCF_THERMALMEASURESA_FIELD_TIGBT=0, //Temperature of IGBT's heat sink.
		CANDB_MCF_THERMALMEASURESA_FIELD_TIGBTJ=1, //Temperature estimation of IGBT chip.
		CANDB_MCF_THERMALMEASURESA_FIELD_TMOTCON=2, //Temperature of motor's connector.
		CANDB_MCF_THERMALMEASURESA_FIELD_TMOTSEN=3, //Temperature of motor's temp. sensor.
		CANDB_MCF_THERMALMEASURESA_FIELD_TMOTWIN=4, //Temperature estimation of motor's winding.
		CANDB_MCF_THERMALMEASURESA_FIELD_TCAP=5, //Temperature of capacitor bank.
		CANDB_MCF_THERMALMEASURESA_FIELD_TMOTI2T=6, //Motor performance capacity utilization rate.
	}candb_enum_MCF_ThermalMeasuresA_FIELD_t;
	typedef enum{
		CANDB_MCF_THERMALMEASURESB_FIELD_TIGBT=0, //Temperature of IGBT's heat sink.
		CANDB_MCF_THERMALMEASURESB_FIELD_TIGBTJ=1, //Temperature estimation of IGBT chip.
		CANDB_MCF_THERMALMEASURESB_FIELD_TMOTCON=2, //Temperature of motor's connector.
		CANDB_MCF_THERMALMEASURESB_FIELD_TMOTSEN=3, //Temperature of motor's temp. sensor.
		CANDB_MCF_THERMALMEASURESB_FIELD_TMOTWIN=4, //Temperature estimation of motor's winding.
		CANDB_MCF_THERMALMEASURESB_FIELD_TCAP=5, //Temperature of capacitor bank.
		CANDB_MCF_THERMALMEASURESB_FIELD_TMOTI2T=6, //Motor performance capacity utilization rate.
	}candb_enum_MCF_ThermalMeasuresB_FIELD_t;
	typedef enum{
		CANDB_MCF_CHANNELMEASURESA_FIELD_SPEED=0, //Speed of motor.
		CANDB_MCF_CHANNELMEASURESA_FIELD_TORQUE=1, //Torque of motor.
		CANDB_MCF_CHANNELMEASURESA_FIELD_PWRIN=2, //Channel's input power consumption.
		CANDB_MCF_CHANNELMEASURESA_FIELD_VDC=3, //Input voltage DC.
	}candb_enum_MCF_ChannelMeasuresA_FIELD_t;
	typedef enum{
		CANDB_MCF_CHANNELMEASURESB_FIELD_SPEED=0, //Speed of motor.
		CANDB_MCF_CHANNELMEASURESB_FIELD_TORQUE=1, //Torque of motor.
		CANDB_MCF_CHANNELMEASURESB_FIELD_PWRIN=2, //Channel's input power consumption.
		CANDB_MCF_CHANNELMEASURESB_FIELD_VDC=3, //Input voltage DC.
	}candb_enum_MCF_ChannelMeasuresB_FIELD_t;
	typedef enum{
		CANDB_MCF_REVOLUTIONSA_FIELD_TA_FWD=0, //Turn Angle in forward direction.
		CANDB_MCF_REVOLUTIONSA_FIELD_TA_RVS=1, //Turn Angle in reverse direction.
	}candb_enum_MCF_RevolutionsA_FIELD_t;
	typedef enum{
		CANDB_MCF_REVOLUTIONSB_FIELD_TA_FWD=0, //Turn Angle in forward direction.
		CANDB_MCF_REVOLUTIONSB_FIELD_TA_RVS=1, //Turn Angle in reverse direction.
	}candb_enum_MCF_RevolutionsB_FIELD_t;
	typedef enum{
		CANDB_MCF_UDQIDQA_FIELD_UD=0, //Output voltage (direct component) to input voltage (DC) ratio. Amplitude value.
		CANDB_MCF_UDQIDQA_FIELD_UQ=1, //Output voltage (quadrature component) to input voltage (DC) ratio. Amplitude value.
		CANDB_MCF_UDQIDQA_FIELD_ID=2, //Output current (direct component), Amplitude value.
		CANDB_MCF_UDQIDQA_FIELD_IQ=3, //Output current (quadrature component), Amplitude value.
	}candb_enum_MCF_UdqIdqA_FIELD_t;
	typedef enum{
		CANDB_MCF_UDQIDQB_FIELD_UD=0, //Output voltage (direct component) to input voltage (DC) ratio. Amplitude value.
		CANDB_MCF_UDQIDQB_FIELD_UQ=1, //Output voltage (quadrature component) to input voltage (DC) ratio. Amplitude value.
		CANDB_MCF_UDQIDQB_FIELD_ID=2, //Output current (direct component), Amplitude value.
		CANDB_MCF_UDQIDQB_FIELD_IQ=3, //Output current (quadrature component), Amplitude value.
	}candb_enum_MCF_UdqIdqB_FIELD_t;
	typedef enum{
		CANDB_MCF_FAULTSA_FIELD_FT_IPM=0, //Intelligent Power Module's error (Overcurrent / Overtemperature / Undervoltage).
		CANDB_MCF_FAULTSA_FIELD_FT_HV_UV=1, //High voltage undervoltage.
		CANDB_MCF_FAULTSA_FIELD_FT_HV_OV=2, //High voltage overvoltage.
		CANDB_MCF_FAULTSA_FIELD_FT_CSU_CALND=3, //Current sensor U calibration needed (offset drifted).
		CANDB_MCF_FAULTSA_FIELD_FT_CSU_FAIL=4, //Current sensor U failure (saturation for no reason / huge drift of offset).
		CANDB_MCF_FAULTSA_FIELD_FT_CSW_CALND=5, //Current sensor W calibration needed (offset drifted).
		CANDB_MCF_FAULTSA_FIELD_FT_CSW_FAIL=6, //Current sensor W failure (saturation for no reason / huge drift of offset).
		CANDB_MCF_FAULTSA_FIELD_FT_OC=7, //Overcurrent peak measured by current sensor.
		CANDB_MCF_FAULTSA_FIELD_FT_RES_FAIL=8, //Resolver failure (not connected or interrupted / huge offset or gain).
		CANDB_MCF_FAULTSA_FIELD_FT_RES_CALND=9, //Resolver calibration needed (sin/cos offset or gain drifted).
		CANDB_MCF_FAULTSA_FIELD_FT_RES_POSSTEP=10, //Resolver evaluated angle big step (noise / connection / defect).
		CANDB_MCF_FAULTSA_FIELD_FT_TMOT_FAIL=11, //Motor temperature sensor not connected.
		CANDB_MCF_FAULTSA_FIELD_FT_TMOT_OR=12, //Temperature over range of motor temperature sensor.
		CANDB_MCF_FAULTSA_FIELD_FT_TIGBT_FAIL=13, //IGBT's heat sink temperature sensor not connected.
		CANDB_MCF_FAULTSA_FIELD_FT_TIGBT_OR=14, //Temperature over range of IGBT's heat sink temperature sensor.
		CANDB_MCF_FAULTSA_FIELD_FT_REQ_NZ=15, //Non-zero torque request during PWM turning on.
		CANDB_MCF_FAULTSA_FIELD_LFT_IPM=16, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_HV_UV=17, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_HV_OV=18, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_CSU_CALND=19, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_CSU_FAIL=20, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_CSW_CALND=21, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_CSW_FAIL=22, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_OC=23, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_RES_FAIL=24, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_RES_CALND=25, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_RES_POSSTEP=26, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_TMOT_FAIL=27, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_TMOT_OR=28, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_TIGBT_FAIL=29, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_TIGBT_OR=30, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_REQ_NZ=31, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSA_FIELD_LFT_TIME=32, //cas kedy naposledy - kombinovat, tie co maju 0 reportovat v 1... 10b mantisa, 6b exponent
	}candb_enum_MCF_FaultsA_FIELD_t;
	typedef enum{
		CANDB_MCF_FAULTSB_FIELD_FT_IPM=0, //Intelligent Power Module's error (Overcurrent / Overtemperature / Undervoltage).
		CANDB_MCF_FAULTSB_FIELD_FT_HV_UV=1, //High voltage undervoltage.
		CANDB_MCF_FAULTSB_FIELD_FT_HV_OV=2, //High voltage overvoltage.
		CANDB_MCF_FAULTSB_FIELD_FT_CSU_CALND=3, //Current sensor U calibration needed (offset drifted).
		CANDB_MCF_FAULTSB_FIELD_FT_CSU_FAIL=4, //Current sensor U failure (saturation for no reason / huge drift of offset).
		CANDB_MCF_FAULTSB_FIELD_FT_CSW_CALND=5, //Current sensor W calibration needed (offset drifted).
		CANDB_MCF_FAULTSB_FIELD_FT_CSW_FAIL=6, //Current sensor W failure (saturation for no reason / huge drift of offset).
		CANDB_MCF_FAULTSB_FIELD_FT_OC=7, //Overcurrent peak measured by current sensor.
		CANDB_MCF_FAULTSB_FIELD_FT_RES_FAIL=8, //Resolver failure (not connected or interrupted / huge offset or gain).
		CANDB_MCF_FAULTSB_FIELD_FT_RES_CALND=9, //Resolver calibration needed (sin/cos offset or gain drifted).
		CANDB_MCF_FAULTSB_FIELD_FT_RES_POSSTEP=10, //Resolver evaluated angle big step (noise / connection / defect).
		CANDB_MCF_FAULTSB_FIELD_FT_TMOT_FAIL=11, //Motor temperature sensor not connected.
		CANDB_MCF_FAULTSB_FIELD_FT_TMOT_OR=12, //Temperature over range of motor temperature sensor.
		CANDB_MCF_FAULTSB_FIELD_FT_TIGBT_FAIL=13, //IGBT's heat sink temperature sensor not connected.
		CANDB_MCF_FAULTSB_FIELD_FT_TIGBT_OR=14, //Temperature over range of IGBT's heat sink temperature sensor.
		CANDB_MCF_FAULTSB_FIELD_FT_REQ_NZ=15, //Non-zero torque request during PWM turning on.
		CANDB_MCF_FAULTSB_FIELD_LFT_IPM=16, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_HV_UV=17, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_HV_OV=18, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_CSU_CALND=19, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_CSU_FAIL=20, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_CSW_CALND=21, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_CSW_FAIL=22, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_OC=23, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_RES_FAIL=24, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_RES_CALND=25, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_RES_POSSTEP=26, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_TMOT_FAIL=27, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_TMOT_OR=28, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_TIGBT_FAIL=29, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_TIGBT_OR=30, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_REQ_NZ=31, //Time from the last occurence of ... is being reported.
		CANDB_MCF_FAULTSB_FIELD_LFT_TIME=32, //description not provided
	}candb_enum_MCF_FaultsB_FIELD_t;
	typedef enum{
		CANDB_MCF_SYSTEMCONTROL_FIELD_PWMA_CTRL=0, //log.1 requests to start motor control on channel A.
		CANDB_MCF_SYSTEMCONTROL_FIELD_PWMB_CTRL=1, //log.1 requests to start motor control on channel B.
		CANDB_MCF_SYSTEMCONTROL_FIELD_DIRA_CTRL=2, //Motor default direction channel A. It will update only when PWMA_CTRL is FALSE.
		CANDB_MCF_SYSTEMCONTROL_FIELD_DIRB_CTRL=3, //Motor default direction channel B. It will update only when PWMB_CTRL is FALSE.
		CANDB_MCF_SYSTEMCONTROL_FIELD_GENA_EN=4, //Generation mode on channel A globally enabled when TRUE.
		CANDB_MCF_SYSTEMCONTROL_FIELD_GENB_EN=5, //Generation mode on channel B globally enabled when TRUE.
		CANDB_MCF_SYSTEMCONTROL_FIELD_DISCH_REQ=6, //log.1 requests to connect discharge resistor.
	}candb_enum_MCF_SystemControl_FIELD_t;
	typedef enum{
		CANDB_MCF_SETTINGS_FIELD_POA=0, //True requests to turn on aux power output channel A.
		CANDB_MCF_SETTINGS_FIELD_POB=1, //True requests to turn on aux power output channel B.
		CANDB_MCF_SETTINGS_FIELD_FWGAIN=2, //Field weakening strength - external adjustment
	}candb_enum_MCF_Settings_FIELD_t;
	typedef enum{
		CANDB_MCR_GENERALREPORT_FIELD_SDC_IN=0, //Shutdown circuit - point at input.
		CANDB_MCR_GENERALREPORT_FIELD_SDC_MSCB=1, //Shutdown circuit - point after channel B motor's sensor connector.
		CANDB_MCR_GENERALREPORT_FIELD_SDC_MPCB=2, //Shutdown circuit - point after channel B motor's power connector.
		CANDB_MCR_GENERALREPORT_FIELD_SDC_HVC=3, //Shutdown circuit - point after high voltage connector.
		CANDB_MCR_GENERALREPORT_FIELD_SDC_MPCA=4, //Shutdown circuit - point after channel A motor's power connector.
		CANDB_MCR_GENERALREPORT_FIELD_SDC_MSCA=5, //Shutdown circuit - point after channel A motor's sensor connector.
		CANDB_MCR_GENERALREPORT_FIELD_DISCH=6, //True means discharge resistor is connected.
		CANDB_MCR_GENERALREPORT_FIELD_POA=7, //True means active auxiliary power output channel A.
		CANDB_MCR_GENERALREPORT_FIELD_POA_PS=8, //Power supply for POA. log.1 = 12V, log.0 = input voltage (24V).
		CANDB_MCR_GENERALREPORT_FIELD_POB=9, //True means active auxiliary power output channel B.
		CANDB_MCR_GENERALREPORT_FIELD_POB_PS=10, //Power supply for POB. log.1 = 12V, log.0 = input voltage (24V).
		CANDB_MCR_GENERALREPORT_FIELD_PWMA=11, //True means channel A PWM is active.
		CANDB_MCR_GENERALREPORT_FIELD_FWA=12, //True means field weakening is allowed for channel A.
		CANDB_MCR_GENERALREPORT_FIELD_GENA=13, //True means generation mode is allowed for channel A.
		CANDB_MCR_GENERALREPORT_FIELD_DIRA=14, //Default direction for positive requests values. 
		CANDB_MCR_GENERALREPORT_FIELD_PWMB=15, //True means channel B PWM is active.
		CANDB_MCR_GENERALREPORT_FIELD_FWB=16, //True means field weakening is allowed for channel B.
		CANDB_MCR_GENERALREPORT_FIELD_GENB=17, //True means generation mode is allowed for channel B.
		CANDB_MCR_GENERALREPORT_FIELD_DIRB=18, //Default direction for positive requests values. 
		CANDB_MCR_GENERALREPORT_FIELD_HB=19, //Heart beat.
	}candb_enum_MCR_GeneralReport_FIELD_t;
	typedef enum{
		CANDB_MCR_THERMALMEASURESA_FIELD_TIGBT=0, //Temperature of IGBT's heat sink.
		CANDB_MCR_THERMALMEASURESA_FIELD_TIGBTJ=1, //Temperature estimation of IGBT chip.
		CANDB_MCR_THERMALMEASURESA_FIELD_TMOTCON=2, //Temperature of motor's connector.
		CANDB_MCR_THERMALMEASURESA_FIELD_TMOTSEN=3, //Temperature of motor's temp. sensor.
		CANDB_MCR_THERMALMEASURESA_FIELD_TMOTWIN=4, //Temperature estimation of motor's winding.
		CANDB_MCR_THERMALMEASURESA_FIELD_TCAP=5, //Temperature of capacitor bank.
		CANDB_MCR_THERMALMEASURESA_FIELD_TMOTI2T=6, //Motor performance capacity utilization rate.
	}candb_enum_MCR_ThermalMeasuresA_FIELD_t;
	typedef enum{
		CANDB_MCR_THERMALMEASURESB_FIELD_TIGBT=0, //Temperature of IGBT's heat sink.
		CANDB_MCR_THERMALMEASURESB_FIELD_TIGBTJ=1, //Temperature estimation of IGBT chip.
		CANDB_MCR_THERMALMEASURESB_FIELD_TMOTCON=2, //Temperature of motor's connector.
		CANDB_MCR_THERMALMEASURESB_FIELD_TMOTSEN=3, //Temperature of motor's temp. sensor.
		CANDB_MCR_THERMALMEASURESB_FIELD_TMOTWIN=4, //Temperature estimation of motor's winding.
		CANDB_MCR_THERMALMEASURESB_FIELD_TCAP=5, //Temperature of capacitor bank.
		CANDB_MCR_THERMALMEASURESB_FIELD_TMOTI2T=6, //Motor performance capacity utilization rate.
	}candb_enum_MCR_ThermalMeasuresB_FIELD_t;
	typedef enum{
		CANDB_MCR_CHANNELMEASURESA_FIELD_SPEED=0, //Speed of motor.
		CANDB_MCR_CHANNELMEASURESA_FIELD_TORQUE=1, //Torque of motor.
		CANDB_MCR_CHANNELMEASURESA_FIELD_PWRIN=2, //Channel's input power consumption.
		CANDB_MCR_CHANNELMEASURESA_FIELD_VDC=3, //Input voltage DC.
	}candb_enum_MCR_ChannelMeasuresA_FIELD_t;
	typedef enum{
		CANDB_MCR_CHANNELMEASURESB_FIELD_SPEED=0, //Speed of motor.
		CANDB_MCR_CHANNELMEASURESB_FIELD_TORQUE=1, //Torque of motor.
		CANDB_MCR_CHANNELMEASURESB_FIELD_PWRIN=2, //Channel's input power consumption.
		CANDB_MCR_CHANNELMEASURESB_FIELD_VDC=3, //Input voltage DC.
	}candb_enum_MCR_ChannelMeasuresB_FIELD_t;
	typedef enum{
		CANDB_MCR_REVOLUTIONSA_FIELD_TA_FWD=0, //Turn Angle in forward direction.
		CANDB_MCR_REVOLUTIONSA_FIELD_TA_RVS=1, //Turn Angle in reverse direction.
	}candb_enum_MCR_RevolutionsA_FIELD_t;
	typedef enum{
		CANDB_MCR_REVOLUTIONSB_FIELD_TA_FWD=0, //Turn Angle in forward direction.
		CANDB_MCR_REVOLUTIONSB_FIELD_TA_RVS=1, //Turn Angle in reverse direction.
	}candb_enum_MCR_RevolutionsB_FIELD_t;
	typedef enum{
		CANDB_MCR_UDQIDQA_FIELD_UD=0, //Output voltage (direct component) to input voltage (DC) ratio. Amplitude value.
		CANDB_MCR_UDQIDQA_FIELD_UQ=1, //Output voltage (quadrature component) to input voltage (DC) ratio. Amplitude value.
		CANDB_MCR_UDQIDQA_FIELD_ID=2, //Output current (direct component), Amplitude value.
		CANDB_MCR_UDQIDQA_FIELD_IQ=3, //Output current (quadrature component), Amplitude value.
	}candb_enum_MCR_UdqIdqA_FIELD_t;
	typedef enum{
		CANDB_MCR_UDQIDQB_FIELD_UD=0, //Output voltage (direct component) to input voltage (DC) ratio. Amplitude value.
		CANDB_MCR_UDQIDQB_FIELD_UQ=1, //Output voltage (quadrature component) to input voltage (DC) ratio. Amplitude value.
		CANDB_MCR_UDQIDQB_FIELD_ID=2, //Output current (direct component), Amplitude value.
		CANDB_MCR_UDQIDQB_FIELD_IQ=3, //Output current (quadrature component), Amplitude value.
	}candb_enum_MCR_UdqIdqB_FIELD_t;
	typedef enum{
		CANDB_MCR_FAULTSA_FIELD_FT_IPM=0, //Intelligent Power Module's error (Overcurrent / Overtemperature / Undervoltage).
		CANDB_MCR_FAULTSA_FIELD_FT_HV_UV=1, //High voltage undervoltage.
		CANDB_MCR_FAULTSA_FIELD_FT_HV_OV=2, //High voltage overvoltage.
		CANDB_MCR_FAULTSA_FIELD_FT_CSU_CALND=3, //Current sensor U calibration needed (offset drifted).
		CANDB_MCR_FAULTSA_FIELD_FT_CSU_FAIL=4, //Current sensor U failure (saturation for no reason / huge drift of offset).
		CANDB_MCR_FAULTSA_FIELD_FT_CSW_CALND=5, //Current sensor W calibration needed (offset drifted).
		CANDB_MCR_FAULTSA_FIELD_FT_CSW_FAIL=6, //Current sensor W failure (saturation for no reason / huge drift of offset).
		CANDB_MCR_FAULTSA_FIELD_FT_OC=7, //Overcurrent peak measured by current sensor.
		CANDB_MCR_FAULTSA_FIELD_FT_RES_FAIL=8, //Resolver failure (not connected or interrupted / huge offset or gain).
		CANDB_MCR_FAULTSA_FIELD_FT_RES_CALND=9, //Resolver calibration needed (sin/cos offset or gain drifted).
		CANDB_MCR_FAULTSA_FIELD_FT_RES_POSSTEP=10, //Resolver evaluated angle big step (noise / connection / defect).
		CANDB_MCR_FAULTSA_FIELD_FT_TMOT_FAIL=11, //Motor temperature sensor not connected.
		CANDB_MCR_FAULTSA_FIELD_FT_TMOT_OR=12, //Temperature over range of motor temperature sensor.
		CANDB_MCR_FAULTSA_FIELD_FT_TIGBT_FAIL=13, //IGBT's heat sink temperature sensor not connected.
		CANDB_MCR_FAULTSA_FIELD_FT_TIGBT_OR=14, //Temperature over range of IGBT's heat sink temperature sensor.
		CANDB_MCR_FAULTSA_FIELD_FT_REQ_NZ=15, //Non-zero torque request during PWM turning on.
		CANDB_MCR_FAULTSA_FIELD_LFT_IPM=16, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_HV_UV=17, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_HV_OV=18, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_CSU_CALND=19, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_CSU_FAIL=20, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_CSW_CALND=21, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_CSW_FAIL=22, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_OC=23, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_RES_FAIL=24, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_RES_CALND=25, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_RES_POSSTEP=26, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_TMOT_FAIL=27, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_TMOT_OR=28, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_TIGBT_FAIL=29, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_TIGBT_OR=30, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_REQ_NZ=31, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSA_FIELD_LFT_TIME=32, //cas kedy naposledy - kombinovat, tie co maju 0 reportovat v 1... 10b mantisa, 6b exponent
	}candb_enum_MCR_FaultsA_FIELD_t;
	typedef enum{
		CANDB_MCR_FAULTSB_FIELD_FT_IPM=0, //Intelligent Power Module's error (Overcurrent / Overtemperature / Undervoltage).
		CANDB_MCR_FAULTSB_FIELD_FT_HV_UV=1, //High voltage undervoltage.
		CANDB_MCR_FAULTSB_FIELD_FT_HV_OV=2, //High voltage overvoltage.
		CANDB_MCR_FAULTSB_FIELD_FT_CSU_CALND=3, //Current sensor U calibration needed (offset drifted).
		CANDB_MCR_FAULTSB_FIELD_FT_CSU_FAIL=4, //Current sensor U failure (saturation for no reason / huge drift of offset).
		CANDB_MCR_FAULTSB_FIELD_FT_CSW_CALND=5, //Current sensor W calibration needed (offset drifted).
		CANDB_MCR_FAULTSB_FIELD_FT_CSW_FAIL=6, //Current sensor W failure (saturation for no reason / huge drift of offset).
		CANDB_MCR_FAULTSB_FIELD_FT_OC=7, //Overcurrent peak measured by current sensor.
		CANDB_MCR_FAULTSB_FIELD_FT_RES_FAIL=8, //Resolver failure (not connected or interrupted / huge offset or gain).
		CANDB_MCR_FAULTSB_FIELD_FT_RES_CALND=9, //Resolver calibration needed (sin/cos offset or gain drifted).
		CANDB_MCR_FAULTSB_FIELD_FT_RES_POSSTEP=10, //Resolver evaluated angle big step (noise / connection / defect).
		CANDB_MCR_FAULTSB_FIELD_FT_TMOT_FAIL=11, //Motor temperature sensor not connected.
		CANDB_MCR_FAULTSB_FIELD_FT_TMOT_OR=12, //Temperature over range of motor temperature sensor.
		CANDB_MCR_FAULTSB_FIELD_FT_TIGBT_FAIL=13, //IGBT's heat sink temperature sensor not connected.
		CANDB_MCR_FAULTSB_FIELD_FT_TIGBT_OR=14, //Temperature over range of IGBT's heat sink temperature sensor.
		CANDB_MCR_FAULTSB_FIELD_FT_REQ_NZ=15, //Non-zero torque request during PWM turning on.
		CANDB_MCR_FAULTSB_FIELD_LFT_IPM=16, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_HV_UV=17, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_HV_OV=18, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_CSU_CALND=19, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_CSU_FAIL=20, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_CSW_CALND=21, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_CSW_FAIL=22, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_OC=23, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_RES_FAIL=24, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_RES_CALND=25, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_RES_POSSTEP=26, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_TMOT_FAIL=27, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_TMOT_OR=28, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_TIGBT_FAIL=29, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_TIGBT_OR=30, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_REQ_NZ=31, //Time from the last occurence of ... is being reported.
		CANDB_MCR_FAULTSB_FIELD_LFT_TIME=32, //description not provided
	}candb_enum_MCR_FaultsB_FIELD_t;
	typedef enum{
		CANDB_MCR_TORQUEPOWERCONTROL_FIELD_REQTRQA=0, //Required torque channel A.
		CANDB_MCR_TORQUEPOWERCONTROL_FIELD_PWRRESTRA=1, //Input power restriction for channel A.
		CANDB_MCR_TORQUEPOWERCONTROL_FIELD_REQTRQB=2, //Required torque channel B.
		CANDB_MCR_TORQUEPOWERCONTROL_FIELD_PWRRESTRB=3, //Input power restriction for channel B.
	}candb_enum_MCR_TorquePowerControl_FIELD_t;
	typedef enum{
		CANDB_MCR_SYSTEMCONTROL_FIELD_PWMA_CTRL=0, //log.1 requests to start motor control on channel A.
		CANDB_MCR_SYSTEMCONTROL_FIELD_PWMB_CTRL=1, //log.1 requests to start motor control on channel B.
		CANDB_MCR_SYSTEMCONTROL_FIELD_DIRA_CTRL=2, //Motor default direction channel A. It will update only when PWMA_CTRL is FALSE.
		CANDB_MCR_SYSTEMCONTROL_FIELD_DIRB_CTRL=3, //Motor default direction channel B. It will update only when PWMB_CTRL is FALSE.
		CANDB_MCR_SYSTEMCONTROL_FIELD_GENA_EN=4, //Generation mode on channel A globally enabled when TRUE.
		CANDB_MCR_SYSTEMCONTROL_FIELD_GENB_EN=5, //Generation mode on channel B globally enabled when TRUE.
		CANDB_MCR_SYSTEMCONTROL_FIELD_DISCH_REQ=6, //log.1 requests to connect discharge resistor.
	}candb_enum_MCR_SystemControl_FIELD_t;
	typedef enum{
		CANDB_MCR_SETTINGS_FIELD_POA=0, //True requests to turn on aux power output channel A.
		CANDB_MCR_SETTINGS_FIELD_POB=1, //True requests to turn on aux power output channel B.
		CANDB_MCR_SETTINGS_FIELD_FWGAIN=2, //Field weakening strength - external adjustment
	}candb_enum_MCR_Settings_FIELD_t;
	typedef enum{
		CANDB_MCF_TORQUEPOWERCONTROL_FIELD_REQTRQA=0, //Required torque channel A.
		CANDB_MCF_TORQUEPOWERCONTROL_FIELD_PWRRESTRA=1, //Input power restriction for channel A.
		CANDB_MCF_TORQUEPOWERCONTROL_FIELD_REQTRQB=2, //Required torque channel B.
		CANDB_MCF_TORQUEPOWERCONTROL_FIELD_PWRRESTRB=3, //Input power restriction for channel B.
	}candb_enum_MCF_TorquePowerControl_FIELD_t;
	typedef enum{
		CANDB_ECUS_STATUS_FIELD_SEQ=0, //Upcounter, ++ on each message transmission
	}candb_enum_ECUS_Status_FIELD_t;
	typedef enum{
		CANDB_IMU_STATUS_FIELD_STATE=0, //description not provided
		CANDB_IMU_STATUS_FIELD_FT_ACC_CAL=1, //Fault for ACC calibration
		CANDB_IMU_STATUS_FIELD_FT_GYRO_CAL=2, //Fault for Gyro calibration
		CANDB_IMU_STATUS_FIELD_FT_MOUNT_CAL=3, //Fault for mount calibration
	}candb_enum_IMU_Status_FIELD_t;
	typedef enum{
		CANDB_IMU_ACCELERATION_FIELD_LONG=0, //Longitudinal acceleration (Forward - positive)
		CANDB_IMU_ACCELERATION_FIELD_LAT=1, //Lateral acceleration (Left - positive
		CANDB_IMU_ACCELERATION_FIELD_VER=2, //Vertical acceleration (Up - positive)
		CANDB_IMU_ACCELERATION_FIELD_FT_LONG=3, //Fault of longitudinal acceleration measurement
		CANDB_IMU_ACCELERATION_FIELD_FT_LAT=4, //Fault of lateral acceleration  measurement
		CANDB_IMU_ACCELERATION_FIELD_FT_VERT=5, //Fault of vertical acceleration measurement
		CANDB_IMU_ACCELERATION_FIELD_SEQ=6, //Message up counter for safety
	}candb_enum_IMU_Acceleration_FIELD_t;
	typedef enum{
		CANDB_IMU_GYRO_FIELD_ROLL=0, //Roll inertial speed (To right is positive)
		CANDB_IMU_GYRO_FIELD_PITCH=1, //Pitch inertial speed (To front is positive
		CANDB_IMU_GYRO_FIELD_YAW=2, //Yaw inertial speed (To left is positive)
		CANDB_IMU_GYRO_FIELD_FT_ROLL=3, //Fault of roll measurement
		CANDB_IMU_GYRO_FIELD_FT_PITCH=4, //Fault of pitch measurement
		CANDB_IMU_GYRO_FIELD_FT_YAW=5, //Fault of yaw measurement
		CANDB_IMU_GYRO_FIELD_SEQ=6, //Message up counter for safety
	}candb_enum_IMU_Gyro_FIELD_t;
	typedef enum{
		CANDB_IMU_GPS_POSITION_FIELD_LONG=0, //GPS Longitude coordinate (float)
		CANDB_IMU_GPS_POSITION_FIELD_LAT=1, //GPS Latittude coordinate (float)
	}candb_enum_IMU_GPS_position_FIELD_t;
	typedef enum{
		CANDB_IMU_OFFSETS_ACC_FIELD_LONG=0, //Used calibrate constant
		CANDB_IMU_OFFSETS_ACC_FIELD_LAT=1, //Used calibrate constant
		CANDB_IMU_OFFSETS_ACC_FIELD_VER=2, //Used calibrate constant
	}candb_enum_IMU_Offsets_Acc_FIELD_t;
	typedef enum{
		CANDB_IMU_OFFSETS_GYR_FIELD_ROLL=0, //Roll calibration offset
		CANDB_IMU_OFFSETS_GYR_FIELD_PITCH=1, //Pitch calibration offset
		CANDB_IMU_OFFSETS_GYR_FIELD_YAW=2, //Yaw calibration offset
	}candb_enum_IMU_Offsets_Gyr_FIELD_t;
	typedef enum{
		CANDB_MSG_ECUA_STATUS=0, //ECUA Base status of ECUA and its subsystems (AMS)
		CANDB_MSG_ECUA_LIMITS=1, //ECUA ACP power limits that are calculated in time based on temperature and votlages. For example if undervoltage the PWR_OUT should be some few kW value to let the driver decide to risk. If ACP is full PWR_IN should be 0.
		CANDB_MSG_ECUA_ACPMEAS=2, //ECUA Main ACP measurements
		CANDB_MSG_ECUA_ESTIMATION=3, //ECUA Calculated data in ACP
		CANDB_MSG_ECUA_BALANCINGSTATUS=4, //ECUA 
		CANDB_MSG_ECUA_BALANCINGSTATUS2=5, //ECUA 
		CANDB_MSG_ECUA_AMSVOLTS=6, //ECUA AMS message for voltages. Uses multiplexors for identifications of dataset. AMS measures all stacks in the same time but sent that in specific order determined by muxing.
		CANDB_MSG_ECUA_AMSTEMP=7, //ECUA AMS message for temperatures. Uses multiplexors for identification of dataset.
		CANDB_MSG_ECUA_AMSSTACK=8, //ECUA BMS status for each stack Not recommended for new designs (obsolete)
		CANDB_MSG_ECUA_AMSOVERALL=9, //ECUA AMS Overal data Auch ein bisschen redundant
		CANDB_MSG_ECUA_VOLTAGES=10, //ECUA Accumulator voltage information.
		CANDB_MSG_CCU_CHARGERHEARTBEAT=11, //CCU Hotfix for a missing interlock. Sent by ECUA to CCU.
		CANDB_MSG_ECUB_STATUS=12, //ECUB ECUB Status report
		CANDB_MSG_ECUB_WHEELSPEED=13, //ECUB Wheel speed measurement message
		CANDB_MSG_ECUB_GLV_AMS=14, //ECUB GLV Accumulator management system
		CANDB_MSG_ECUB_COOLING=15, //ECUB PWM for each fan and waterpump
		CANDB_MSG_ECUB_POWER_DIST=16, //ECUB Power distribution message measurement U_ECUA U_Service_box
		CANDB_MSG_ECUB_TEMPSUSPR=17, //ECUB Rear suspension temperatures
		CANDB_MSG_ECUB_TEMPAUX=18, //ECUB Auxiliary temperature measurements - cooling system
		CANDB_MSG_ECUP_STATUS=19, //ECUP ECUP Status message
		CANDB_MSG_ECUP_PEDALS=20, //ECUP Pedal values and valid flags
		CANDB_MSG_ECUP_PRESSURE=21, //ECUP Brake pressures sensor
		CANDB_MSG_ECUP_DIAGPOS=22, //ECUP Raw diagnostic positional data of pedals
		CANDB_MSG_ECUP_DIAGPRESSURE=23, //ECUP Raw sensor values
		CANDB_MSG_ECUP_REQCALIBPEDAL=24, //ECUP Request calibration. Assign pedal max/min to its' current position.
		CANDB_MSG_VDCU_STATUS=25, //VDCU VDCU systems status
		CANDB_MSG_VDCU_SOC=26, //VDCU SOC Estimation
		CANDB_MSG_VDCU_PARAM=27, //VDCU Parameters changed in ECUS are muxed and sent after every change. Acknowledge is expected in next 20ms. If not acknowledged parameters are resend unitl 5th time. Whole parameters are boadcasted in a loop. The acknowledges parameters data are then displayed.
		CANDB_MSG_VDCU_REQCALIBDIS=28, //VDCU Request for displacement sensor calibration
		CANDB_MSG_VDCU_CONTROLLER=29, //VDCU Overal actual values of motor torques
		CANDB_MSG_VDCU_BODY=30, //VDCU Formula Body actual values
		CANDB_MSG_VDCU_WHEELFZ=31, //VDCU Calculated and calibrated wheel loads. Using accelerometer, configuration and suspension displacement sensors
		CANDB_MSG_VDCU_PARAM_ACK=32, //VDCU ECUS is displaying and evaluating the parameters that are only sent and acknowledged. That means that the initial parameter set is sent from ECUS and should be acknowledged of the actual used values by unit
		CANDB_MSG_VDCU_LONGSLIP=33, //VDCU Calculated longitudinal wheel slip
		CANDB_MSG_VDCU_SLIPANGLE=34, //VDCU Calculated slip angles on wheels
		CANDB_MSG_ECUF_STATUS=35, //ECUF Summary of unit status and faults
		CANDB_MSG_ECUF_DASHBOARD=36, //ECUF Dashboard buttons & switches, but not only that :thinking:
		CANDB_MSG_ECUF_STW=37, //ECUF Steering wheel angle measurements.
		CANDB_MSG_ECUF_DISSUSP=38, //ECUF Suspension displacement sensors (Spring lengths)
		CANDB_MSG_ECUF_TEMPSUSPF=39, //ECUF Front suspension temperatures
		CANDB_MSG_ECUF_REQCALIBSTW=40, //ECUF Request calibration of steering wheel
		CANDB_MSG_MCF_GENERALREPORT=41, //MCF Actual settings and states, system faults.
		CANDB_MSG_MCF_THERMALMEASURESA=42, //MCF Thermal measures for channel A.
		CANDB_MSG_MCF_THERMALMEASURESB=43, //MCF Thermal measures for channel B.
		CANDB_MSG_MCF_CHANNELMEASURESA=44, //MCF Motor/channel A essential measures.
		CANDB_MSG_MCF_CHANNELMEASURESB=45, //MCF Motor/channel B essential measures.
		CANDB_MSG_MCF_REVOLUTIONSA=46, //MCF Absolute values of turn angles in forward and reverse direction for channel A.
		CANDB_MSG_MCF_REVOLUTIONSB=47, //MCF Absolute values of turn angles in forward and reverse direction for channel B.
		CANDB_MSG_MCF_UDQIDQA=48, //MCF Ud, Uq, Id, Iq of channel A
		CANDB_MSG_MCF_UDQIDQB=49, //MCF Ud, Uq, Id, Iq of channel B
		CANDB_MSG_MCF_FAULTSA=50, //MCF Faults and failure reasons of channel A.
		CANDB_MSG_MCF_FAULTSB=51, //MCF Faults and failure reasons of channel B.
		CANDB_MSG_MCF_NOTIFICATIONSWARNINGSA=52, //MCF Notifications and warnings from channel A.
		CANDB_MSG_MCF_NOTIFICATIONSWARNINGSB=53, //MCF Notifications and warnings from channel B.
		CANDB_MSG_MCF_SYSTEMCONTROL=54, //MCF Main states and behavior control.
		CANDB_MSG_MCF_SETTINGS=55, //MCF Various settings available.
		CANDB_MSG_MCR_GENERALREPORT=56, //MCR Actual settings and states, system faults.
		CANDB_MSG_MCR_THERMALMEASURESA=57, //MCR Thermal measures for channel A.
		CANDB_MSG_MCR_THERMALMEASURESB=58, //MCR Thermal measures for channel B.
		CANDB_MSG_MCR_CHANNELMEASURESA=59, //MCR Motor/channel A essential measures.
		CANDB_MSG_MCR_CHANNELMEASURESB=60, //MCR Motor/channel B essential measures.
		CANDB_MSG_MCR_REVOLUTIONSA=61, //MCR Absolute values of turn angles in forward and reverse direction for channel A.
		CANDB_MSG_MCR_REVOLUTIONSB=62, //MCR Absolute values of turn angles in forward and reverse direction for channel B.
		CANDB_MSG_MCR_UDQIDQA=63, //MCR Ud, Uq, Id, Iq of channel A
		CANDB_MSG_MCR_UDQIDQB=64, //MCR Ud, Uq, Id, Iq of channel B
		CANDB_MSG_MCR_FAULTSA=65, //MCR Faults and failure reasons of channel A.
		CANDB_MSG_MCR_FAULTSB=66, //MCR Faults and failure reasons of channel B.
		CANDB_MSG_MCR_NOTIFICATIONSWARNINGSA=67, //MCR Notifications and warnings from channel A.
		CANDB_MSG_MCR_NOTIFICATIONSWARNINGSB=68, //MCR Notifications and warnings from channel B.
		CANDB_MSG_MCR_TORQUEPOWERCONTROL=69, //MCR Torque and Power control for both channels.
		CANDB_MSG_MCR_SYSTEMCONTROL=70, //MCR Main states and behavior control.
		CANDB_MSG_MCR_SETTINGS=71, //MCR Various settings available.
		CANDB_MSG_MCF_TORQUEPOWERCONTROL=72, //MCF Torque and Power control for both channels.
		CANDB_MSG_ECUS_STATUS=73, //ECUS Status of ECUS unit
		CANDB_MSG_IMU_STATUS=74, //IMU Calibration, configuration
		CANDB_MSG_IMU_ACCELERATION=75, //IMU IMU Acceleration (longitudinal, lateral, vertical)  calibrated measuring for mount and referenced to CG (CG position = )
		CANDB_MSG_IMU_GYRO=76, //IMU IMU Rate (roll, pitch, yaw) calibrated measuring for mount and referenced to CG (CG position = )
		CANDB_MSG_IMU_GPS_POSITION=77, //IMU GPS Longitude, Latitude in floating point format
		CANDB_MSG_IMU_OFFSETS_ACC=78, //IMU Value of calibration offset constants of accelerometer's axis
		CANDB_MSG_IMU_OFFSETS_GYR=79, //IMU Value of calibration constants of gyroscope's axis (offsets)
	}candb_enum_msg_t;
	typedef enum{
		CANDB_ECUA_AIRSSTATE_ECUA_PENDINGCHARGERDETECT=0, //Awaiting detection of car or charger
		CANDB_ECUA_AIRSSTATE_ECUA_READY=1, //Awaiting SDC completion to begin precharge
		CANDB_ECUA_AIRSSTATE_ECUA_STARTUPCHECK=2, //Startup check
		CANDB_ECUA_AIRSSTATE_ECUA_PRECHARGECLOSING=3, //Precharge relay is being closed
		CANDB_ECUA_AIRSSTATE_ECUA_HVMCLOSING=4, //HV- relay is being closed
		CANDB_ECUA_AIRSSTATE_ECUA_PRECHARGING=5, //Precharge part 1: blind delay
		CANDB_ECUA_AIRSSTATE_ECUA_WAITINGFORVDIFF=6, //Precharge part 2: wait for ΔV to approach zero
		CANDB_ECUA_AIRSSTATE_ECUA_HVPCLOSING=7, //HV+ relay is being closed
		CANDB_ECUA_AIRSSTATE_ECUA_ENDPRECHARGE=8, //Precharge is finishing
		CANDB_ECUA_AIRSSTATE_ECUA_TSACTIVE=9, //TS is charged and active
		CANDB_ECUA_AIRSSTATE_ECUA_FATALERROR=10, //A fatal error occured and the AMS is latched
		CANDB_ECUA_AIRSSTATE_ECUA_COOLDOWN=12, //Precharge failed, cooling down before retrying
		CANDB_ECUA_AIRSSTATE_ECUA_HVMCOOLDOWN=13, //HV- failed to close, cooling down before retrying
	}candb_enum_ECUA_AIRsState_t;
	typedef enum{
		CANDB_ECUA_STATEAMS_ECUA_ALL_OK=0, //without_fault
		CANDB_ECUA_STATEAMS_ECUA_SHIT=1, //All_fucked
	}candb_enum_ECUA_StateAMS_t;
	typedef enum{
		CANDB_ECUA_ERRORCODE_ECUA_OK=0, //no error
		CANDB_ECUA_ERRORCODE_ECUA_SDC_TIMEOUT=1, //unused
		CANDB_ECUA_ERRORCODE_ECUA_HVM_MELT=2, //HV- closed even though it shouldn't be
		CANDB_ECUA_ERRORCODE_ECUA_HVP_MELT=3, //HV+ closed even though it shouldn't be
		CANDB_ECUA_ERRORCODE_ECUA_HVM_TIMEOUT=4, //HV- didn't close in time
		CANDB_ECUA_ERRORCODE_ECUA_HVP_TIMEOUT=5, //HV+ didn't close in time
		CANDB_ECUA_ERRORCODE_ECUA_VDIFF_TIMEOUT=6, //precharge failed to equaize AIRs x Accu voltage
		CANDB_ECUA_ERRORCODE_ECUA_SDC_INTERRUPTED=7, //SDC interrupted unexpectedly
		CANDB_ECUA_ERRORCODE_ECUA_HVM_DISCONNECT=8, //HV- broke open
		CANDB_ECUA_ERRORCODE_ECUA_HVP_DISCONNECT=9, //HV+ broke open
		CANDB_ECUA_ERRORCODE_ECUA_BMS_CELL_MIN_VOLTAGE=10, //Voltage of a cell is too low
		CANDB_ECUA_ERRORCODE_ECUA_BMS_CELL_BALANCE=11, //Imbalance between some cells is too high
		CANDB_ECUA_ERRORCODE_ECUA_BMS_CELL_TEMPERATURE=12, //Too hot!
		CANDB_ECUA_ERRORCODE_ECUA_BMS_COMMUNICATION=13, //BMS communication error - probably not connected
		CANDB_ECUA_ERRORCODE_ECUA_TOO_MANY_ERRORS=128, //Too many non-fatal errors => escalated to a fatal error
	}candb_enum_ECUA_ErrorCode_t;
	typedef enum{
		CANDB_ECUB_BATT_CODE_ECUB_IDLE=0, //No power drawn nor charged
		CANDB_ECUB_BATT_CODE_ECUB_CHARGING=1, //Charging with balancing
		CANDB_ECUB_BATT_CODE_ECUB_FAST_CHARGING=2, //Charging without balancing
		CANDB_ECUB_BATT_CODE_ECUB_BALANCING=3, //Only balancing
		CANDB_ECUB_BATT_CODE_ECUB_DISCHARGING=4, //Is being discharged
		CANDB_ECUB_BATT_CODE_ECUB_FULL=5, //Fully charged
		CANDB_ECUB_BATT_CODE_ECUB_ERROR=6, //Is in error state
	}candb_enum_ECUB_Batt_code_t;
	typedef enum{
		CANDB_ECUB_CARSTATE_ECUB_NOT_READY=0, //SDC interrupted -> not ready for start
		CANDB_ECUB_CARSTATE_ECUB_LATCHED=1, //Fatal error \w SDC latching
		CANDB_ECUB_CARSTATE_ECUB_TS_READY=2, //Ready for TSON button
		CANDB_ECUB_CARSTATE_ECUB_PRECHARGE=3, //ACP is being precharged -> waiting for ECUA status
		CANDB_ECUB_CARSTATE_ECUB_TS_ON=4, //Ready for START
		CANDB_ECUB_CARSTATE_ECUB_WAITING_FOR_RTDS=5, //Waiting for completion of RTDS
		CANDB_ECUB_CARSTATE_ECUB_STARTED=6, //Drive!
	}candb_enum_ECUB_CarState_t;
	typedef enum{
		CANDB_ECUB_GLV_POWERSOURCE_ECUB_ACP=0, //ACP
		CANDB_ECUB_GLV_POWERSOURCE_ECUB_GLV_BATTERY=1, //GLV battery
		CANDB_ECUB_GLV_POWERSOURCE_ECUB_SERVICE_INPUT=2, //Service box input
	}candb_enum_ECUB_GLV_PowerSource_t;
	typedef enum{
		CANDB_ECUB_NOTREADY_REASON_ECUB_NONE=0, //No error
		CANDB_ECUB_NOTREADY_REASON_ECUB_LATCH_START=1, //Vehicle was latched at the startup
		CANDB_ECUB_NOTREADY_REASON_ECUB_LATCH_BSPD=2, //Vehicle was latched due to BSPD error
		CANDB_ECUB_NOTREADY_REASON_ECUB_LATCH_AMS=3, //Vehicle was latched due to AMS error
		CANDB_ECUB_NOTREADY_REASON_ECUB_SDC_FAILURE=4, //Error in SDC chain
		CANDB_ECUB_NOTREADY_REASON_ECUB_TIMEOUT_MC=5, //Motor controller CAN timeout
		CANDB_ECUB_NOTREADY_REASON_ECUB_TIMEOUT_ECUA=6, //AMS CAN timeout
		CANDB_ECUB_NOTREADY_REASON_ECUB_TIMEOUT_ECUF=7, //ECU Front CAN timeout
		CANDB_ECUB_NOTREADY_REASON_ECUB_TIMEOUT_ECUP=8, //Pedal unit CAN timeout
		CANDB_ECUB_NOTREADY_REASON_ECUB_TIMEOUT_VDCU=9, //VDCU CAN timeout
		CANDB_ECUB_NOTREADY_REASON_ECUB_PWM_FAULT=10, //Fault on PWM_fault pins
	}candb_enum_ECUB_Notready_reason_t;
	typedef enum{
		CANDB_ECUP_CAL_PEDALINDEX_ECUP_NONE=0, //None
		CANDB_ECUP_CAL_PEDALINDEX_ECUP_APPSMIN=1, //Minimum apps position
		CANDB_ECUP_CAL_PEDALINDEX_ECUP_APPSMAX=2, //Maximum apps position
		CANDB_ECUP_CAL_PEDALINDEX_ECUP_BRAKEMIN=3, //Minimum brake position
		CANDB_ECUP_CAL_PEDALINDEX_ECUP_BRAKEMAX=4, //Maximum brake position
		CANDB_ECUP_CAL_PEDALINDEX_ECUP_REGENMAX=5, //Maximum regenerative position
	}candb_enum_ECUP_CAL_PedalIndex_t;
	typedef enum{
		CANDB_ECUP_CALIBRATIONINDEX_ECUP_DUMMY=1, //FIX THIS SHIT
	}candb_enum_ECUP_CalibrationIndex_t;
	typedef enum{
		CANDB_VDCU_CAL_DISINDEX_VDCU_NONE=0, //None
		CANDB_VDCU_CAL_DISINDEX_VDCU_DISFR=1, //Front right displacement sensor calibration
		CANDB_VDCU_CAL_DISINDEX_VDCU_DISFL=2, //Front left displacement sensor calibration
		CANDB_VDCU_CAL_DISINDEX_VDCU_DISRR=3, //Rear right displacement sensor calibration
		CANDB_VDCU_CAL_DISINDEX_VDCU_DISRL=4, //Rear left displacement sensor calibration
	}candb_enum_VDCU_CAL_DisIndex_t;
	typedef enum{
		CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_GAIN=0, //Torque gain (0-100)
		CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXFRONT=1, //Maximum torque for front axle (0-100)
		CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXREAR=2, //Maximum torque for rear axle (0-100)
		CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM=3, //Maximum power in kW (0-140)
		CANDB_VDCU_VDCU_PARAM_VDCU_GEN_PWRLIM=4, //Maximum regenerative power in kW (0-40)
		CANDB_VDCU_VDCU_PARAM_VDCU_PED_MAP=5, //Pedal map selector (0-4)
		CANDB_VDCU_VDCU_PARAM_VDCU_TV_DISTRIB=10, //Torque distribution to rear (0-100)
		CANDB_VDCU_VDCU_PARAM_VDCU_TV_FRONT_GAIN=11, //Torque vectoring gain on front axle (0-200)
		CANDB_VDCU_VDCU_PARAM_VDCU_TV_REAR_GAIN=12, //Torque vectoring gain on rear axle (0-200)
		CANDB_VDCU_VDCU_PARAM_VDCU_TV_SPEED_DECLINE=13, //Torque  vectoring speed decline (0-100)
		CANDB_VDCU_VDCU_PARAM_VDCU_TC_SLIP_SP=16, //Slip ratio controller slip setpoint (4-20)
		CANDB_VDCU_VDCU_PARAM_VDCU_YC_REF_GAIN=19, //Yaw rate controller reference gain (0-200)
		CANDB_VDCU_VDCU_PARAM_VDCU_YC_GAIN=20, //Yaw controller output gain (0-200)
		CANDB_VDCU_VDCU_PARAM_VDCU_FIELDWEAK=23, //Field weakening (0-100)
		CANDB_VDCU_VDCU_PARAM_VDCU_REVERSE_REQ=25, //Request for reverse [0,1] (not a parameter)
		CANDB_VDCU_VDCU_PARAM_VDCU_RACEMODE_REQ=26, //Racing mode (0-11) (OFF,accel, skid, autox, endu, fun, amateur, transport ...)
		CANDB_VDCU_VDCU_PARAM_VDCU_TV_EN=29, //TorqueVectoring (distribution) enable
		CANDB_VDCU_VDCU_PARAM_VDCU_GEN_EN=28, //ENABLE regenerative braking [0,1]
		CANDB_VDCU_VDCU_PARAM_VDCU_BOOST_EN=29, //ENABLE unlimited performance [0,1]
		CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_SPEED_DECLINE=32, //Torque speed limitation ramp (0-100)
		CANDB_VDCU_VDCU_PARAM_VDCU_TC_THRESHOLD=35, //Slip ratio controller threshold (0-10)
		CANDB_VDCU_VDCU_PARAM_VDCU_TC_KP=36, //Slip ratio controller Kp gain (0-200)
		CANDB_VDCU_VDCU_PARAM_VDCU_TC_KI=37, //Slip ratio controller Ki gain (0-200)
		CANDB_VDCU_VDCU_PARAM_VDCU_TC_KB=38, //Slip ratio controller Kb gain(0-100)
		CANDB_VDCU_VDCU_PARAM_VDCU_YC_SPEED_DECLINE=40, //Yaw controller Speed limitation ramp (0-100)
		CANDB_VDCU_VDCU_PARAM_VDCU_YC_KP=41, //Yaw controller Kp gain (0-200)
		CANDB_VDCU_VDCU_PARAM_VDCU_YC_KI=42, //Yaw controller Ki gain (0-200)
		CANDB_VDCU_VDCU_PARAM_VDCU_YC_KB=43, //Yaw controller Kb gain (0-100)
		CANDB_VDCU_VDCU_PARAM_VDCU_FEEDFORWARD_GAIN=44, //Feedforward gain (0-200)
		CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM_RAMP_DECLINE=50, //Power limiting speed ramp (0-100)
	}candb_enum_VDCU_VDCU_Param_t;
	typedef enum{
		CANDB_VDCU_VDCU_STATE_VDCU_STANDBY=0, //Waiting for RTD
		CANDB_VDCU_VDCU_STATE_VDCU_TORQUE_EN=1, //Torque enabled
		CANDB_VDCU_VDCU_STATE_VDCU_ERROR=2, //Error state
	}candb_enum_VDCU_VDCU_State_t;
	typedef enum{
		CANDB_ECUF_CAL_STWINDEX_ECUF_NONE=0, //None
		CANDB_ECUF_CAL_STWINDEX_ECUF_STWLEFT=1, //Left position (output is positive)
		CANDB_ECUF_CAL_STWINDEX_ECUF_STWCENTER=2, //Center position
		CANDB_ECUF_CAL_STWINDEX_ECUF_STWRIGHT=3, //Right position (output is negative)
	}candb_enum_ECUF_CAL_STWIndex_t;
#endif
