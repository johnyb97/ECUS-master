#include "menu_calib.h"
#include "candb/can_ECUS.h"
#include "debug.h"

#include "debug_enable.h"

void menu_calib_apps_min(void)
{
	ECUP_send_REQCalibPedal(ECUP_CAL_PedalIndex_AppsMin);
	DEBUG_STR("CAL AppsMin\n");
}

void menu_calib_apps_max(void)
{
	ECUP_send_REQCalibPedal(ECUP_CAL_PedalIndex_AppsMax);
	DEBUG_STR("CAL AppsMax\n");
}

void menu_calib_brake_min(void)
{
	ECUP_send_REQCalibPedal(ECUP_CAL_PedalIndex_BrakeMin);
	DEBUG_STR("CAL BrakeMin\n");
}

void menu_calib_brake_max(void)
{
	ECUP_send_REQCalibPedal(ECUP_CAL_PedalIndex_BrakeMax);
	DEBUG_STR("CAL BrakeMax\n");
}

void menu_calib_regen_max(void)
{
	ECUP_send_REQCalibPedal(ECUP_CAL_PedalIndex_RegenMax);
	DEBUG_STR("CAL RegenMax\n");
}

void menu_calib_stw_center(void)
{
	ECUF_send_REQCalibSTW(ECUF_CAL_STWIndex_STWCenter);
	DEBUG_STR("CAL STW mid\n");
}
	