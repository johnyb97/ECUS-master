#include "gui_screen_sdc.h"
#include "candb_structure.h"
#include "systick.h"
#include "candb_msg.h"

void gui_screen_sdc_show_field(struct nk_context* ctx, const candb_msg_t *msg, const uint8_t field_idx)
{
	if(candb_msg_is_not_timeouted(msg))
	{
		if(*(msg->fields[field_idx]->type_specific.bl.value))
			nk_button_color(ctx, nk_rgb(0, 255, 0));
		else
			nk_button_color(ctx, nk_rgb(255, 0, 0));

	}
	else
		nk_button_color(ctx, nk_rgb(127, 127, 127));
	nk_label(ctx, msg->fields[field_idx]->description.name, NK_TEXT_LEFT);	
}

bool gui_screen_sdc(struct nk_context* ctx, menu_evt_t event)
{
	nk_layout_row_template_begin(ctx, 30);
	nk_layout_row_template_push_static(ctx, ctx->current->layout->row.height);
	nk_layout_row_template_push_dynamic(ctx);
	nk_layout_row_template_end(ctx);

	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUP_STATUS], CANDB_ECUP_STATUS_FIELD_SDC_BOTS);

	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUF_STATUS], CANDB_ECUF_STATUS_FIELD_SDC_FWIL);
	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUF_STATUS], CANDB_ECUF_STATUS_FIELD_SDC_INERTIA);
	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUF_STATUS], CANDB_ECUF_STATUS_FIELD_SDC_SDBC);

	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUB_STATUS], CANDB_ECUB_STATUS_FIELD_SDC_FRONT);
	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUB_STATUS], CANDB_ECUB_STATUS_FIELD_SDC_SDBL);
	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUB_STATUS], CANDB_ECUB_STATUS_FIELD_SDC_SDBR);
	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUB_STATUS], CANDB_ECUB_STATUS_FIELD_SDC_AMS);
	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUA_STATUS], CANDB_ECUA_STATUS_FIELD_SDC_AMS);

	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUA_STATUS], CANDB_ECUA_STATUS_FIELD_SDC_HV_ILOCK);
	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUA_STATUS], CANDB_ECUA_STATUS_FIELD_SDC_IMD);
	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUB_STATUS], CANDB_ECUB_STATUS_FIELD_SDC_MCUR);
	
	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUA_STATUS], CANDB_ECUA_STATUS_FIELD_SDC_OUT);

	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUB_STATUS], CANDB_ECUB_STATUS_FIELD_SDC_HVD);
	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUB_STATUS], CANDB_ECUB_STATUS_FIELD_SDC_BSPD);
	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUB_STATUS], CANDB_ECUB_STATUS_FIELD_SDC_TSMS);


	gui_screen_sdc_show_field(ctx, candb_messages[CANDB_MSG_ECUA_STATUS], CANDB_ECUA_STATUS_FIELD_SDC_END);

	return !(event == MENU_EVT_ENTER);
}