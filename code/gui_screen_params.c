#include "gui_screen_params.h"
#include "fonts.h"

void gui_screen_params_show_menu(struct nk_context* ctx)
{
	gui_screen_params_show(ctx, false);
}

void gui_screen_params_show(struct nk_context* ctx, vdcu_param_t *const *current_parameter_set)
{
	char conversion_buffer[16];
	float buffer;

	nk_layout_row_dynamic(ctx, 0, 1);

	nk_layout_row_dynamic(ctx, nk_get_remaining_vertical_space(ctx), 1);
	if(nk_group_begin(ctx,"param_list", 0))
	{
		const uint8_t row_height=70;

		vdcu_param_t *const *parameter_set = current_parameter_set;
		vdcu_param_t *parameter;

		for(; *parameter_set != NULL; parameter_set++)
		{
			parameter=(*parameter_set);
			nk_style_push_font(ctx, &font_nk_large);

			nk_layout_row_template_begin(ctx, row_height);
			nk_layout_row_template_push_dynamic(ctx);//parameter name
			nk_layout_row_template_push_static(ctx, 150);//value
			nk_layout_row_template_end(ctx);

			nk_label(ctx, parameter->name, NK_TEXT_LEFT);
			struct nk_color value_color = ctx->style.text.color;

			switch(parameter->state)
			{
				case PARAM_STATE_FAILED:
					value_color = nk_rgb(255, 0, 0);
					break;
				
				case PARAM_STATE_CONFIRMED_MATCH:
					value_color = nk_rgb(0, 255, 0);
					break;

				case PARAM_STATE_SENT:
					value_color = nk_rgb(255, 255, 0);
					break;

				default:
					break;
				
			}
			nk_label_colored(ctx, itoa_dec_fill_append(conversion_buffer, parameter->value, 0, ' ', 0, 10), NK_TEXT_RIGHT, value_color);
			nk_style_pop_font(ctx);
			
			// nk_layout_row_template_begin(ctx, 0);
			// nk_layout_row_template_push_static(ctx, 60);//min
			// nk_layout_row_template_push_static(ctx, 60);//max
			// nk_layout_row_template_push_dynamic(ctx);//value
			// nk_layout_row_template_end(ctx);

		}
		nk_group_end(ctx);
	}
}