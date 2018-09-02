#include "gui_screen_tracker.h"
#include "debug.h"

#include "debug_enable.h"

void gui_screen_tracker_draw(struct nk_context* ctx)
{
	char conversion_buffer[16];
	static int8_t selected_slot=-1;
	tracker_t *tracker=field_tracker_get_default();

	if(tracker == NULL)
		return;

	if(nk_group_begin(ctx,"tracker", NK_WINDOW_NO_SCROLLBAR))
	{
		nk_layout_row_template_begin(ctx, 0);
		nk_layout_row_template_push_static(ctx, 80);//radio button
		nk_layout_row_template_push_dynamic(ctx);//field name
		nk_layout_row_template_end(ctx);

		for(int8_t idx=0; tracker->fields[idx]!=NULL; idx++)
		{
			tracker_field_t *field=tracker->fields[idx];
			if(nk_option_label(ctx, itoa_dec_fill_append(conversion_buffer, idx, 1, ' ', 0, 10), selected_slot == idx))
			{
				if(field->msg_field != NULL)
					selected_slot = idx;
			}

			if(field->msg_field != NULL)
				nk_label(ctx, field->msg_field->description.name, NK_TEXT_LEFT);
			else
				nk_label(ctx, "empty", NK_TEXT_LEFT);
		}

		int8_t charted_slot = -1;

		if(selected_slot >= 0)
		{
			if(tracker->fields[selected_slot]->msg_field != NULL)
				charted_slot = selected_slot;
			else
			{
				charted_slot = -1;
				selected_slot = -1;
			}
		}
		
		nk_layout_row_dynamic(ctx, nk_get_remaining_vertical_space(ctx), 1);

		if(charted_slot>=0)
		{
			nk_chart_begin(ctx, NK_CHART_LINES, tracker->fields[charted_slot]->data.usage, tracker->fields[selected_slot]->msg_field->type_specific.num.min, tracker->fields[selected_slot]->msg_field->type_specific.num.max);
			float *value;
			uint16_t idx=0;
			while(true)
			{
				value = field_tracker_read_value(tracker->fields[charted_slot], &idx);
				if(value == NULL)
					break;
				nk_chart_push(ctx, *value);
			}
			DEBUG_STR("points avail: ");
			DEBUG_NUM(tracker->fields[charted_slot]->data.usage, 4);
			DEBUG_STR("displayed: ");
			DEBUG_NUM(idx, 4);
			DEBUG_NL();
		}
		else
			nk_chart_begin(ctx, NK_CHART_LINES, 1, 0, 1);//at least show chart even if there is nothing to plot
		nk_chart_end(ctx);


		nk_group_end(ctx);
	}


	
}