#include "gui_screen_battery.h"
#include "gui_menu.h"
#include "nk.h"
#include "candb_structure.h"

const candb_msg_field_t *const gui_screen_battery_get_amsvolt_cell(uint8_t stack, uint8_t cell)
{
	if(cell > 15)
		return NULL;
	if(stack > 5)
		return NULL;

	const candb_msg_field_t *cell_field = candb_messages[CANDB_MSG_ECUA_AMSVOLTS]->fields[CANDB_ECUA_AMSVOLTS_FIELD_STACKID]->type_specific.mux.muxed_fields[stack][1];
	
	// return stack_field->type_specific.mux.muxed_fields[cell*2];
	return cell_field;
}

bool gui_screen_battery(struct nk_context* ctx, menu_evt_t event)
{
	char conversion_buffer[16];
	static enum{
		BATT_VIEW_STACK_0 = 0,
		BATT_VIEW_STACK_1 = 1,
		BATT_VIEW_STACK_2 = 2,
		BATT_VIEW_STACK_3 = 3,
		BATT_VIEW_STACK_4 = 4,
		BATT_VIEW_STACK_5 = 5,
		BATT_VIEW_ACP,
	}batt_view;
	nk_layout_row_template_begin(ctx, 30);
	nk_layout_row_template_push_dynamic(ctx);//ACP
	nk_layout_row_template_push_dynamic(ctx);//stack number
	nk_layout_row_template_push_dynamic(ctx);//stack number
	nk_layout_row_template_push_dynamic(ctx);//stack number
	nk_layout_row_template_push_dynamic(ctx);//stack number
	nk_layout_row_template_push_dynamic(ctx);//stack number
	nk_layout_row_template_push_dynamic(ctx);//stack number
	nk_layout_row_template_end(ctx);

	if(nk_button_label(ctx, "ACP"))
		batt_view = BATT_VIEW_ACP;

	for(uint8_t stack=0; stack<6; stack++)
	{
		nk_button_label(ctx, itoa_dec_append(conversion_buffer, stack, 0, 0));
	}
	
	nk_layout_row_template_begin(ctx, 30);
	nk_layout_row_template_push_static(ctx, 100);//cell voltage
	nk_layout_row_template_end(ctx);

	

	return true;
}