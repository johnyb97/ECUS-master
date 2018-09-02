#include "gui_screen_messages.h"
#include "field_tracker.h"




#define NK_COLOR_FAIL		nk_rgb(255,0,0)
#define NK_COLOR_SUCCESS	nk_rgb(0,255,0)

static void gui_screen_messages_draw_numeric_field(struct nk_context* ctx, const candb_msg_t *message, const candb_msg_field_t *field, uint8_t level, bool expanded)
{
	char conversion_buffer[16];

	float value;
	static bool popup_active=false;

	if(expanded)
	{
		nk_hspacer(ctx);//do not show value in line with name if expanded

		nk_layout_row_template_begin(ctx, 45);
		nk_layout_row_template_push_static(ctx, 10*(level+1));//indent(spacer)
		nk_layout_row_template_push_dynamic(ctx);//min
		nk_layout_row_template_push_static(ctx, 70);//<=
		nk_layout_row_template_push_dynamic(ctx);//value
		nk_layout_row_template_push_static(ctx, 70);//<=	
		nk_layout_row_template_push_dynamic(ctx);//max
		nk_layout_row_template_push_static(ctx, 10);//spacer
		nk_layout_row_template_push_static(ctx, 45);//plot button
		nk_layout_row_template_end(ctx);
	}
	else if(field->count>1)
	{
		nk_label(ctx, "ARRAY", NK_TEXT_RIGHT);

		nk_layout_row_template_begin(ctx, 45);
		nk_layout_row_template_push_static(ctx, 10*level);//indent(spacer)
		nk_layout_row_template_push_dynamic(ctx);//value
		nk_layout_row_template_push_dynamic(ctx);//value
		nk_layout_row_template_push_dynamic(ctx);//value
		nk_layout_row_template_push_dynamic(ctx);//value
		nk_layout_row_template_push_static(ctx, 10);//spacer
		nk_layout_row_template_end(ctx);
	}

	if(expanded)
	{
		char buffer_min[16];
		char buffer_max[16];
		ftoa(buffer_min, field->type_specific.num.min, 0, 2, ' ');
		ftoa(buffer_max, field->type_specific.num.max, 0, 2, ' ');

		for(uint8_t idx=0; idx<field->count; idx++)
		{
			num_validity_t validity = candb_field_num_converted(field, idx, &value);

			nk_hspacer(ctx);
			nk_label(ctx, buffer_min, NK_TEXT_CENTERED);
			nk_label_colored(ctx, "=>", NK_TEXT_CENTERED, (validity == INVALID_MIN)? NK_COLOR_FAIL : NK_COLOR_SUCCESS );
			if(validity == INVALID_NAN)
				nk_label_colored(ctx, "invalid", NK_TEXT_CENTERED, NK_COLOR_FAIL);
			else
				nk_label_colored(ctx, ftoa(conversion_buffer, value, 6, 2, ' '), NK_TEXT_RIGHT, (validity != VALID)? NK_COLOR_FAIL : NK_COLOR_SUCCESS);
			nk_label_colored(ctx, "=>", NK_TEXT_CENTERED, (validity == INVALID_MAX)? NK_COLOR_FAIL : NK_COLOR_SUCCESS );
			nk_label(ctx, buffer_max, NK_TEXT_CENTERED);
			nk_hspacer(ctx);

			nk_hspacer(ctx);
			nk_hspacer(ctx);
			nk_label(ctx, "RAW", NK_TEXT_CENTERED);
			nk_hspacer(ctx);
			switch(field->type)
			{
				case CANDB_MSG_FIELD_TYPE_UINT:
					nk_label(ctx, itoa_dec_append(conversion_buffer, (*field->type_specific.num.value).ui, 6, 0), NK_TEXT_RIGHT);
					break;
				
				case CANDB_MSG_FIELD_TYPE_INT:
					nk_label(ctx, itoa_dec_append(conversion_buffer, (*field->type_specific.num.value).si, 6, 0), NK_TEXT_RIGHT);
					break;
				
				case CANDB_MSG_FIELD_TYPE_FLOAT:
					nk_label(ctx, ftoa(conversion_buffer, (*field->type_specific.num.value).fl, 6, 2, ' '), NK_TEXT_RIGHT);
					break;
				
				default:
					nk_label(ctx, "WTF?", NK_TEXT_LEFT);
					break;
			}
			nk_hspacer(ctx);
			nk_hspacer(ctx);
			nk_hspacer(ctx);
	



			if(nk_button_symbol(ctx, NK_SYMBOL_CIRCLE_SOLID))
			{
				popup_active=true;
				// gui_screen_messages_chart_track_new_field(&field_chart, message, field, idx);
			}


			{
				static int8_t selected_slot=-1;
				if (popup_active)
				{
					struct nk_rect s = {10, 100, ctx->current->bounds.w-50, 500};
					if (nk_popup_begin(ctx, NK_POPUP_DYNAMIC, "Select tracker slot", NK_WINDOW_TITLE|NK_WINDOW_BORDER|NK_WINDOW_MOVABLE, s))
					{
						nk_layout_row_template_begin(ctx, 0);
						nk_layout_row_template_push_static(ctx, 80);//radio button
						nk_layout_row_template_push_dynamic(ctx);//field name
						nk_layout_row_template_end(ctx);

						tracker_t *tracker=field_tracker_get_default();

						for(uint8_t idx=0; tracker->fields[idx]!=NULL; idx++)
						{
							tracker_field_t *field=tracker->fields[idx];
							if(nk_option_label(ctx, itoa_dec_fill_extbuff(conversion_buffer, idx, 1, ' ', 0, 10), selected_slot == idx))
								selected_slot = idx;

							if(field->msg_field != NULL)
								nk_label(ctx, field->msg_field->description.name, NK_TEXT_LEFT);
							else
								nk_label(ctx, "empty", NK_TEXT_LEFT);
						}

						nk_layout_row_dynamic(ctx, 25, 2);
						if (nk_button_label(ctx, "OK")) {
							if(selected_slot>=0)
							{
								field_tracker_track_new(tracker->fields[selected_slot], message, field, idx);
							}
							popup_active = 0;
							nk_popup_close(ctx);
						}
						if (nk_button_label(ctx, "Cancel")) {
							popup_active = 0;
							nk_popup_close(ctx);
						}
						nk_popup_end(ctx);
					} else popup_active = nk_false;
				}
				else
				{
					selected_slot=-1;
				}
			}



		}	
	}
	else
	{
		//print all values below field title
		for(uint8_t idx=0; idx<field->count; idx++)
		{
			if(idx%4 == 0 && field->count>1)
				nk_hspacer(ctx);

			num_validity_t validity=candb_field_num_converted(field, idx, &value);
			if(validity == INVALID_NAN)
				nk_label_colored(ctx, "invalid", NK_TEXT_RIGHT, NK_COLOR_FAIL);
			else
				nk_label_colored(ctx, ftoa(conversion_buffer, value, 6, 2, ' '), NK_TEXT_RIGHT, (validity != VALID)? NK_COLOR_FAIL : NK_COLOR_SUCCESS);

			if((idx+1)%4 == 0)
				nk_hspacer(ctx);
		}
	}
}

