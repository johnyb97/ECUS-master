#include "device.h"
#include "config.h"
#include "misc.h"
#include "adc.h"
#include "gpio.h"
#include "clock.h"
#include "debug.h"
#include "sdram.h"
#include "ili9806e.h"
#include "ltdc.h"
#include "spi.h"
#include "lcd.h"
#include "i2c.h"
#include "goodix.h"
#include "exti.h"
#include "circular_buffer.h"
#include "nk.h"
#include "systick.h"
#include "can.h"
#include "candb/can_ECUS.h"
#include "candb_structure.h"
#include "candb_msg.h"
#include "field_tracker.h"
#include "qei.h"
#include "button.h"
#include "dent_pot.h"
#include "vdcu_params.h"
#include "menu_calib.h"
#include "iwdg.h"

#include "gui.h"
#include "gui_screen_messages.h"
#include "gui_screen_tracker.h"
#include "gui_screen_race.h"
#include "gui_screen_sdc.h"
#include "gui_screen_temperatures.h"
#include "gui_menu.h"
#include "gui_popup_param.h"


#include <string.h>
#include <stddef.h>
#include <math.h>


#include "debug_enable.h"

uint16_t adc_ain1=0;
uint16_t adc_ain2=0;

volatile uint8_t redraws=0;

uint32_t frame_timestamp_prev=0;
uint32_t frame_timestamp_last=0;

uint32_t loops_per_second=0;//counts how many times main loop repeats

enum{
	DISPLAYED_MENU,
	DISPLAYED_RACE_SCREEN,
} volatile displayed = DISPLAYED_RACE_SCREEN;

volatile uint8_t screen_idx = 0;

volatile uint32_t menu_last_activity_ts = 0;

menu_item_t testing_menu[]=
	MENU_ITEM_SUBMENU("MENU", NULL,
		MENU_ITEM_SUBMENU("CALIBRATION", NULL,
			MENU_ITEM_ONESHOT("APPS MAX", NULL, menu_calib_apps_max),
			MENU_ITEM_ONESHOT("APPS MIN", NULL, menu_calib_apps_min),
			MENU_ITEM_ONESHOT("BRAKE MAX", NULL, menu_calib_brake_max),
			MENU_ITEM_ONESHOT("BRAKE MIN", NULL, menu_calib_brake_min),
			MENU_ITEM_ONESHOT("REGEN MAX", NULL, menu_calib_regen_max),
			MENU_ITEM_ONESHOT("STW CENTER", NULL, menu_calib_stw_center)
		)
	);

menu_t menu = {
	.current_menu = testing_menu,
	.selected_position = 0,
};


struct{
	bool active;
	uint32_t last_action_ts;
}params_window={false, 0};

//IDLE
vdcu_param_t *const vdcu_param_set_idle[]={
	VDCU_PARAMETER("TRQ_GAIN",            CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_GAIN            , 0, 0, 0),//Torque gain (0-100)
	VDCU_PARAMETER("TRQ_MAXFRONT",        CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXFRONT        , 0, 0, 0),//Maximum torque for front axle (0-100)
	VDCU_PARAMETER("TRQ_MAXREAR",         CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXREAR         , 0, 0, 0),//Maximum torque for rear axle (0-100)
	VDCU_PARAMETER("PWRLIM",              CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM              , 0, 0, 0),//Maximum power in kW (0-140)
	VDCU_PARAMETER("GEN_PWRLIM",          CANDB_VDCU_VDCU_PARAM_VDCU_GEN_PWRLIM          , 0, 0, 0),//Maximum regenerative power in kW (0-40)
	VDCU_PARAMETER("PED_MAP",             CANDB_VDCU_VDCU_PARAM_VDCU_PED_MAP             , 0, 0, 0),//Pedal map selector (0-4)
	VDCU_PARAMETER("TV_DISTRIB",          CANDB_VDCU_VDCU_PARAM_VDCU_TV_DISTRIB          , 0, 0, 0),//Torque distribution to rear (0-100)
	VDCU_PARAMETER("TV_FRONT_GAIN",       CANDB_VDCU_VDCU_PARAM_VDCU_TV_FRONT_GAIN       , 0, 0, 0),//Torque vectoring gain on front axle (0-200)
	VDCU_PARAMETER("TV_REAR_GAIN",        CANDB_VDCU_VDCU_PARAM_VDCU_TV_REAR_GAIN        , 0, 0, 0),//Torque vectoring gain on rear axle (0-200)
	VDCU_PARAMETER("TV_SPEED_DECLINE",    CANDB_VDCU_VDCU_PARAM_VDCU_TV_SPEED_DECLINE    , 0, 0, 0),//Torque  vectoring speed decline (0-100)
	VDCU_PARAMETER("TC_SLIP_SP",          CANDB_VDCU_VDCU_PARAM_VDCU_TC_SLIP_SP          , 0, 0, 0),//Slip ratio controller slip setpoint (4-20)
	VDCU_PARAMETER("YC_REF_GAIN",         CANDB_VDCU_VDCU_PARAM_VDCU_YC_REF_GAIN         , 0, 0, 0),//Yaw rate controller reference gain (0-200)
	VDCU_PARAMETER("YC_GAIN",             CANDB_VDCU_VDCU_PARAM_VDCU_YC_GAIN             , 0, 0, 0),//Yaw controller output gain (0-200)
	VDCU_PARAMETER("FIELDWEAK",           CANDB_VDCU_VDCU_PARAM_VDCU_FIELDWEAK           , 0, 0, 0),//Field weakening (0-100)
	VDCU_PARAMETER("REVERSE_REQ",         CANDB_VDCU_VDCU_PARAM_VDCU_REVERSE_REQ         , 0, 0, 0),//Request for reverse [0,1] (not a parameter)
	VDCU_PARAMETER("RACEMODE_REQ",        CANDB_VDCU_VDCU_PARAM_VDCU_RACEMODE_REQ        , 0, 0, 0),//Racing mode (0-11) (OFF,accel, skid, autox, endu, fun, amateur, transport ...)
	VDCU_PARAMETER("TV_EN",               CANDB_VDCU_VDCU_PARAM_VDCU_TV_EN               , 0, 0, 0),//TorqueVectoring (distribution) enable
	VDCU_PARAMETER("GEN_EN",              CANDB_VDCU_VDCU_PARAM_VDCU_GEN_EN              , 0, 0, 0),//ENABLE regenerative braking [0,1]
	VDCU_PARAMETER("BOOST_EN",            CANDB_VDCU_VDCU_PARAM_VDCU_BOOST_EN            , 0, 0, 0),//ENABLE unlimited performance [0,1]
	VDCU_PARAMETER("TRQ_SPEED_DECLINE",   CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_SPEED_DECLINE   , 0, 0, 0),//Torque speed limitation ramp (0-100)
	VDCU_PARAMETER("TC_THRESHOLD",        CANDB_VDCU_VDCU_PARAM_VDCU_TC_THRESHOLD        , 0, 0, 0),//Slip ratio controller threshold (0-10)
	VDCU_PARAMETER("TC_KP",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KP               , 0, 0, 0),//Slip ratio controller Kp gain (0-200)
	VDCU_PARAMETER("TC_KI",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KI               , 0, 0, 0),//Slip ratio controller Ki gain (0-200)
	VDCU_PARAMETER("TC_KB",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KB               , 0, 0, 0),//Slip ratio controller Kb gain(0-100)
	VDCU_PARAMETER("YC_SPEED_DECLINE",    CANDB_VDCU_VDCU_PARAM_VDCU_YC_SPEED_DECLINE    , 0, 0, 0),//Yaw controller Speed limitation ramp (0-100)
	VDCU_PARAMETER("YC_KP",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KP               , 0, 0, 0),//Yaw controller Kp gain (0-200)
	VDCU_PARAMETER("YC_KI",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KI               , 0, 0, 0),//Yaw controller Ki gain (0-200)
	VDCU_PARAMETER("YC_KB",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KB               , 0, 0, 0),//Yaw controller Kb gain (0-100)
	VDCU_PARAMETER("FEEDFORWARD_GAIN",    CANDB_VDCU_VDCU_PARAM_VDCU_FEEDFORWARD_GAIN    , 0, 0, 0),//Feedforward gain (0-200)
	VDCU_PARAMETER("PWRLIM_RAMP_DECLINE", CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM_RAMP_DECLINE , 0, 0, 0),//Power limiting speed ramp (0-100)
	NULL
};

