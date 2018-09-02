#ifndef _GUI_POPUP_PARAM
	#define _GUI_POPUP_PARAM
	
	#include "nk.h"
	#include "gui_menu.h"
	#include "vdcu_params.h"

	typedef volatile struct{
		uint32_t last_value_change_ts;
		vdcu_param_t *const *vdcu_param_set;//pointer to array of pointers
		uint8_t selected;
	}parameter_set_t;

	void gui_param_draw(struct nk_context* ctx, parameter_set_t *parameters);
	void gui_current_param_change(parameter_set_t *parameters, bool inc_ndec);
	void gui_param_popup_draw(struct nk_context* ctx, parameter_set_t *parameters);

#endif