static void gui_screen_messages_draw_fields(struct nk_context* ctx, const candb_msg_t *message, const candb_msg_field_t *const *const fields, uint8_t level, const candb_msg_field_t **expanded_field)
{
	for(const candb_msg_field_t *const *field_ptr_ptr=fields; *field_ptr_ptr != NULL; field_ptr_ptr++)
	{
		const candb_msg_field_t *field =*field_ptr_ptr;

		nk_layout_row_template_begin(ctx, 45);
		nk_layout_row_template_push_static(ctx, 10*(level+1));//indent(spacer)
		nk_layout_row_template_push_static(ctx, 45);//expand btn
		nk_layout_row_template_push_static(ctx, 250);//name
		nk_layout_row_template_push_dynamic(ctx);//value
		nk_layout_row_template_push_static(ctx, 10);//spacer (not needed to be widget)
		nk_layout_row_template_end(ctx);


		nk_hspacer(ctx);
		if(*expanded_field == field)
		{
			if(nk_button_symbol(ctx, NK_SYMBOL_MINUS))
				*expanded_field = NULL;
		}
		else
		{
			if(nk_button_symbol(ctx, NK_SYMBOL_PLUS))
				*expanded_field = field;
		}
		bool expanded = (*expanded_field == field);

		//field label
		nk_label(ctx, field->description.name, NK_TEXT_LEFT);
		
		switch(field->type)
		{
			
			case CANDB_MSG_FIELD_TYPE_UINT:
			case CANDB_MSG_FIELD_TYPE_INT:
			case CANDB_MSG_FIELD_TYPE_FLOAT:
			{
				gui_screen_messages_draw_numeric_field(ctx, message, field, level+1, expanded);
			}
			break;
			
			case CANDB_MSG_FIELD_TYPE_ENUM:
			{
				const char *current_enum_state_name = candb_find_description(field->type_specific.en.descriptions, *field->type_specific.en.value);
				nk_label(ctx, itoa(*field->type_specific.en.value,1), NK_TEXT_RIGHT);//raw value of enum

				if(expanded)
				{
					nk_layout_row_template_begin(ctx, 45);
					nk_layout_row_template_push_static(ctx, 10*(level+1)+45);//indent(spacer)
					nk_layout_row_template_push_static(ctx, 40);//value
					nk_layout_row_template_push_dynamic(ctx);//description
					nk_layout_row_template_push_static(ctx, 10);//spacer (not needed to be widget)
					nk_layout_row_template_end(ctx);

					if(current_enum_state_name!=NULL)
					{
						nk_hspacer(ctx);
						nk_label(ctx, itoa(*field->type_specific.en.value,1), NK_TEXT_RIGHT);//raw value of enum
						nk_label(ctx, current_enum_state_name, NK_TEXT_CENTERED);
						nk_hspacer(ctx);
					}
					else
					{
						nk_hspacer(ctx);
						nk_hspacer(ctx);
						nk_label(ctx, "UNKNOWN STATE! :(", NK_TEXT_CENTERED);
						nk_hspacer(ctx);
					}

					for(const candb_descrition_map_t *const *description_ptr_ptr = field->type_specific.en.descriptions; *description_ptr_ptr != NULL; description_ptr_ptr++)
					{
						const char* enum_state_name = (*description_ptr_ptr)->text;

						nk_hspacer(ctx);
						nk_label(ctx, itoa((*description_ptr_ptr)->id,2), NK_TEXT_RIGHT);//raw value of enum
						nk_label(ctx, enum_state_name, NK_TEXT_CENTERED);
						nk_hspacer(ctx);
					}

					
				}
			}
			break;

			case CANDB_MSG_FIELD_TYPE_BOOL:
			{
				// nk_layout_row_dynamic(ctx, 30, 1);
				if(field->type_specific.bl.value[0])
					nk_label(ctx, "True", NK_TEXT_RIGHT);
				else
					nk_label(ctx, "False", NK_TEXT_RIGHT);
			}
			break;

			case CANDB_MSG_FIELD_TYPE_MUX:
				nk_label(ctx, "MUX", NK_TEXT_RIGHT);
				if(expanded)
				{
					for(uint8_t mux=0; mux<(field->type_specific.mux.max-field->type_specific.mux.min); mux++)
					{
						gui_screen_messages_draw_fields(ctx, message, field->type_specific.mux.muxed_fields[mux] , level+1, expanded_field+1);
					}
				}
				break;

			default:
				nk_layout_row_dynamic(ctx, 30, 1);
				nk_label(ctx, "not implemented yet :(", NK_TEXT_RIGHT);
				break;

		}

		// nk_label(ctx, field->description.name, NK_TEXT_LEFT);
	}
}