// ACC
vdcu_param_t *const vdcu_param_set_acc[]={
	VDCU_PARAMETER("TRQ_GAIN",            CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_GAIN            ,  85,   0, 100),//Torque gain (0-100)
	VDCU_PARAMETER("TRQ_MAXFRONT",        CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXFRONT        ,   0,   0, 100),//Maximum torque for front axle (0-100)
	VDCU_PARAMETER("TRQ_MAXREAR",         CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXREAR         ,   0,   0, 100),//Maximum torque for rear axle (0-100)
	VDCU_PARAMETER("PWRLIM",              CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM              ,  80,   0, 140),//Maximum power in kW (0-140)
	VDCU_PARAMETER("GEN_PWRLIM",          CANDB_VDCU_VDCU_PARAM_VDCU_GEN_PWRLIM          ,   0,   0,  40),//Maximum regenerative power in kW (0-40)
	VDCU_PARAMETER("PED_MAP",             CANDB_VDCU_VDCU_PARAM_VDCU_PED_MAP             ,   2,   0,   4),//Pedal map selector (0-4)
	VDCU_PARAMETER("TV_DISTRIB",          CANDB_VDCU_VDCU_PARAM_VDCU_TV_DISTRIB          ,  72,   0, 100),//Torque distribution to rear (0-100)
	VDCU_PARAMETER("TV_FRONT_GAIN",       CANDB_VDCU_VDCU_PARAM_VDCU_TV_FRONT_GAIN       ,   0,   0, 200),//Torque vectoring gain on front axle (0-200)
	VDCU_PARAMETER("TV_REAR_GAIN",        CANDB_VDCU_VDCU_PARAM_VDCU_TV_REAR_GAIN        ,   0,   0, 200),//Torque vectoring gain on rear axle (0-200)
	VDCU_PARAMETER("TV_SPEED_DECLINE",    CANDB_VDCU_VDCU_PARAM_VDCU_TV_SPEED_DECLINE    ,   0,   0, 100),//Torque  vectoring speed decline (0-100)
	VDCU_PARAMETER("TC_SLIP_SP",          CANDB_VDCU_VDCU_PARAM_VDCU_TC_SLIP_SP          ,  15,   4,  30),//Slip ratio controller slip setpoint (4-20)
	VDCU_PARAMETER("YC_REF_GAIN",         CANDB_VDCU_VDCU_PARAM_VDCU_YC_REF_GAIN         ,   0,   0, 200),//Yaw rate controller reference gain (0-200)
	VDCU_PARAMETER("YC_GAIN",             CANDB_VDCU_VDCU_PARAM_VDCU_YC_GAIN             ,   0,   0, 200),//Yaw controller output gain (0-200)
	VDCU_PARAMETER("FIELDWEAK",           CANDB_VDCU_VDCU_PARAM_VDCU_FIELDWEAK           ,  50,   0, 100),//Field weakening (0-100)
	VDCU_PARAMETER("REVERSE_REQ",         CANDB_VDCU_VDCU_PARAM_VDCU_REVERSE_REQ         ,   0,   0,   1),//Request for reverse [0,1] (not a parameter)
	VDCU_PARAMETER("RACEMODE_REQ",        CANDB_VDCU_VDCU_PARAM_VDCU_RACEMODE_REQ        ,   1,   0,  11),//Racing mode (0-11) (OFF,accel, skid, autox, endu, fun, amateur, transport ...)
	VDCU_PARAMETER("TV_EN",               CANDB_VDCU_VDCU_PARAM_VDCU_TV_EN               ,   0,   0,   1),//TorqueVectoring (distribution) enable
	VDCU_PARAMETER("GEN_EN",              CANDB_VDCU_VDCU_PARAM_VDCU_GEN_EN              ,   0,   0,   1),//ENABLE regenerative braking [0,1]
	VDCU_PARAMETER("BOOST_EN",            CANDB_VDCU_VDCU_PARAM_VDCU_BOOST_EN            ,   0,   0,   1),//ENABLE unlimited performance [0,1]
	VDCU_PARAMETER("TRQ_SPEED_DECLINE",   CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_SPEED_DECLINE   ,   0,   0, 100),//Torque speed limitation ramp (0-100)
	VDCU_PARAMETER("TC_THRESHOLD",        CANDB_VDCU_VDCU_PARAM_VDCU_TC_THRESHOLD        ,   2,   0,  10),//Slip ratio controller threshold (0-10)
	VDCU_PARAMETER("TC_KP",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KP               ,   9,   0, 200),//Slip ratio controller Kp gain (0-200)
	VDCU_PARAMETER("TC_KI",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KI               ,   1,   0, 200),//Slip ratio controller Ki gain (0-200)
	VDCU_PARAMETER("TC_KB",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KB               ,   0,   0, 100),//Slip ratio controller Kb gain(0-100)
	VDCU_PARAMETER("YC_SPEED_DECLINE",    CANDB_VDCU_VDCU_PARAM_VDCU_YC_SPEED_DECLINE    ,   0,   0, 100),//Yaw controller Speed limitation ramp (0-100)
	VDCU_PARAMETER("YC_KP",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KP               ,   0,   0, 200),//Yaw controller Kp gain (0-200)
	VDCU_PARAMETER("YC_KI",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KI               ,   0,   0, 200),//Yaw controller Ki gain (0-200)
	VDCU_PARAMETER("YC_KB",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KB               ,   0,   0, 100),//Yaw controller Kb gain (0-100)
	VDCU_PARAMETER("FEEDFORWARD_GAIN",    CANDB_VDCU_VDCU_PARAM_VDCU_FEEDFORWARD_GAIN    ,   0,   0, 200),//Feedforward gain (0-200)
	VDCU_PARAMETER("PWRLIM_RAMP_DECLINE", CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM_RAMP_DECLINE ,   0,   0, 100),//Power limiting speed ramp (0-100)
	NULL
};

// SKID
vdcu_param_t *const vdcu_param_set_skid[]={
	VDCU_PARAMETER("TRQ_GAIN",            CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_GAIN            ,  35,   0, 100),//Torque gain (0-100)
	VDCU_PARAMETER("TRQ_MAXFRONT",        CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXFRONT        ,   0,   0, 100),//Maximum torque for front axle (0-100)
	VDCU_PARAMETER("TRQ_MAXREAR",         CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXREAR         ,   0,   0, 100),//Maximum torque for rear axle (0-100)
	VDCU_PARAMETER("PWRLIM",              CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM              ,  30,   0, 140),//Maximum power in kW (0-140)
	VDCU_PARAMETER("GEN_PWRLIM",          CANDB_VDCU_VDCU_PARAM_VDCU_GEN_PWRLIM          ,   0,   0,  40),//Maximum regenerative power in kW (0-40)
	VDCU_PARAMETER("PED_MAP",             CANDB_VDCU_VDCU_PARAM_VDCU_PED_MAP             ,   1,   0,   4),//Pedal map selector (0-4)
	VDCU_PARAMETER("TV_DISTRIB",          CANDB_VDCU_VDCU_PARAM_VDCU_TV_DISTRIB          ,  68,   0, 100),//Torque distribution to rear (0-100)
	VDCU_PARAMETER("TV_FRONT_GAIN",       CANDB_VDCU_VDCU_PARAM_VDCU_TV_FRONT_GAIN       , 150,   0, 200),//Torque vectoring gain on front axle (0-200)
	VDCU_PARAMETER("TV_REAR_GAIN",        CANDB_VDCU_VDCU_PARAM_VDCU_TV_REAR_GAIN        ,  95,   0, 200),//Torque vectoring gain on rear axle (0-200)
	VDCU_PARAMETER("TV_SPEED_DECLINE",    CANDB_VDCU_VDCU_PARAM_VDCU_TV_SPEED_DECLINE    ,   0,   0, 100),//Torque  vectoring speed decline (0-100)
	VDCU_PARAMETER("TC_SLIP_SP",          CANDB_VDCU_VDCU_PARAM_VDCU_TC_SLIP_SP          ,   8,   4,  30),//Slip ratio controller slip setpoint (4-20)
	VDCU_PARAMETER("YC_REF_GAIN",         CANDB_VDCU_VDCU_PARAM_VDCU_YC_REF_GAIN         , 100,   0, 200),//Yaw rate controller reference gain (0-200)
	VDCU_PARAMETER("YC_GAIN",             CANDB_VDCU_VDCU_PARAM_VDCU_YC_GAIN             , 100,   0, 200),//Yaw controller output gain (0-200)
	VDCU_PARAMETER("FIELDWEAK",           CANDB_VDCU_VDCU_PARAM_VDCU_FIELDWEAK           ,   0,   0, 100),//Field weakening (0-100)
	VDCU_PARAMETER("REVERSE_REQ",         CANDB_VDCU_VDCU_PARAM_VDCU_REVERSE_REQ         ,   0,   0,   1),//Request for reverse [0,1] (not a parameter)
	VDCU_PARAMETER("RACEMODE_REQ",        CANDB_VDCU_VDCU_PARAM_VDCU_RACEMODE_REQ        ,   2,   0,  11),//Racing mode (0-11) (OFF,accel, skid, autox, endu, fun, amateur, transport ...)
	VDCU_PARAMETER("TV_EN",               CANDB_VDCU_VDCU_PARAM_VDCU_TV_EN               ,   0,   0,   1),//TorqueVectoring (distribution) enable
	VDCU_PARAMETER("GEN_EN",              CANDB_VDCU_VDCU_PARAM_VDCU_GEN_EN              ,   0,   0,   1),//ENABLE regenerative braking [0,1]
	VDCU_PARAMETER("BOOST_EN",            CANDB_VDCU_VDCU_PARAM_VDCU_BOOST_EN            ,   0,   0,   1),//ENABLE unlimited performance [0,1]
	VDCU_PARAMETER("TRQ_SPEED_DECLINE",   CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_SPEED_DECLINE   ,   0,   0, 100),//Torque speed limitation ramp (0-100)
	VDCU_PARAMETER("TC_THRESHOLD",        CANDB_VDCU_VDCU_PARAM_VDCU_TC_THRESHOLD        ,   2,   0,  10),//Slip ratio controller threshold (0-10)
	VDCU_PARAMETER("TC_KP",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KP               ,   9,   0, 200),//Slip ratio controller Kp gain (0-200)
	VDCU_PARAMETER("TC_KI",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KI               ,   1,   0, 200),//Slip ratio controller Ki gain (0-200)
	VDCU_PARAMETER("TC_KB",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KB               ,   0,   0, 100),//Slip ratio controller Kb gain(0-100)
	VDCU_PARAMETER("YC_SPEED_DECLINE",    CANDB_VDCU_VDCU_PARAM_VDCU_YC_SPEED_DECLINE    ,   0,   0, 100),//Yaw controller Speed limitation ramp (0-100)
	VDCU_PARAMETER("YC_KP",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KP               ,  50,   0, 200),//Yaw controller Kp gain (0-200)
	VDCU_PARAMETER("YC_KI",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KI               ,  20,   0, 200),//Yaw controller Ki gain (0-200)
	VDCU_PARAMETER("YC_KB",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KB               ,  10,   0, 100),//Yaw controller Kb gain (0-100)
	VDCU_PARAMETER("FEEDFORWARD_GAIN",    CANDB_VDCU_VDCU_PARAM_VDCU_FEEDFORWARD_GAIN    , 100,   0, 200),//Feedforward gain (0-200)
	VDCU_PARAMETER("PWRLIM_RAMP_DECLINE", CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM_RAMP_DECLINE ,   0,   0, 100),//Power limiting speed ramp (0-100)
	NULL
};

