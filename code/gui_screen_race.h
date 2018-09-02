#ifndef _GUI_SCREEN_RACE_LIB
	#define _GUI_SCREEN_RACE_LIB
	
	#include "nk.h"
	#include "vdcu_params.h"

	typedef enum{
		RACE_MODE_ACCELERATION=0,
		RACE_MODE_ENDURANCE,
		RACE_MODE_AUTOCROSS,
		RACE_MODE_SKIDPAD,
		RACE_MODE_DEMO,
	}race_mode_t;

	void gui_screen_race(struct nk_context* ctx, race_mode_t racemode, vdcu_param_t *const *current_parameter_set);

#endif