static void gui_screen_messages_draw_message_timeout_indicator(struct nk_context* ctx, const candb_msg_t *message, uint32_t timestamp)
{
	if(message->timeout <= 0)//timeout not defined
	{
		uint8_t delay = 0;
		if(timestamp - *message->timestamp < 500)
			delay = (255ul-64)*(timestamp - *message->timestamp)/500;
		else
			delay = 255-64;
		nk_button_color(ctx, nk_rgb(64,255-delay,64));
	}
	else if(*message->timestamp + message->timeout > timestamp)//timeout defined, but not timeouted
	{
		uint8_t delayed = 255ul*(timestamp - *message->timestamp)/message->timeout;
		nk_button_color(ctx, nk_rgb(delayed,255-delayed,0));
	}
	else
		nk_button_color(ctx, nk_rgb(255, 0, 0));
}

void gui_screen_messages(struct nk_context* ctx, const candb_msg_t  *const *const messages, const uint32_t timestamp)
{	
	static const candb_msg_t *expanded_msg=NULL;
	static const candb_msg_field_t *expanded_field[5];//how many nesting levels are we able to handle

	for(const candb_msg_t *const *msg_ptr_ptr = messages; *msg_ptr_ptr != NULL; msg_ptr_ptr++)
	{
		const candb_msg_t *msg = *msg_ptr_ptr;
		nk_layout_row_template_begin(ctx, 45);
		nk_layout_row_template_push_static(ctx, 45);//indicator
		nk_layout_row_template_push_static(ctx, 45);//expand btn
		nk_layout_row_template_push_static(ctx, 90);//source unit name
		nk_layout_row_template_push_dynamic(ctx);//message name
		nk_layout_row_template_end(ctx);

		gui_screen_messages_draw_message_timeout_indicator(ctx, msg, timestamp);

		if(expanded_msg == msg)
		{
			if(nk_button_symbol(ctx, NK_SYMBOL_MINUS))
				expanded_msg = NULL;
		}
		else
		{
			if(nk_button_symbol(ctx, NK_SYMBOL_PLUS))
				expanded_msg = msg;
		}
		
		nk_label(ctx, msg->sent_by, NK_TEXT_LEFT);	
		nk_label(ctx, msg->description.name, NK_TEXT_LEFT);	

		if(expanded_msg == msg)
		{
			nk_layout_row_dynamic(ctx, 0, 1);//hack, we need to know mow wide will be space for our text to calculate its' height
			nk_label_wrap_vertical_hack(ctx, msg->description.comments);
			gui_screen_messages_draw_fields(ctx, msg, msg->fields, 0, expanded_field);
		
		}
	}


	
}
