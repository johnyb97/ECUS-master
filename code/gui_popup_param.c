#include "gui_popup_param.h"
#include "fonts.h"
#include "systick.h"
#include "vdcu_params.h"

struct nk_color gui_param_state_to_color(struct nk_context* ctx, param_state_t state)
{
	switch(state)
	{
		case PARAM_STATE_IDLE:
			return ctx->style.text.color;

		case PARAM_STATE_MODIFIED:
		case PARAM_STATE_SENT:
		case PARAM_STATE_UPDATE:
		case PARAM_STATE_TIMEOUT:
			return nk_rgb(255, 255, 0);	

		case PARAM_STATE_CONFIRMED_MATCH:
			return nk_rgb(0, 255, 0);

		case PARAM_STATE_CONFIRMED_MISMATCH:
			return nk_rgb(255, 127, 0);

		case PARAM_STATE_FAILED:
			return nk_rgb(255, 0, 0);
		
		default:
			return ctx->style.text.color;
	}
}

void gui_current_param_change(parameter_set_t *parameters, bool inc_ndec)
{
	vdcu_param_t *param = parameters->vdcu_param_set[parameters->selected];

	if(inc_ndec)
	{
		if(param->value < param->max)
			vdcu_param_change(param, param->value+1);
		else
			return;
	}
	else
	{
		if(param->value > param->min)
			vdcu_param_change(param, param->value-1);
		else
			return;
	}
	parameters->last_value_change_ts = SysTick_uptime();
}

#define PARAM_POPUP_TIMEOUT	2000

void gui_param_popup_draw(struct nk_context* ctx, parameter_set_t *parameters)
{
	if(parameters->last_value_change_ts + PARAM_POPUP_TIMEOUT < SysTick_uptime() || 
		SysTick_uptime() < PARAM_POPUP_TIMEOUT)
		return;

	char conversion_buffer[16];
	
	vdcu_param_t *param = parameters->vdcu_param_set[parameters->selected];

	struct nk_color color = gui_param_state_to_color(ctx, param->state);

	if (nk_begin(ctx, "active parameter edit", nk_rect(10, 200, LCD_WIDTH-20, 200), NK_WINDOW_BORDER))
	{	
		nk_style_push_font(ctx, &font_nk_default);
		nk_layout_row_template_begin(ctx, 0);
		nk_layout_row_template_push_dynamic(ctx);
		nk_layout_row_template_push_static(ctx, 60);
		nk_layout_row_template_end(ctx);


		nk_label_colored(ctx, param->name, NK_TEXT_LEFT, color);
		nk_label_colored(ctx, ftoa(conversion_buffer, param->value, 3, 0, ' '), NK_TEXT_RIGHT, color);
		nk_layout_row_dynamic(ctx, 20, 1);
		nk_prog(ctx, param->value - param->min, param->max - param->min, false);

		nk_style_pop_font(ctx);
		
	}
	nk_end(ctx);
}

void gui_param_draw(struct nk_context* ctx, parameter_set_t *parameters)
{
	char conversion_buffer[16];

	struct nk_style_window window_style_backup = ctx->style.window;
	ctx->style.window.background = nk_rgba( 51,  55,  67, 255);

	if (nk_begin(ctx, "PARAMETERS", nk_rect(10, 100, LCD_WIDTH-20, 600), NK_WINDOW_BORDER|NK_WINDOW_TITLE))
	{	

		nk_style_push_font(ctx, &font_nk_default);
		nk_layout_row_template_begin(ctx, 40);
		nk_layout_row_template_push_static(ctx, 40);//indicator
		nk_layout_row_template_push_dynamic(ctx);//name
		nk_layout_row_template_push_static(ctx, 60);//value
		nk_layout_row_template_end(ctx);


		//selected is always on top
		for(uint8_t param_idx = parameters->selected; parameters->vdcu_param_set[param_idx] != NULL; param_idx++)
		{
			if(nk_get_remaining_vertical_space(ctx) < (ctx->active->layout->row.height + 4 ))
				break;

			vdcu_param_t *param = parameters->vdcu_param_set[param_idx];

			nk_button_color(ctx, gui_param_state_to_color(ctx, param->state));//param indicator

			if(param_idx == parameters->selected)
				nk_label_colored(ctx, param->name, NK_TEXT_LEFT, ctx->style.button.normal.data.color);
			else
				nk_label(ctx, param->name, NK_TEXT_LEFT);

			

			nk_label(ctx, ftoa(conversion_buffer, param->value, 3, 0, ' '), NK_TEXT_RIGHT);
		}
		nk_style_pop_font(ctx);
		
	}
	nk_end(ctx);

	ctx->style.window = window_style_backup;
}