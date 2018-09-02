#include "gui_screen_temperatures.h"
#include "fonts.h"
#include "candb_structure.h"
#include "candb_msg.h"
#include "misc.h"

void gui_screen_temperature(struct nk_context *ctx, const float temp, const float t_min, const float t_max, nk_flags align)
{
	const float t_half = (t_max-t_min)/2;
	struct nk_color t_color;
	if(temp < (t_half + t_min))
		t_color = nk_rgb(255*max(0, temp-t_min)/t_half , 255, 0);
	else
		t_color = nk_rgb(255 , max(0, 255 - 255*max(0, temp-t_half-t_min)/t_half) , 0);
	
	char conversion_buffer [16];
	nk_label_colored(ctx, ftoa(conversion_buffer, temp, 5, 0, ' '), align,t_color);
}

void gui_screen_temperatures_draw(struct nk_context *ctx)
{
	nk_style_push_font(ctx, &font_nk_large);
	
	nk_layout_row_template_begin(ctx, 0);
	nk_layout_row_template_push_dynamic(ctx);
	nk_layout_row_template_push_dynamic(ctx);
	nk_layout_row_template_push_dynamic(ctx);
	nk_layout_row_template_push_dynamic(ctx);
	nk_layout_row_template_end(ctx);

	float buffer = 0;
	candb_field_num_converted(candb_messages[CANDB_MSG_MCF_THERMALMEASURESA]->fields[CANDB_MCF_THERMALMEASURESA_FIELD_TMOTSEN], 0, &buffer);
	gui_screen_temperature(ctx, buffer, 20, 100, NK_TEXT_CENTERED);
	candb_field_num_converted(candb_messages[CANDB_MSG_MCF_THERMALMEASURESA]->fields[CANDB_MCF_THERMALMEASURESA_FIELD_TIGBT], 0, &buffer);
	gui_screen_temperature(ctx, buffer, 20, 100, NK_TEXT_CENTERED);
	candb_field_num_converted(candb_messages[CANDB_MSG_MCF_THERMALMEASURESB]->fields[CANDB_MCF_THERMALMEASURESB_FIELD_TIGBT], 0, &buffer);
	gui_screen_temperature(ctx, buffer, 20, 100, NK_TEXT_CENTERED);
	candb_field_num_converted(candb_messages[CANDB_MSG_MCF_THERMALMEASURESB]->fields[CANDB_MCF_THERMALMEASURESB_FIELD_TMOTSEN], 0, &buffer);
	gui_screen_temperature(ctx, buffer, 20, 100, NK_TEXT_CENTERED);

	candb_field_num_converted(candb_messages[CANDB_MSG_MCR_THERMALMEASURESA]->fields[CANDB_MCR_THERMALMEASURESA_FIELD_TMOTSEN], 0, &buffer);
	gui_screen_temperature(ctx, buffer, 20, 100, NK_TEXT_CENTERED);
	candb_field_num_converted(candb_messages[CANDB_MSG_MCR_THERMALMEASURESA]->fields[CANDB_MCR_THERMALMEASURESA_FIELD_TIGBT], 0, &buffer);
	gui_screen_temperature(ctx, buffer, 20, 100, NK_TEXT_CENTERED);
	candb_field_num_converted(candb_messages[CANDB_MSG_MCR_THERMALMEASURESB]->fields[CANDB_MCR_THERMALMEASURESB_FIELD_TIGBT], 0, &buffer);
	gui_screen_temperature(ctx, buffer, 20, 100, NK_TEXT_CENTERED);
	candb_field_num_converted(candb_messages[CANDB_MSG_MCR_THERMALMEASURESB]->fields[CANDB_MCR_THERMALMEASURESB_FIELD_TMOTSEN], 0, &buffer);
	gui_screen_temperature(ctx, buffer, 20, 100, NK_TEXT_CENTERED);

	nk_style_pop_font(ctx);
}