//AUTOCROSS
vdcu_param_t *const vdcu_param_set_autox[]={
	VDCU_PARAMETER("TRQ_GAIN",            CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_GAIN            ,  70,   0, 100),//Torque gain (0-100)
	VDCU_PARAMETER("TRQ_MAXFRONT",        CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXFRONT        ,   0,   0, 100),//Maximum torque for front axle (0-100)
	VDCU_PARAMETER("TRQ_MAXREAR",         CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXREAR         ,   0,   0, 100),//Maximum torque for rear axle (0-100)
	VDCU_PARAMETER("PWRLIM",              CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM              ,  80,   0, 140),//Maximum power in kW (0-140)
	VDCU_PARAMETER("GEN_PWRLIM",          CANDB_VDCU_VDCU_PARAM_VDCU_GEN_PWRLIM          ,   0,   0,  40),//Maximum regenerative power in kW (0-40)
	VDCU_PARAMETER("PED_MAP",             CANDB_VDCU_VDCU_PARAM_VDCU_PED_MAP             ,   0,   0,   4),//Pedal map selector (0-4)
	VDCU_PARAMETER("TV_DISTRIB",          CANDB_VDCU_VDCU_PARAM_VDCU_TV_DISTRIB          ,  66,   0, 100),//Torque distribution to rear (0-100)
	VDCU_PARAMETER("TV_FRONT_GAIN",       CANDB_VDCU_VDCU_PARAM_VDCU_TV_FRONT_GAIN       , 130,   0, 200),//Torque vectoring gain on front axle (0-200)
	VDCU_PARAMETER("TV_REAR_GAIN",        CANDB_VDCU_VDCU_PARAM_VDCU_TV_REAR_GAIN        ,  75,   0, 200),//Torque vectoring gain on rear axle (0-200)
	VDCU_PARAMETER("TV_SPEED_DECLINE",    CANDB_VDCU_VDCU_PARAM_VDCU_TV_SPEED_DECLINE    ,   0,   0, 100),//Torque  vectoring speed decline (0-100)
	VDCU_PARAMETER("TC_SLIP_SP",          CANDB_VDCU_VDCU_PARAM_VDCU_TC_SLIP_SP          ,  16,   4,  30),//Slip ratio controller slip setpoint (4-20)
	VDCU_PARAMETER("YC_REF_GAIN",         CANDB_VDCU_VDCU_PARAM_VDCU_YC_REF_GAIN         , 100,   0, 200),//Yaw rate controller reference gain (0-200)
	VDCU_PARAMETER("YC_GAIN",             CANDB_VDCU_VDCU_PARAM_VDCU_YC_GAIN             , 100,   0, 200),//Yaw controller output gain (0-200)
	VDCU_PARAMETER("FIELDWEAK",           CANDB_VDCU_VDCU_PARAM_VDCU_FIELDWEAK           ,  20,   0, 100),//Field weakening (0-100)
	VDCU_PARAMETER("REVERSE_REQ",         CANDB_VDCU_VDCU_PARAM_VDCU_REVERSE_REQ         ,   0,   0,   1),//Request for reverse [0,1] (not a parameter)
	VDCU_PARAMETER("RACEMODE_REQ",        CANDB_VDCU_VDCU_PARAM_VDCU_RACEMODE_REQ        ,   3,   0,  11),//Racing mode (0-11) (OFF,accel, skid, autox, endu, fun, amateur, transport ...)
	VDCU_PARAMETER("TV_EN",               CANDB_VDCU_VDCU_PARAM_VDCU_TV_EN               ,   0,   0,   1),//TorqueVectoring (distribution) enable
	VDCU_PARAMETER("GEN_EN",              CANDB_VDCU_VDCU_PARAM_VDCU_GEN_EN              ,   0,   0,   1),//ENABLE regenerative braking [0,1]
	VDCU_PARAMETER("BOOST_EN",            CANDB_VDCU_VDCU_PARAM_VDCU_BOOST_EN            ,   0,   0,   1),//ENABLE unlimited performance [0,1]
	VDCU_PARAMETER("TRQ_SPEED_DECLINE",   CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_SPEED_DECLINE   ,   0,   0, 100),//Torque speed limitation ramp (0-100)
	VDCU_PARAMETER("TC_THRESHOLD",        CANDB_VDCU_VDCU_PARAM_VDCU_TC_THRESHOLD        ,   2,   0,  10),//Slip ratio controller threshold (0-10)
	VDCU_PARAMETER("TC_KP",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KP               ,   9,   0, 200),//Slip ratio controller Kp gain (0-200)
	VDCU_PARAMETER("TC_KI",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KI               ,   1,   0, 200),//Slip ratio controller Ki gain (0-200)
	VDCU_PARAMETER("TC_KB",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KB               ,   0,   0, 100),//Slip ratio controller Kb gain(0-100)
	VDCU_PARAMETER("YC_SPEED_DECLINE",    CANDB_VDCU_VDCU_PARAM_VDCU_YC_SPEED_DECLINE    ,   0,   0, 100),//Yaw controller Speed limitation ramp (0-100)
	VDCU_PARAMETER("YC_KP",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KP               ,  50,   0, 200),//Yaw controller Kp gain (0-200)
	VDCU_PARAMETER("YC_KI",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KI               ,  20,   0, 200),//Yaw controller Ki gain (0-200)
	VDCU_PARAMETER("YC_KB",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KB               ,  10,   0, 100),//Yaw controller Kb gain (0-100)
	VDCU_PARAMETER("FEEDFORWARD_GAIN",    CANDB_VDCU_VDCU_PARAM_VDCU_FEEDFORWARD_GAIN    , 100,   0, 200),//Feedforward gain (0-200)
	VDCU_PARAMETER("PWRLIM_RAMP_DECLINE", CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM_RAMP_DECLINE ,   0,   0, 100),//Power limiting speed ramp (0-100)
	NULL
};

