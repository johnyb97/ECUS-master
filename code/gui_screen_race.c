#include "gui_screen_race.h"
#include "fonts.h"
#include "candb_structure.h"
#include "candb_msg.h"
#include "debug.h"

#include "debug_enable.h"

#define LINE_THICKNESS 3

void gui_screen_race_name_unit_value(struct nk_context* ctx, const char *name, const char *unit, float value)
{
	char conversion_buffer[16];
	nk_label(ctx, name, NK_TEXT_RIGHT);
	nk_label(ctx, ftoa(conversion_buffer, value, 5, 1, ' '), NK_TEXT_RIGHT);
	nk_label(ctx, unit, NK_TEXT_LEFT);
}

void gui_screen_race_name_value_unit(struct nk_context* ctx, const char *name, const candb_msg_field_t *field)
{
	float value_buffer;

	candb_field_num_converted(field, 0, &value_buffer);
	gui_screen_race_name_unit_value(ctx, name, field->unit, value_buffer);
}

void gui_screen_race(struct nk_context* ctx, race_mode_t racemode, vdcu_param_t *const *parameter_set)
{
	char conversion_buffer[16];
	float buffer;

	struct nk_color separator_color = ctx->style.button.normal.data.color;

	const candb_msg_field_t *field;


	//header - racemode name
	nk_style_push_font(ctx, &font_nk_large);
	nk_layout_row_dynamic(ctx, 0, 1);
	switch(racemode)
	{
		case RACE_MODE_ACCELERATION:
			nk_label(ctx, "ACCELERATION", NK_TEXT_CENTERED);
			break;
		
		case RACE_MODE_AUTOCROSS:
			nk_label(ctx, "AUTOCROSS", NK_TEXT_CENTERED);
			break;
		
		case RACE_MODE_ENDURANCE:
			nk_label(ctx, "ENDURANCE", NK_TEXT_CENTERED);
			break;
		
		case RACE_MODE_SKIDPAD:
			nk_label(ctx, "SKIDPAD", NK_TEXT_CENTERED);
			break;
		
		case RACE_MODE_DEMO:
			nk_label(ctx, "DEMO", NK_TEXT_CENTERED);
			break;
		
		default:
			nk_label_colored(ctx, "BAD SLOT!", NK_TEXT_CENTERED, nk_rgb(255, 0, 0));
	}
	nk_style_pop_font(ctx);

	nk_layout_row_dynamic(ctx, -1, 1);
	nk_filled_color(ctx, separator_color);

	//header - voltages
	nk_layout_row_template_begin(ctx, 0);
	nk_layout_row_template_push_static(ctx, 100);//LV
	nk_layout_row_template_push_dynamic(ctx);//val
	nk_layout_row_template_push_static(ctx, 50);//V
	nk_layout_row_template_push_static(ctx, LINE_THICKNESS);//separator
	nk_layout_row_template_push_static(ctx, 100);//HV
	nk_layout_row_template_push_dynamic(ctx);//val
	nk_layout_row_template_push_static(ctx, 50);//V
	nk_layout_row_template_end(ctx);

	gui_screen_race_name_value_unit(ctx, "LV", candb_messages[CANDB_MSG_ECUB_GLV_AMS]->fields[CANDB_ECUB_GLV_AMS_FIELD_VOLT]);
	nk_filled_color(ctx, separator_color);
	gui_screen_race_name_value_unit(ctx, "HV", candb_messages[CANDB_MSG_ECUA_ACPMEAS]->fields[CANDB_ECUA_ACPMEAS_FIELD_VOLT_HV_IN]);

	nk_layout_row_dynamic(ctx, -1, 1);
	nk_filled_color(ctx, separator_color);

	// body - important info
	nk_layout_row_dynamic(ctx, nk_get_remaining_vertical_space(ctx)-200, 1);
	if(nk_group_begin(ctx, "mode_specific", NK_WINDOW_NO_SCROLLBAR))
	{
		nk_layout_row_dynamic(ctx, 280, 1);
		if(nk_group_begin(ctx, "large", NK_WINDOW_NO_SCROLLBAR))
		{
			nk_style_push_font(ctx, &font_nk_large);
			nk_layout_row_template_begin(ctx, 0);
			nk_layout_row_template_push_dynamic(ctx);//property
			nk_layout_row_template_push_static(ctx, 150);//value
			nk_layout_row_template_push_dynamic(ctx);//unit
			nk_layout_row_template_end(ctx);
			

			switch(racemode)
			{
				case RACE_MODE_ACCELERATION:
					//speed
					gui_screen_race_name_value_unit(ctx, "SPD", candb_messages[CANDB_MSG_VDCU_BODY]->fields[CANDB_VDCU_BODY_FIELD_SPEED_REF]);
					//A
					candb_field_num_converted(candb_messages[CANDB_MSG_IMU_ACCELERATION]->fields[CANDB_IMU_ACCELERATION_FIELD_LONG], 0, &buffer);
					gui_screen_race_name_unit_value(ctx, "Ax", "G", buffer/9.81f);
					break;
				
				case RACE_MODE_DEMO:
				case RACE_MODE_AUTOCROSS:
					break;
				
				case RACE_MODE_ENDURANCE:
					gui_screen_race_name_value_unit(ctx, "SOC", candb_messages[CANDB_MSG_VDCU_SOC]->fields[CANDB_VDCU_SOC_FIELD_SOC]);
					{
						float buffer1=0;
						float buffer2=0;

						float ecua_max_temp = 0;
						candb_field_num_converted(candb_messages[CANDB_MSG_ECUA_AMSOVERALL]->fields[CANDB_ECUA_AMSOVERALL_FIELD_TEMP_MAX], 0, &ecua_max_temp);

						candb_field_num_converted(candb_messages[CANDB_MSG_MCF_THERMALMEASURESA]->fields[CANDB_MCF_THERMALMEASURESA_FIELD_TMOTSEN], 0, &buffer1);
						candb_field_num_converted(candb_messages[CANDB_MSG_MCF_THERMALMEASURESB]->fields[CANDB_MCF_THERMALMEASURESB_FIELD_TMOTSEN], 0, &buffer2);
						float mcf_max_motor_temp = max(buffer1, buffer2);

						candb_field_num_converted(candb_messages[CANDB_MSG_MCR_THERMALMEASURESA]->fields[CANDB_MCR_THERMALMEASURESA_FIELD_TMOTSEN], 0, &buffer1);
						candb_field_num_converted(candb_messages[CANDB_MSG_MCR_THERMALMEASURESB]->fields[CANDB_MCR_THERMALMEASURESB_FIELD_TMOTSEN], 0, &buffer2);
						float mcr_max_motor_temp = max(buffer1, buffer2);

						if(ecua_max_temp > 50)
						{
							nk_label_colored(ctx, "ACP", NK_TEXT_RIGHT, nk_rgb(255,0,0));
							nk_label_colored(ctx, ftoa(conversion_buffer, ecua_max_temp, 3, 0, ' '), NK_TEXT_RIGHT, nk_rgb(255,0,0));
							nk_label_colored(ctx, "C", NK_TEXT_LEFT, nk_rgb(255,0,0));
						}
						else
						{
							nk_label(ctx, "ACP", NK_TEXT_RIGHT);
							nk_label(ctx, ftoa(conversion_buffer, ecua_max_temp, 3, 0, ' '), NK_TEXT_RIGHT);
							nk_label(ctx, "C", NK_TEXT_LEFT);
						}

						uint8_t errors_shown = 0;
						#define MAX_ERRORS	1

						if(errors_shown < MAX_ERRORS && mcr_max_motor_temp > 100)
						{
							errors_shown++;
							nk_label_colored(ctx, "MCR", NK_TEXT_RIGHT, nk_rgb(255,0,0));
							nk_label_colored(ctx, ftoa(conversion_buffer, mcr_max_motor_temp, 3, 0, ' '), NK_TEXT_RIGHT, nk_rgb(255,0,0));
							nk_label_colored(ctx, "C", NK_TEXT_LEFT, nk_rgb(255,0,0));
						}
						if(errors_shown < MAX_ERRORS && mcf_max_motor_temp > 100)
						{
							errors_shown++;
							nk_label_colored(ctx, "MCF", NK_TEXT_RIGHT, nk_rgb(255,0,0));
							nk_label_colored(ctx, ftoa(conversion_buffer, mcf_max_motor_temp, 3, 0, ' '), NK_TEXT_RIGHT, nk_rgb(255,0,0));
							nk_label_colored(ctx, "C", NK_TEXT_LEFT, nk_rgb(255,0,0));
						}
					}
					//dSOC? step time/lap/...?
					break;
				
				case RACE_MODE_SKIDPAD:
					candb_field_num_converted(candb_messages[CANDB_MSG_IMU_ACCELERATION]->fields[CANDB_IMU_ACCELERATION_FIELD_LAT], 0, &buffer);
					gui_screen_race_name_unit_value(ctx, "Ay", "G", buffer/9.81f);
					break;
				
				default:
					break;
			}


			nk_style_pop_font(ctx);
			nk_group_end(ctx);
		}

		nk_layout_row_dynamic(ctx, nk_get_remaining_vertical_space(ctx), 1);
		if(nk_group_begin(ctx, "small", NK_WINDOW_NO_SCROLLBAR))
		{
			nk_layout_row_dynamic(ctx, -1, 1);
			nk_filled_color(ctx, separator_color);

			nk_layout_row_template_begin(ctx, 0);
			nk_layout_row_template_push_dynamic(ctx);//property
			nk_layout_row_template_push_static(ctx, 90);//value
			nk_layout_row_template_push_dynamic(ctx);//unit
			nk_layout_row_template_push_static(ctx, 3);//separator
			nk_layout_row_template_push_dynamic(ctx);//property
			nk_layout_row_template_push_static(ctx, 90);//value
			nk_layout_row_template_push_dynamic(ctx);//unit
			nk_layout_row_template_end(ctx);

			switch(racemode)
			{
				case RACE_MODE_ACCELERATION:
					gui_screen_race_name_unit_value(ctx, "TRQ", "\%", vdcu_param_get(parameter_set, CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_GAIN)->value);//TRQ
					nk_filled_color(ctx, separator_color);
					gui_screen_race_name_unit_value(ctx, "P", "kW", vdcu_param_get(parameter_set, CANDB_VDCU_VDCU_PARAM_VDCU_PWRLIM)->value);//P

					gui_screen_race_name_unit_value(ctx, "DIST", "\%", vdcu_param_get(parameter_set, CANDB_VDCU_VDCU_PARAM_VDCU_TV_DISTRIB)->value);//TRQ
					nk_filled_color(ctx, separator_color);
					gui_screen_race_name_unit_value(ctx, "SLIP", "\%", vdcu_param_get(parameter_set, CANDB_VDCU_VDCU_PARAM_VDCU_TC_SLIP_SP)->value);//SLIP

					nk_hspacer(ctx);
					nk_hspacer(ctx);
					nk_hspacer(ctx);
					nk_filled_color(ctx, separator_color);
					break;
				
				case RACE_MODE_DEMO:
				case RACE_MODE_AUTOCROSS:
					break;
				
				case RACE_MODE_ENDURANCE:
					break;
				
				case RACE_MODE_SKIDPAD:
					gui_screen_race_name_unit_value(ctx, "TRQ", "\%", vdcu_param_get(parameter_set, CANDB_VDCU_VDCU_PARAM_VDCU_TRQ_GAIN)->value);//TRQ
					nk_filled_color(ctx, separator_color);
					gui_screen_race_name_unit_value(ctx, "TvF", "\%", vdcu_param_get(parameter_set, CANDB_VDCU_VDCU_PARAM_VDCU_TV_FRONT_GAIN)->value);//TvF

					gui_screen_race_name_unit_value(ctx, "DIST", "\%", vdcu_param_get(parameter_set, CANDB_VDCU_VDCU_PARAM_VDCU_TV_DISTRIB)->value);//TRQ
					nk_filled_color(ctx, separator_color);
					gui_screen_race_name_unit_value(ctx, "TvR", "\%", vdcu_param_get(parameter_set, CANDB_VDCU_VDCU_PARAM_VDCU_TV_REAR_GAIN)->value);//TvR

					gui_screen_race_name_unit_value(ctx, "?", "\%", 0);//?
					nk_filled_color(ctx, separator_color);
					gui_screen_race_name_unit_value(ctx, "SLIP", "\%", vdcu_param_get(parameter_set, CANDB_VDCU_VDCU_PARAM_VDCU_TC_SLIP_SP)->value);//SLIP
					break;					
				
				default:
					break;
			}



			nk_group_end(ctx);
		}


		nk_group_end(ctx);
	}

	//bottom bargraphs
	
	nk_layout_row_template_begin(ctx, 30);
	nk_layout_row_template_push_static(ctx, 100);//name
	nk_layout_row_template_push_static(ctx, 100);//value
	nk_layout_row_template_push_dynamic(ctx);
	nk_layout_row_template_end(ctx);

	struct nk_style_progress default_prog_style = ctx->style.progress;

	ctx->style.progress.active.data.color = nk_rgb(0, 255, 0);

	nk_label(ctx, "ACC", NK_TEXT_CENTERED);
	field = candb_messages[CANDB_MSG_ECUP_PEDALS]->fields[CANDB_ECUP_PEDALS_FIELD_APPS_POS];
	candb_field_num_converted(field , 0, &buffer);
	nk_label(ctx, ftoa(conversion_buffer, buffer, 5, 1, ' '), NK_TEXT_RIGHT);//acc
	buffer -= field->type_specific.num.min;
	nk_prog(ctx, buffer, field->type_specific.num.max - field->type_specific.num.min, 0);

	ctx->style.progress.active.data.color = nk_rgb(204, 35, 0);
	
	nk_label(ctx, "BRK", NK_TEXT_CENTERED);
	field = candb_messages[CANDB_MSG_ECUP_PEDALS]->fields[CANDB_ECUP_PEDALS_FIELD_BRAKE_POS];
	candb_field_num_converted(field , 0, &buffer);
	nk_label(ctx, ftoa(conversion_buffer, buffer, 5, 1, ' '), NK_TEXT_RIGHT);//brk front
	buffer -= field->type_specific.num.min;
	nk_prog(ctx, buffer, field->type_specific.num.max - field->type_specific.num.min, 0);

	ctx->style.progress.active.data.color = nk_rgb(152, 0, 0);

	nk_label(ctx, "BRK F", NK_TEXT_CENTERED);
	field = candb_messages[CANDB_MSG_ECUP_PRESSURE]->fields[CANDB_ECUP_PRESSURE_FIELD_BRAKEF];
	candb_field_num_converted(field , 0, &buffer);
	nk_label(ctx, ftoa(conversion_buffer, buffer, 5, 1, ' '), NK_TEXT_RIGHT);//brk front
	buffer -= field->type_specific.num.min;
	nk_prog(ctx, buffer, field->type_specific.num.max - field->type_specific.num.min, 0);

	ctx->style.progress.active.data.color = nk_rgb(204, 65, 37);

	nk_label(ctx, "BRK R", NK_TEXT_CENTERED);
	field = candb_messages[CANDB_MSG_ECUP_PRESSURE]->fields[CANDB_ECUP_PRESSURE_FIELD_BRAKER];
	candb_field_num_converted(field , 0, &buffer);
	nk_label(ctx, ftoa(conversion_buffer, buffer, 5, 1, ' '), NK_TEXT_RIGHT);//brk front
	buffer -= field->type_specific.num.min;
	nk_prog(ctx, buffer, field->type_specific.num.max - field->type_specific.num.min, 0);

	ctx->style.progress = default_prog_style;

	// nk_layout_row_template_begin(ctx, 30);
	// nk_layout_row_template_push_static(ctx, 100);//name
	// nk_layout_row_template_push_dynamic(ctx);
	// nk_layout_row_template_push_static(ctx, 100);//value
	// nk_layout_row_template_push_dynamic(ctx);
	// nk_layout_row_template_end(ctx);

	nk_label(ctx, "STW", NK_TEXT_CENTERED);
	field = candb_messages[CANDB_MSG_ECUF_STW]->fields[CANDB_ECUF_STW_FIELD_ANGLE];
	candb_field_num_converted(field , 0, &buffer);
	nk_label(ctx, ftoa(conversion_buffer, buffer, 5, 1, ' '), NK_TEXT_RIGHT);//brk front
	buffer -= field->type_specific.num.min;
	nk_prog(ctx, buffer, field->type_specific.num.max - field->type_specific.num.min, 0);

}
