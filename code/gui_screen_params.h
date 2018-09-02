#ifndef _GUI_SCREEN_PARAM_LIB
	#define _GUI_SCREEN_PARAM_LIB
	
	#include "config.h"
	#include "nk.h"
	#include "vdcu_params.h"

	void gui_screen_params_show_menu(struct nk_context* ctx);
	void gui_screen_params_show(struct nk_context* ctx, vdcu_param_t *const *parameter_set);
	
#endif