//ENDURANCE
vdcu_param_t *const vdcu_param_set_endurance[]={
	VDCU_PARAMETER("TRQ_GAIN",            CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_GAIN            ,  60,   0, 100),//Torque gain (0-100)
	VDCU_PARAMETER("TRQ_MAXFRONT",        CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXFRONT        ,   0,   0, 100),//Maximum torque for front axle (0-100)
	VDCU_PARAMETER("TRQ_MAXREAR",         CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXREAR         ,   0,   0, 100),//Maximum torque for rear axle (0-100)
	VDCU_PARAMETER("PWRLIM",              CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM              ,  42,   0, 140),//Maximum power in kW (0-140)
	VDCU_PARAMETER("GEN_PWRLIM",          CANDB_VDCU_VDCU_PARAM_VDCU_GEN_PWRLIM          ,   0,   0,  40),//Maximum regenerative power in kW (0-40)
	VDCU_PARAMETER("PED_MAP",             CANDB_VDCU_VDCU_PARAM_VDCU_PED_MAP             ,   0,   0,   4),//Pedal map selector (0-4)
	VDCU_PARAMETER("TV_DISTRIB",          CANDB_VDCU_VDCU_PARAM_VDCU_TV_DISTRIB          ,  69,   0, 100),//Torque distribution to rear (0-100)
	VDCU_PARAMETER("TV_FRONT_GAIN",       CANDB_VDCU_VDCU_PARAM_VDCU_TV_FRONT_GAIN       ,  95,   0, 200),//Torque vectoring gain on front axle (0-200)
	VDCU_PARAMETER("TV_REAR_GAIN",        CANDB_VDCU_VDCU_PARAM_VDCU_TV_REAR_GAIN        ,  70,   0, 200),//Torque vectoring gain on rear axle (0-200)
	VDCU_PARAMETER("TV_SPEED_DECLINE",    CANDB_VDCU_VDCU_PARAM_VDCU_TV_SPEED_DECLINE    ,   0,   0, 100),//Torque  vectoring speed decline (0-100)
	VDCU_PARAMETER("TC_SLIP_SP",          CANDB_VDCU_VDCU_PARAM_VDCU_TC_SLIP_SP          ,  12,   4,  30),//Slip ratio controller slip setpoint (4-20)
	VDCU_PARAMETER("YC_REF_GAIN",         CANDB_VDCU_VDCU_PARAM_VDCU_YC_REF_GAIN         , 100,   0, 200),//Yaw rate controller reference gain (0-200)
	VDCU_PARAMETER("YC_GAIN",             CANDB_VDCU_VDCU_PARAM_VDCU_YC_GAIN             , 100,   0, 200),//Yaw controller output gain (0-200)
	VDCU_PARAMETER("FIELDWEAK",           CANDB_VDCU_VDCU_PARAM_VDCU_FIELDWEAK           ,   0,   0, 100),//Field weakening (0-100)
	VDCU_PARAMETER("REVERSE_REQ",         CANDB_VDCU_VDCU_PARAM_VDCU_REVERSE_REQ         ,   0,   0,   1),//Request for reverse [0,1] (not a parameter)
	VDCU_PARAMETER("RACEMODE_REQ",        CANDB_VDCU_VDCU_PARAM_VDCU_RACEMODE_REQ        ,   4,   0,  11),//Racing mode (0-11) (OFF,accel, skid, autox, endu, fun, amateur, transport ...)
	VDCU_PARAMETER("TV_EN",               CANDB_VDCU_VDCU_PARAM_VDCU_TV_EN               ,   0,   0,   1),//TorqueVectoring (distribution) enable
	VDCU_PARAMETER("GEN_EN",              CANDB_VDCU_VDCU_PARAM_VDCU_GEN_EN              ,   0,   0,   1),//ENABLE regenerative braking [0,1]
	VDCU_PARAMETER("BOOST_EN",            CANDB_VDCU_VDCU_PARAM_VDCU_BOOST_EN            ,   0,   0,   1),//ENABLE unlimited performance [0,1]
	VDCU_PARAMETER("TRQ_SPEED_DECLINE",   CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_SPEED_DECLINE   ,   0,   0, 100),//Torque speed limitation ramp (0-100)
	VDCU_PARAMETER("TC_THRESHOLD",        CANDB_VDCU_VDCU_PARAM_VDCU_TC_THRESHOLD        ,   2,   0,  10),//Slip ratio controller threshold (0-10)
	VDCU_PARAMETER("TC_KP",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KP               ,   9,   0, 200),//Slip ratio controller Kp gain (0-200)
	VDCU_PARAMETER("TC_KI",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KI               ,   1,   0, 200),//Slip ratio controller Ki gain (0-200)
	VDCU_PARAMETER("TC_KB",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KB               ,   0,   0, 100),//Slip ratio controller Kb gain(0-100)
	VDCU_PARAMETER("YC_SPEED_DECLINE",    CANDB_VDCU_VDCU_PARAM_VDCU_YC_SPEED_DECLINE    ,   0,   0, 100),//Yaw controller Speed limitation ramp (0-100)
	VDCU_PARAMETER("YC_KP",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KP               ,  50,   0, 200),//Yaw controller Kp gain (0-200)
	VDCU_PARAMETER("YC_KI",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KI               ,  20,   0, 200),//Yaw controller Ki gain (0-200)
	VDCU_PARAMETER("YC_KB",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KB               ,  10,   0, 100),//Yaw controller Kb gain (0-100)
	VDCU_PARAMETER("FEEDFORWARD_GAIN",    CANDB_VDCU_VDCU_PARAM_VDCU_FEEDFORWARD_GAIN    , 100,   0, 200),//Feedforward gain (0-200)
	VDCU_PARAMETER("PWRLIM_RAMP_DECLINE", CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM_RAMP_DECLINE , 100,   0, 100),//Power limiting speed ramp (0-100)
	NULL
};

//DEMO
vdcu_param_t *const vdcu_param_set_demo[]={
	VDCU_PARAMETER("TRQ_GAIN",            CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_GAIN            ,  45,   0, 100),//Torque gain (0-100)
	VDCU_PARAMETER("TRQ_MAXFRONT",        CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXFRONT        ,   0,   0, 100),//Maximum torque for front axle (0-100)
	VDCU_PARAMETER("TRQ_MAXREAR",         CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_MAXREAR         ,   0,   0, 100),//Maximum torque for rear axle (0-100)
	VDCU_PARAMETER("PWRLIM",              CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM              ,  35,   0, 140),//Maximum power in kW (0-140)
	VDCU_PARAMETER("GEN_PWRLIM",          CANDB_VDCU_VDCU_PARAM_VDCU_GEN_PWRLIM          ,   0,   0,  40),//Maximum regenerative power in kW (0-40)
	VDCU_PARAMETER("PED_MAP",             CANDB_VDCU_VDCU_PARAM_VDCU_PED_MAP             ,   0,   0,   4),//Pedal map selector (0-4)
	VDCU_PARAMETER("TV_DISTRIB",          CANDB_VDCU_VDCU_PARAM_VDCU_TV_DISTRIB          ,  66,   0, 100),//Torque distribution to rear (0-100)
	VDCU_PARAMETER("TV_FRONT_GAIN",       CANDB_VDCU_VDCU_PARAM_VDCU_TV_FRONT_GAIN       , 130,   0, 200),//Torque vectoring gain on front axle (0-200)
	VDCU_PARAMETER("TV_REAR_GAIN",        CANDB_VDCU_VDCU_PARAM_VDCU_TV_REAR_GAIN        ,  75,   0, 200),//Torque vectoring gain on rear axle (0-200)
	VDCU_PARAMETER("TV_SPEED_DECLINE",    CANDB_VDCU_VDCU_PARAM_VDCU_TV_SPEED_DECLINE    ,   0,   0, 100),//Torque  vectoring speed decline (0-100)
	VDCU_PARAMETER("TC_SLIP_SP",          CANDB_VDCU_VDCU_PARAM_VDCU_TC_SLIP_SP          ,  16,   4,  30),//Slip ratio controller slip setpoint (4-20)
	VDCU_PARAMETER("YC_REF_GAIN",         CANDB_VDCU_VDCU_PARAM_VDCU_YC_REF_GAIN         , 100,   0, 200),//Yaw rate controller reference gain (0-200)
	VDCU_PARAMETER("YC_GAIN",             CANDB_VDCU_VDCU_PARAM_VDCU_YC_GAIN             , 100,   0, 200),//Yaw controller output gain (0-200)
	VDCU_PARAMETER("FIELDWEAK",           CANDB_VDCU_VDCU_PARAM_VDCU_FIELDWEAK           ,  20,   0, 100),//Field weakening (0-100)
	VDCU_PARAMETER("REVERSE_REQ",         CANDB_VDCU_VDCU_PARAM_VDCU_REVERSE_REQ         ,   0,   0,   1),//Request for reverse [0,1] (not a parameter)
	VDCU_PARAMETER("RACEMODE_REQ",        CANDB_VDCU_VDCU_PARAM_VDCU_RACEMODE_REQ        ,   3,   0,  11),//Racing mode (0-11) (OFF,accel, skid, autox, endu, fun, amateur, transport ...)
	VDCU_PARAMETER("TV_EN",               CANDB_VDCU_VDCU_PARAM_VDCU_TV_EN               ,   0,   0,   1),//TorqueVectoring (distribution) enable
	VDCU_PARAMETER("GEN_EN",              CANDB_VDCU_VDCU_PARAM_VDCU_GEN_EN              ,   0,   0,   1),//ENABLE regenerative braking [0,1]
	VDCU_PARAMETER("BOOST_EN",            CANDB_VDCU_VDCU_PARAM_VDCU_BOOST_EN            ,   0,   0,   1),//ENABLE unlimited performance [0,1]
	VDCU_PARAMETER("TRQ_SPEED_DECLINE",   CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_SPEED_DECLINE   ,   0,   0, 100),//Torque speed limitation ramp (0-100)
	VDCU_PARAMETER("TC_THRESHOLD",        CANDB_VDCU_VDCU_PARAM_VDCU_TC_THRESHOLD        ,   2,   0,  10),//Slip ratio controller threshold (0-10)
	VDCU_PARAMETER("TC_KP",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KP               ,   9,   0, 200),//Slip ratio controller Kp gain (0-200)
	VDCU_PARAMETER("TC_KI",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KI               ,   1,   0, 200),//Slip ratio controller Ki gain (0-200)
	VDCU_PARAMETER("TC_KB",               CANDB_VDCU_VDCU_PARAM_VDCU_TC_KB               ,   0,   0, 100),//Slip ratio controller Kb gain(0-100)
	VDCU_PARAMETER("YC_SPEED_DECLINE",    CANDB_VDCU_VDCU_PARAM_VDCU_YC_SPEED_DECLINE    ,   0,   0, 100),//Yaw controller Speed limitation ramp (0-100)
	VDCU_PARAMETER("YC_KP",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KP               ,  50,   0, 200),//Yaw controller Kp gain (0-200)
	VDCU_PARAMETER("YC_KI",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KI               ,  20,   0, 200),//Yaw controller Ki gain (0-200)
	VDCU_PARAMETER("YC_KB",               CANDB_VDCU_VDCU_PARAM_VDCU_YC_KB               ,  10,   0, 100),//Yaw controller Kb gain (0-100)
	VDCU_PARAMETER("FEEDFORWARD_GAIN",    CANDB_VDCU_VDCU_PARAM_VDCU_FEEDFORWARD_GAIN    , 100,   0, 200),//Feedforward gain (0-200)
	VDCU_PARAMETER("PWRLIM_RAMP_DECLINE", CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM_RAMP_DECLINE ,   0,   0, 100),//Power limiting speed ramp (0-100)
	NULL
};



