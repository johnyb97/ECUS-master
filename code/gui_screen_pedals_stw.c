#include "gui_screen_pedals_stw.h"

#include "gui_menu.h"
#include "candb_structure.h"
#include "candb_msg.h"

void gui_screen_name_val_progress(struct nk_context* ctx, const candb_msg_field_t *const field)
{
	char conversion_buffer[16];
	float buffer;

	nk_layout_row_dynamic(ctx, 0, 1);
	candb_field_num_converted(field , 0, &buffer);
	nk_label(ctx, ftoa(conversion_buffer, buffer, 5, 1, ' '), NK_TEXT_RIGHT);//acc
	buffer -= field->type_specific.num.min;
	nk_prog(ctx, buffer, field->type_specific.num.max - field->type_specific.num.min, 0);
}

bool gui_screen_pedals_stw(struct nk_context* ctx, menu_evt_t event)
{
	float buffer;
	nk_layout_row_dynamic(ctx, 0, 1);
	nk_label(ctx, "APPS", NK_TEXT_LEFT);
	//apps pos
	gui_screen_name_val_progress(ctx, candb_messages[CANDB_MSG_ECUP_PEDALS]->fields[CANDB_ECUP_PEDALS_FIELD_APPS_POS]);
	//brk pos
	gui_screen_name_val_progress(ctx, candb_messages[CANDB_MSG_ECUP_PEDALS]->fields[CANDB_ECUP_PEDALS_FIELD_BRAKE_POS]);
	//brk pressure F
	gui_screen_name_val_progress(ctx, candb_messages[CANDB_MSG_ECUP_PRESSURE]->fields[CANDB_ECUP_PRESSURE_FIELD_BRAKEF]);
	//brk pressure R
	gui_screen_name_val_progress(ctx, candb_messages[CANDB_MSG_ECUP_PRESSURE]->fields[CANDB_ECUP_PRESSURE_FIELD_BRAKER]);


	candb_field_num_converted(candb_messages[CANDB_MSG_ECUP_DIAGPOS]->fields[CANDB_ECUP_DIAGPRESSURE_FIELD_BRAKEPRESSFRAW], 0, &buffer);

	// candb_messages[CANDB_MSG_ECUP_PEDALS]->fields[CANDB_ECUP_PEDALS_FIELD_FT_APPS_POS]->type_specific.bl.value
	// candb_messages[CANDB_MSG_ECUP_PEDALS]->fields[CANDB_ECUP_PEDALS_FIELD_FT_BRAKE_POS]->type_specific.bl.value
	// candb_messages[CANDB_MSG_ECUP_PRESSURE]->fields[CANDB_ECUP_PRESSURE_FIELD_FT_BRAKEF]->type_specific.bl.value
	// candb_messages[CANDB_MSG_ECUP_PRESSURE]->fields[CANDB_ECUP_PRESSURE_FIELD_FT_BRAKER]->type_specific.bl.value

	// if(valid)
	// 	nk_label(ctx, field->description.name, NK_TEXT_CENTERED);
	// else
	// 	nk_label_colored(ctx, field->description.name, NK_TEXT_CENTERED, nk_rgb(255,0,0));

	// nk_layout_row_template_begin(ctx, 30);
	// nk_layout_row_template_push_static(ctx, 100);//name
	// nk_layout_row_template_push_static(ctx, 100);//value
	// nk_layout_row_template_push_dynamic(ctx);
	// nk_layout_row_template_end(ctx);
	return false;
}