parameter_set_t parameters={
	.selected = 0,
	.vdcu_param_set = vdcu_param_set_idle,
};

void qei1_event_callback(qei_event_t event, uint32_t pos)
{
	UNUSED(pos);

	if(params_window.active)
	{
		params_window.last_action_ts = SysTick_uptime();	
		switch(event)
		{
			case QEI_EVT_INC:
				gui_current_param_change(&parameters, true);
				break;

			case QEI_EVT_DEC:
				gui_current_param_change(&parameters, false);
				break;
		}
		return;
			
	}

	if(displayed == DISPLAYED_MENU)
	{
		menu_last_activity_ts = SysTick_uptime();
		switch(event)
		{
			case QEI_EVT_INC:
				gui_menu_event(&menu, MENU_EVT_DEC);
				break;
			
			case QEI_EVT_DEC:
				gui_menu_event(&menu, MENU_EVT_INC);
				break;
		}
	}
	else if(displayed == DISPLAYED_RACE_SCREEN)
	{
		switch(event)
		{
			case QEI_EVT_INC:
				if(screen_idx<6)
					screen_idx++;
				break;
			
			case QEI_EVT_DEC:
				if(screen_idx>0)
					screen_idx--;
				break;
		}
	}
}

qei_handle_t qei_1 = {
	.gpio_lvl={.port=GPIOA, .bit=0},
	.gpio_edge={.port=GPIOA, .bit=2},
	.position=0,
	.reverse_direction=false,
	.act_on_rising=false,
	.act_on_falling=true,
	.sensitive=QEI_EVT_DEC | QEI_EVT_INC,
	.event_callback=qei1_event_callback,
	.evt_prescaler=2,
};

void fps_record(void)
{
	frame_timestamp_prev = frame_timestamp_last;
	frame_timestamp_last = SysTick_uptime();
}

void dpot_1_callback(uint8_t new_slot)
{
	DEBUG_STR("new slot: ");
	DEBUG_NUM(new_slot, 3);
	DEBUG_NL();
}

dent_pot_t dpot_1={
	.callback=dpot_1_callback,
	.data=&adc_ain1,
	.slot_tolerance=15,
	.slot_positions=(int16_t []){5, 57, 440, 912, 1452, 2032, 2640, 3183, 3640, 4030, 4090, -1},
	.slots=11,
	.current_slot=0,
};

void qei_btn_callback(button_t *btn, button_event_t event)
{
	qei_1.evt_cnt=0;//reset rot cont on qe push
	UNUSED(btn);
	// DEBUG_STR("BTN Q1 ");
	switch(event)
	{
		case BTN_EVT_PRESS:
			// DEBUG_STR("PRESS");
			switch(displayed)
			{
				case DISPLAYED_MENU:
					menu_last_activity_ts = SysTick_uptime();
					if(!gui_menu_event(&menu, MENU_EVT_ENTER))
					{
						displayed = DISPLAYED_RACE_SCREEN;
						DEBUG_STR("LEAVING MENU\n");
					}
					break;
				
				case DISPLAYED_RACE_SCREEN:
						menu_last_activity_ts = SysTick_uptime();
						menu.current_menu = testing_menu;
						displayed = DISPLAYED_MENU;
					break;
			}
			break;

		case BTN_EVT_RELEASE:
			// DEBUG_STR("RELEASE");
			break;

		case BTN_EVT_HOLD_TIMEOUT:
			// DEBUG_STR("TIMEOUT");
			break;

		case BTN_EVT_CLICK:
			// DEBUG_STR("CLICK");
			break;
		
		case BTN_EVT_CLICK_LONG:
			// DEBUG_STR("CLICK_LONG");
			break;
		
		default:
			break;
	}
	DEBUG_NL();
}

#define BUTTON(NAME, ID, GPIO_PORT, GPIO_BIT, CALLBACK, HOLD_THR, LONG_CLICK_THR, ACT_HIGH, SENSITIVE)	\
	(button_t []){{\
		.name=NAME,\
		.id=ID,\
		.callback=CALLBACK,\
		.gpio={GPIO_PORT, GPIO_BIT},\
		.clicks=0,\
		.sensitive=SENSITIVE,\
		.hold_time=0,\
		.hold_threshold=HOLD_THR,\
		.click_long_threshold=LONG_CLICK_THR,\
		.active_high=ACT_HIGH,	\
	}}


typedef enum{
	BTN_1_WHITE = 1,
	BTN_2_YELLOW,
	BTN_3_BLUE,
	BTN_4_RED,
}btn_id_t;

struct{
	bool active;
}boost = {.active=false};

struct{
	enum{
		REVERSE_OFF,
		REVERSE_ON,
		REVERSE_TOO_FAST
	}state;
}reverse = {.state=REVERSE_OFF};

void btn_default_handler(button_t *btn, button_event_t event)
{
	if(params_window.active)
	{
		params_window.last_action_ts = SysTick_uptime();	
		switch(btn->id)
		{
			case BTN_1_WHITE:
				switch(event)
				{
					case BTN_EVT_PRESS:
						params_window.active = false;
						return;

					default: break;
				}
				break;

			case BTN_2_YELLOW:
				switch(event)
				{	
					default: break;
				}
				break;

			case BTN_3_BLUE:
				switch(event)
				{
					//select next param
					case BTN_EVT_PRESS:
						if(parameters.vdcu_param_set[parameters.selected + 1] != NULL)
							parameters.selected++;
						else
							parameters.selected = 0;//overflow to start
						return;

					default: break;
				}
				break;

			case BTN_4_RED:
				switch(event)
				{
					//select prev param
					case BTN_EVT_PRESS:
						if(parameters.selected>0)
							parameters.selected--;
						else
						{
							uint8_t end=0;
							while(parameters.vdcu_param_set[end+1]!=NULL)
								end++;
							parameters.selected = end;
						}
						return;

					default: break;
				}
				break;
		}
		return;
	}

	//default btn handling
	switch(btn->id)
	{
		case BTN_1_WHITE:
			switch(event)
			{
				case BTN_EVT_HOLD_TIMEOUT:
					params_window.active = true;
					params_window.last_action_ts = SysTick_uptime();
					break;

				default: break;
			}
			break;

		case BTN_2_YELLOW:
			switch(event)
			{
				case BTN_EVT_PRESS:
					{
						TODO("hard reset boost parameter on set change");
						boost.active = true;
						vdcu_param_t *parameter = vdcu_param_get(parameters.vdcu_param_set, CANDB_VDCU_VDCU_PARAM_VDCU_BOOST_EN);
						if(parameter == NULL)
						{
							DEBUG_CRITICAL_STR("PARAM ID not found! (");
							DEBUG_CRITICAL_NUM(CANDB_VDCU_VDCU_PARAM_VDCU_BOOST_EN,2);
							DEBUG_CRITICAL_STR(")\n");
							break;
						}
						vdcu_param_change(parameter, 1);
					}
					break;
				
				case BTN_EVT_RELEASE:
					{
						boost.active = false;
						vdcu_param_t *parameter = vdcu_param_get(parameters.vdcu_param_set, CANDB_VDCU_VDCU_PARAM_VDCU_BOOST_EN);
						if(parameter == NULL)
						{
							DEBUG_CRITICAL_STR("PARAM ID not found! (");
							DEBUG_CRITICAL_NUM(CANDB_VDCU_VDCU_PARAM_VDCU_BOOST_EN,2);
							DEBUG_CRITICAL_STR(")\n");
							break;
						}
						vdcu_param_change(parameter, 0);
					}
					break;
				
				default: break;
			}
			break;

		case BTN_3_BLUE:
			switch(event)
			{
				case BTN_EVT_CLICK:
				case BTN_EVT_CLICK_LONG:
					gui_current_param_change(&parameters, false);
					return;

				default: break;
			}
			break;

		case BTN_4_RED:
			switch(event)
			{
				case BTN_EVT_CLICK:
				case BTN_EVT_CLICK_LONG:
					gui_current_param_change(&parameters, true);
					return;


				case BTN_EVT_HOLD_TIMEOUT:
					{
						TODO("hard reset reverse parameter on set change");
						float speed;
						candb_field_num_converted(candb_messages[CANDB_MSG_VDCU_BODY]->fields[CANDB_VDCU_BODY_FIELD_SPEED_REF], 0, &speed);
						if(speed < 1)
						{
							reverse.state = REVERSE_ON;
							vdcu_param_t *parameter = vdcu_param_get(parameters.vdcu_param_set, CANDB_VDCU_VDCU_PARAM_VDCU_REVERSE_REQ);
							vdcu_param_change(parameter, 1);
						}
						else
							reverse.state = REVERSE_TOO_FAST;
					}
					break;
				
				case BTN_EVT_RELEASE:
					{
						reverse.state = REVERSE_OFF;;
						vdcu_param_t *parameter = vdcu_param_get(parameters.vdcu_param_set, CANDB_VDCU_VDCU_PARAM_VDCU_REVERSE_REQ);
						vdcu_param_change(parameter, 0);
					}
					break;

				default: break;
			}
			break;
	}
}

button_t *const buttons[]={
	BUTTON("BLUE",		BTN_3_BLUE   , GPIOH,  6, btn_default_handler, 25, 8, false, BTN_EVT_ALL),
	BUTTON("WHITE",		BTN_1_WHITE  , GPIOH,  7, btn_default_handler, 25, 8, false, BTN_EVT_ALL),
	BUTTON("YELLOW",	BTN_2_YELLOW , GPIOB, 15, btn_default_handler, 25, 8, false, BTN_EVT_ALL),
	BUTTON("RED",		BTN_4_RED    , GPIOD, 11, btn_default_handler, 25, 8, false, BTN_EVT_ALL),
	BUTTON("QEI1 BTN",			    0, GPIOH,  2, qei_btn_callback,    25, 8, false, BTN_EVT_ALL),
	NULL
};


can_msg_t can1_tx_buffer[CAN_TX_BUFFER_SIZE] __attribute__ ((section ("sram1"))) __attribute__ ((aligned (4)));;
circular_buffer_t can1_tx_cb=CB_INIT_STATIC(can1_tx_buffer, "C1 TX");

can_msg_t can1_rx_buffer[CAN_RX_BUFFER_SIZE] __attribute__ ((section ("sram1"))) __attribute__ ((aligned (4)));;
circular_buffer_t can1_rx_cb=CB_INIT_STATIC(can1_rx_buffer, "C1 RX");

//rx buffers can be merged if necessary
can_msg_t can2_rx_buffer[CAN_RX_BUFFER_SIZE] __attribute__ ((section ("sram1"))) __attribute__ ((aligned (4)));;
circular_buffer_t can2_rx_cb=CB_INIT_STATIC(can2_rx_buffer, "C2 RX");


can_dual_handle_t can_dual_handle={
	.can1={.txcb=&can1_tx_cb,	.rxcb=&can1_rx_cb,	.can=CAN1},
	.can2={.txcb=NULL,			.rxcb=&can2_rx_cb,	.can=CAN2},
	.can1_filters_count = 1,
	.filter={
		CAN_FILTER_MASK32(0, 0, 0x00000000),
		CAN_FILTER_MASK32(0, 0, 0x00000000)
	}
};



void SysTick_callback(uint32_t time_ms)
{
	UNUSED(time_ms);
	static uint8_t seq=0;
	switch(time_ms%1000)
	{
		case 500:
			gpio_set(LED4);
			break;

		case 0:
			gpio_clr(LED4);
			DEBUG_STR("FPS: ");
			DEBUG_NUM(redraws,3);
			// DEBUG_NL();
			redraws=0;
			DEBUG_STR(" LOOPS: ");
			DEBUG_NUM(loops_per_second,8);
			DEBUG_NL();
			loops_per_second=0;
			// DEBUG_STR("ADC:\n");
			// DEBUG_NUM(adc_ain1,6);
			// DEBUG_NUM(adc_ain2,6);
			// DEBUG_NL();

			seq++;
			if(seq>=16)
				seq=0;

			break;
	}
	if(time_ms%VDCU_PARAM_PERIODIC_UPDATE_MS == 0)
	{
		vdcu_param_periodic_update(parameters.vdcu_param_set);
	}

	if(time_ms%100==0)
	{
		if(time_ms>1000)
			ECUS_send_Status(seq);
	}
	if(time_ms%20==0)
	{
		button_process(buttons);
	}
	dent_pot_process(&dpot_1);
	adc_ain1=adc_avg(ADC_AIN1_INDEX);
	adc_ain2=adc_avg(ADC_AIN2_INDEX);
	adc_trigger();
}

void SystemInit(void)
{
	SCB->CPACR |= ((3UL << 10*2) | (3UL << 11*2)  );/* set CP11 and CP10 Full Access (3) - Float coprocessors*/
	gpio_init();
	clock_init();
	NVIC_EnableIRQ(NonMaskableInt_IRQn);
	NVIC_EnableIRQ(MemoryManagement_IRQn);
	NVIC_EnableIRQ(BusFault_IRQn);
	NVIC_EnableIRQ(UsageFault_IRQn);
	SysTick_init(SysTick_callback);
	__enable_irq();
}

void lcd_reset(void)
{
	gpio_clr(LCD_nRST);
	delay_ms(10);
	gpio_set(LCD_nRST);
	delay_ms(50);
}

struct ili9806e_handle IL_handle={
	.spi=&LCD_SPI,
	.spi_write=spi_write16,
	.spi_start=spi_start,
	.spi_end=spi_end,
	.lcd_reset=lcd_reset
};

#define I2C_TASK_BUFFER_SIZE	100
i2c_task_t i2c4_task_buffer[I2C_TASK_BUFFER_SIZE];
circular_buffer_t i2c4_cb=CB_INIT_STATIC(i2c4_task_buffer, "I2C");

i2c_handle_t i2c4_handle={
	.dev=I2C4,
	.cb=&i2c4_cb,
	.current_task={
		.type=I2C_TASK_IDLE,
	}
};

gt_handle_t gt_handle={
	.i2c=&i2c4_handle,
	.callback=NULL
};

ltdc_fb_t lcd_fb[LCD_BUFFERS]=
{
	{	
		.layer={
			{.address=SDRAM_ADDR_BANK_0, LCD_PIX_FMT_RGB565, LTDC_Layer1, true},
			{.address=SDRAM_ADDR_BANK_1, LCD_PIX_FMT_RGB565, LTDC_Layer2, false},
		},
		.state=LCD_FB_STATE_DISPLAYING
	},
	{	
		.layer={
			{.address=SDRAM_ADDR_BANK_2, LCD_PIX_FMT_RGB565, LTDC_Layer1, true},
			{.address=SDRAM_ADDR_BANK_3, LCD_PIX_FMT_RGB565, LTDC_Layer2, false},
		},
		.state=LCD_FB_STATE_READY_TO_DRAW
	}
};

void CAN1_TX_IRQHandler(void)
{
	// DEBUG_STR("CAN msg xfer to hw fifo\n");
	can_tx_irq_handler(&can_dual_handle.can1);
}

void CAN1_RX0_IRQHandler(void)
{
	can_rx_irq_handler(&can_dual_handle.can1);
}

void CAN2_RX0_IRQHandler(void)
{
	can_rx_irq_handler(&can_dual_handle.can2);
}

void gt_irq(void)
{
	gpio_set(LED1);
	gt_handle_irq(&gt_handle);
	DEBUG_STR("GT irq\n");
	gpio_clr(LED1);
}

/**
 * @brief 
 * 
 * @param rxcb pointer ot circular buffer of received can messages 
 * @param all bult/single message
 * | value | behavior |
 * | ------| -------- |
 * | true  | process all messages in buffer untill empty |
 * | false | false only first message (useful if executed in loop) |
 * @return status_t 
 */
status_t can_process_messages(circular_buffer_t *rxcb, bool all)
{
	can_msg_t msg; 
	status_t status=STAT_OK;
	bool has_messages=true;
	do
	{
		CpuCriticalBlock(
			//do not use return in CPU ritical block!
			if(cb_used_space(rxcb)>0)
			{
				status = cb_pop(rxcb, &msg);
			}
			else
			{
				has_messages=false;
			}
		);
		if(status!=STAT_OK)
		{
			DEBUG_STR("CAN process failed\n");
			return status;
		}

		if(!has_messages)
		{
			return STAT_OK;
		}
		candb_decode(msg.ID.Std, msg.length, msg.data);
		// DEBUG_STR("MSG\n");
	}while(all);
	return STAT_OK;
}	

void qei_1_callback(void)
{
	qei_callback(&qei_1);
	DEBUG_STR("QEI 1: ");
	DEBUG_NUM(qei_1.position, 6);
	DEBUG_NL();
}

#define NK_ALLOCATED_BUFFER_SIZE	(1024*20)

uint8_t nk_fixed_buffer[NK_ALLOCATED_BUFFER_SIZE] __attribute__ ((section ("sram1"))) __attribute__ ((aligned (4)));

struct nk_context *ctx=&(struct nk_context){};

void vdcu_param_ack_handler_wrapper(const struct candb_msg *msg)
{
	vdcu_param_ack_handler(msg, parameters.vdcu_param_set);
}

int main(void)
{
	delay_ms(10);

	bit_set(RCC->APB1ENR, RCC_APB1ENR_CAN1EN);
	bit_set(RCC->APB1ENR, RCC_APB1ENR_CAN2EN);
	bit_set(RCC->APB1ENR, RCC_APB1ENR_I2C4EN);

	bit_set(RCC->APB2ENR, RCC_APB2ENR_SPI4EN);
	bit_set(RCC->APB2ENR, RCC_APB2ENR_LTDCEN);
	bit_set(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);
	bit_set(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);

	bit_set(RCC->AHB1ENR, RCC_AHB1ENR_DMA2DEN);
	bit_set(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN);

	bit_set(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN);

	*(candb_messages[CANDB_MSG_VDCU_PARAM_ACK]->callback) = vdcu_param_ack_handler_wrapper;


	delay_ms(20);
	debug_init();
	DEBUG_STR("FSE07 ECUS starting...\n");

	DEBUG_STR("NK init\n");
	nk_init_fixed(ctx, nk_fixed_buffer, NK_ALLOCATED_BUFFER_SIZE, &font_nk_default);
	DEBUG_STR("done\n");

	{
		struct nk_color table[NK_COLOR_COUNT];
		table[NK_COLOR_TEXT] =                    nk_rgba(255, 255, 255, 255);
		table[NK_COLOR_WINDOW] =                  nk_rgba( 10,  10,  15, 255);
		table[NK_COLOR_HEADER] =                  nk_rgba(150,  60,   0, 255);
		table[NK_COLOR_BORDER] =                  nk_rgba(  0, 200,   0, 255);
		table[NK_COLOR_BUTTON] =                  nk_rgba(230,  90,   0, 255);
		table[NK_COLOR_BUTTON_HOVER] =            nk_rgba(255, 255, 255, 255);
		table[NK_COLOR_BUTTON_ACTIVE] =           nk_rgba(230,  20,   0, 255);
		table[NK_COLOR_TOGGLE] =                  nk_rgba( 51,  55,  67, 255);
		table[NK_COLOR_TOGGLE_HOVER] =            nk_rgba( 45,  60,  60, 255);
		table[NK_COLOR_TOGGLE_CURSOR] =           nk_rgba(150,  60,   0, 255);
		table[NK_COLOR_SELECT] =                  nk_rgba( 51,  55,  67, 255);
		table[NK_COLOR_SELECT_ACTIVE] =           nk_rgba(150,  60,   0, 255);
		table[NK_COLOR_SLIDER] =                  nk_rgba( 51,  55,  67, 255);
		table[NK_COLOR_SLIDER_CURSOR] =           nk_rgba(150,  60,   0, 255);
		table[NK_COLOR_SLIDER_CURSOR_HOVER] =     nk_rgba(186,  50,  74, 255);
		table[NK_COLOR_SLIDER_CURSOR_ACTIVE] =    nk_rgba(191,  55,  79, 255);
		table[NK_COLOR_PROPERTY] =                nk_rgba( 51,  55,  67, 255);
		table[NK_COLOR_EDIT] =                    nk_rgba( 51,  55,  67, 255);
		table[NK_COLOR_EDIT_CURSOR] =             nk_rgba(190, 190, 190, 255);
		table[NK_COLOR_COMBO] =                   nk_rgba( 51,  55,  67, 255);
		table[NK_COLOR_CHART] =                   nk_rgba( 51,  55,  67, 255);
		table[NK_COLOR_CHART_COLOR] =             nk_rgba(150,  60,   0, 255);
		table[NK_COLOR_CHART_COLOR_HIGHLIGHT] =   nk_rgba(230,  90,   0, 255);
		table[NK_COLOR_SCROLLBAR] =               nk_rgba( 30,  33,  40, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR] =        nk_rgba( 64,  84,  95, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] =  nk_rgba( 70,  90, 100, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba( 75,  95, 105, 255);
		table[NK_COLOR_TAB_HEADER] =              nk_rgba(150,  60,   0, 255);
		nk_style_from_table(ctx, table);
	}

	exti_init();
	adc_init();

	NVIC_SetPriority(CAN1_TX_IRQn, CAN1_TX_IRQ_PRIORITY);
	NVIC_EnableIRQ(CAN1_TX_IRQn);

	NVIC_SetPriority(CAN1_RX0_IRQn, CAN1_RX_IRQ_PRIORITY);
	NVIC_EnableIRQ(CAN1_RX0_IRQn);

	NVIC_SetPriority(CAN2_RX0_IRQn, CAN1_RX_IRQ_PRIORITY);
	NVIC_EnableIRQ(CAN2_RX0_IRQn);

	NVIC_SetPriority(CAN1_SCE_IRQn, IRQ_PRIORITY(1,7));
	NVIC_EnableIRQ(CAN1_SCE_IRQn);

	NVIC_SetPriority(CAN2_SCE_IRQn, IRQ_PRIORITY(1,7));
	NVIC_EnableIRQ(CAN2_SCE_IRQn);

	delay_ms(50);
	GPIOA->BSRR = GPIO_BSRR_BS_10;//TC enable (disable reset)
	delay_ms(50);

	exti_register_callback(9, GPIOA, false, true, gt_irq);//PA9 TC int

	exti_register_callback(qei_1.gpio_edge.bit, qei_1.gpio_edge.port, qei_1.act_on_rising, qei_1.act_on_falling, qei_1_callback);

	NVIC_EnableIRQ(I2C4_EV_IRQn);
	i2c_init(&i2c4_handle, I2C_F_400k);
	spi_init(SPI4, SPI_PSC_128);
	sdram_init();
	// sdram_check(SDRAM_ADDR_BASE);
	ili9806e_init(&IL_handle);
	ltdc_init();


	GPIOA->BSRR = GPIO_BSRR_BS_15;//manual backlight 100%
	ltdc_start(lcd_fb);


	ltdc_fb_t *fb=NULL;

	bool released=true;
	uint16_t cursor_x=0;
	uint16_t cursor_y=0;

	bool scroll=false;
	float scroll_y=0;

	// iwdg_init();
	// iwdg_reset();

	can_dual_init(&can_dual_handle);

	DEBUG_STR("main loop start...\n");
	while(true)
	{
		// iwdg_reset();

		fb = ltdc_get_drawable_fb(lcd_fb);
		if(fb != NULL)
		{

			gui_clear(fb);

			nk_input_begin(ctx);
			if(gt_handle.updated)
			{
				gt_handle.updated=false;

				cursor_x=gt_handle.coords[0].x;
				cursor_y=gt_handle.coords[0].y;

				nk_input_motion(ctx, gt_handle.coords[0].x, gt_handle.coords[0].y);
				if(scroll)
				{
					nk_input_scroll(ctx, (struct nk_vec2){0, scroll_y});
				}
				else
				{
					nk_input_button(ctx, NK_BUTTON_LEFT, gt_handle.coords[0].x, gt_handle.coords[0].y,1);
				}
				released=false;

			}
			else
			{
				if(!released)
				{
					nk_input_button(ctx, NK_BUTTON_LEFT, gt_handle.coords[0].x, gt_handle.coords[0].y,0);
					nk_input_motion(ctx, 0,0);
					released=true;
					scroll=false;
				}
			}
			nk_input_end(ctx);

			// DEBUG_STR("NK begin\n");
			if(nk_begin(ctx, "Main", nk_rect(0, 0, LCD_WIDTH, LCD_HEIGHT),NK_WINDOW_NO_SCROLLBAR|NK_WINDOW_BACKGROUND))
			{	
				uint32_t timestamp = SysTick_uptime();
				nk_layout_row_dynamic(ctx, nk_get_remaining_vertical_space(ctx), 1);


				if(nk_group_begin(ctx,"drawable_area", 0))
				{
					if(displayed == DISPLAYED_MENU)
					{
						if(menu_last_activity_ts+MENU_IDLE_TIMEOUT_ms < timestamp)
						{
							displayed = DISPLAYED_RACE_SCREEN;
							menu.selected_position = 0;
						}
						else
							gui_menu_draw(ctx, &menu);
					}

					else if(displayed == DISPLAYED_RACE_SCREEN)
					{
						switch(dpot_1.current_slot)
						{
							case 0:
								// IDLE
								nk_style_push_font(ctx, &font_nk_large);
								nk_layout_row_dynamic(ctx, nk_get_remaining_vertical_space(ctx), 1);
								nk_label(ctx, "IDLE", NK_TEXT_CENTERED);
								nk_style_pop_font(ctx);
								parameters.vdcu_param_set = vdcu_param_set_idle;
								break;
							
							case 1:
								parameters.vdcu_param_set = vdcu_param_set_acc;
								gui_screen_race(ctx, RACE_MODE_ACCELERATION, parameters.vdcu_param_set);
								break;
							
							case 2:
								parameters.vdcu_param_set = vdcu_param_set_skid;
								gui_screen_race(ctx, RACE_MODE_SKIDPAD, parameters.vdcu_param_set);
								break;
							
							case 3:
								parameters.vdcu_param_set = vdcu_param_set_autox;
								gui_screen_race(ctx, RACE_MODE_AUTOCROSS, parameters.vdcu_param_set);
								break;
							
							case 4:
								parameters.vdcu_param_set = vdcu_param_set_endurance;
								gui_screen_race(ctx, RACE_MODE_ENDURANCE, parameters.vdcu_param_set);
								break;
							
							case 5:
								parameters.vdcu_param_set = vdcu_param_set_demo;
								gui_screen_race(ctx, RACE_MODE_DEMO, parameters.vdcu_param_set);
								break;
							
							case 6:
								gui_screen_sdc(ctx, MENU_EVT_NONE);
								parameters.vdcu_param_set = vdcu_param_set_idle;
								break;
							
							case 7:
								gui_screen_temperatures_draw(ctx);
								parameters.vdcu_param_set = vdcu_param_set_idle;
								break;

							default:
								gui_screen_messages(ctx, candb_messages, timestamp);
								parameters.vdcu_param_set = vdcu_param_set_idle;
								break;
							

						}
					}
					nk_group_end(ctx);
				}


				// 		gui_screen_tracker_draw(ctx);
			}
			if((ctx->last_widget_state & NK_WIDGET_STATE_MODIFIED) == 0 && released == false && ctx->input.mouse.buttons[NK_BUTTON_LEFT].clicked == 0)
			{
				scroll=true;
				scroll_y=ctx->input.mouse.delta.y*0.02f;
			}
			nk_end(ctx);

			if(params_window.active)
			{
				if(params_window.last_action_ts + 3000 > SysTick_uptime())
					gui_param_draw(ctx, &parameters);
				else
					params_window.active = false;
			}
			gui_param_popup_draw(ctx, &parameters);

			if(boost.active)
			{
				struct nk_style_window window_style_backup = ctx->style.window;

				ctx->style.window.fixed_background.data.color = nk_rgb( 51,  55,  67);

				if (nk_begin(ctx, "BOOST", nk_rect(30, 200, LCD_WIDTH-60-20, 200), NK_WINDOW_BORDER))
				{
					nk_style_push_font(ctx, &font_nk_large);
					nk_layout_row_dynamic(ctx, 80, 1);
					nk_layout_row_dynamic(ctx, 0, 1);
					
					nk_label_colored(ctx, "BOOST", NK_TEXT_CENTERED, nk_rgb(255,0,0));
					nk_style_pop_font(ctx);
				}
				nk_end(ctx);
				ctx->style.window = window_style_backup;
			}

			if(reverse.state != REVERSE_OFF)
			{
				struct nk_style_window window_style_backup = ctx->style.window;
				struct nk_style_progress progress_style_backup = ctx->style.progress;

				ctx->style.window.fixed_background.data.color = nk_rgb( 51,  55,  67);
				
				ctx->style.progress.cursor_normal.data.color = nk_rgb( 255, 0, 0);

				if (nk_begin(ctx, "REVERSE", nk_rect(30, 200, LCD_WIDTH-60-20, 200), NK_WINDOW_BORDER))
				{
					nk_style_push_font(ctx, &font_nk_large);
					nk_layout_row_dynamic(ctx, 80, 1);
					nk_layout_row_dynamic(ctx, 0, 1);

					switch(reverse.state)
					{
						case REVERSE_ON:
							nk_label_colored(ctx, "REVERSE", NK_TEXT_CENTERED, nk_rgb(255,0,0));
							break;
							
						case REVERSE_TOO_FAST:
							nk_label_colored(ctx, "TOO FAST!", NK_TEXT_CENTERED, nk_rgb(255,0,0));
							break;

						case REVERSE_OFF:
							nk_label_colored(ctx, "OFF ???", NK_TEXT_CENTERED, nk_rgb(255,0,0));
							break;
					}
					
					nk_style_pop_font(ctx);
				}
				nk_end(ctx);
				ctx->style.window = window_style_backup;
				ctx->style.progress = progress_style_backup;
			}

			gui_draw(ctx, fb);
			nk_clear(ctx);

			draw_rectangle_filled(fb->layer[0].address, fb->layer[0].pix_fmt, LCD_COLOR(255,0,0), NULL, \
						cursor_x, 0, 1,LCD_HEIGHT);
			draw_rectangle_filled(fb->layer[0].address, fb->layer[0].pix_fmt, LCD_COLOR(255,0,0), NULL, \
						0, cursor_y, LCD_WIDTH, 1);
			ltdc_release_fb_to_display(&fb);
			redraws++;
			fps_record();
		}
		// if(can_dual_handle.can1.rxcb->usage)
		// {
		// 	DEBUG_STR("CAN1 RX USG: ");
		// 	DEBUG_NUM(can_dual_handle.can1.rxcb->usage, 3);
		// 	DEBUG_STR(" of ");
		// 	DEBUG_NUM(can_dual_handle.can1.rxcb->capacity, 3);
		// 	DEBUG_NL();
		// }

		// if(can_dual_handle.can2.rxcb->usage)
		// {
		// 	DEBUG_STR("CAN2 RX USG: ");
		// 	DEBUG_NUM(can_dual_handle.can2.rxcb->usage, 3);
		// 	DEBUG_STR(" of ");
		// 	DEBUG_NUM(can_dual_handle.can2.rxcb->capacity, 3);
		// 	DEBUG_NL();
		// }

		can_process_messages(can_dual_handle.can1.rxcb, true);
		can_process_messages(can_dual_handle.can2.rxcb, true);
		// field_tracker_process(field_tracker_get_default());
		vdcu_param_process(parameters.vdcu_param_set);

		loops_per_second++;
	}

}

void I2C4_EV_IRQHandler(void)
{
	i2c_irq_handler(&i2c4_handle);
}

void AFU_handler(void *data)
{
	UNUSED(data);
	gpio_set(LED1);
	delay_ms(200);
	gpio_clr(LED1);
	gpio_set(LED2);
	delay_ms(200);
	gpio_clr(LED2);
	gpio_set(LED3);
	delay_ms(200);
	gpio_clr(LED3);
	gpio_set(LED4);
	delay_ms(200);
	gpio_clr(LED4);
}

void CAN1_SCE_IRQHandler(void)
{
	DEBUG_STR("CAN 1 ERR: ");	
	if(CAN1->ESR & CAN_ESR_BOFF)
		DEBUG_STR("BOFF");
	
	if(CAN1->ESR & CAN_ESR_EPVF)
		DEBUG_STR("EPVF");

	if(CAN1->ESR & CAN_ESR_EWGF)
		DEBUG_STR("EWGF");
	
	if(CAN1->ESR & CAN_ESR_LEC)
	{
		DEBUG_STR("LEC: ");
		switch((CAN1->ESR & CAN_ESR_LEC)>>CAN_ESR_LEC_Pos)
		{
			case 0:
				DEBUG_STR("NONE"); break;
			
			case 1:
				DEBUG_STR("STUFF"); break;

			case 2:
				DEBUG_STR("FORM"); break;

			case 3:
				DEBUG_STR("ACK"); break;

			case 4:
				DEBUG_STR("RECESSIVE"); break;

			case 5:
				DEBUG_STR("DOMINANT"); break;

			case 6:
				DEBUG_STR("CRC"); break;
			
			case 7:
				DEBUG_STR("SW"); break;
		}
	}
	
	bit_clr(CAN1->MSR, CAN_MSR_ERRI);
	DEBUG_NL();
}

void CAN2_SCE_IRQHandler(void)
{
	DEBUG_STR("CAN 1 ERR: ");	
	if(CAN2->ESR & CAN_ESR_BOFF)
		DEBUG_STR("BOFF");
	
	if(CAN2->ESR & CAN_ESR_EPVF)
		DEBUG_STR("EPVF");

	if(CAN2->ESR & CAN_ESR_EWGF)
		DEBUG_STR("EWGF");
	
	if(CAN2->ESR & CAN_ESR_LEC)
	{
		DEBUG_STR("LEC: ");
		switch((CAN2->ESR & CAN_ESR_LEC)>>CAN_ESR_LEC_Pos)
		{
			case 0:
				DEBUG_STR("NONE"); break;
			
			case 1:
				DEBUG_STR("STUFF"); break;

			case 2:
				DEBUG_STR("FORM"); break;

			case 3:
				DEBUG_STR("ACK"); break;

			case 4:
				DEBUG_STR("RECESSIVE"); break;

			case 5:
				DEBUG_STR("DOMINANT"); break;

			case 6:
				DEBUG_STR("CRC"); break;
			
			case 7:
				DEBUG_STR("SW"); break;
		}
	}
	
	bit_clr(CAN2->MSR, CAN_MSR_ERRI);
	DEBUG_NL();

	uint16_t rec = (CAN1->ESR & CAN_ESR_REC) >> CAN_ESR_REC_Pos;
	DEBUG_STR("REC: ");
	DEBUG_NUM(rec, 4);
	uint16_t tec = (CAN1->ESR & CAN_ESR_TEC) >> CAN_ESR_TEC_Pos;
	DEBUG_STR(" TEC: ");
	DEBUG_NUM(tec, 4);
	DEBUG_NL();
}
