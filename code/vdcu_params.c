#include "vdcu_params.h"
#include "config.h"
#include "candb/can_ECUS.h"
#include "systick.h"
#include "debug.h"

// #include "debug_enable.h"
#include "candb_msg.h"

vdcu_param_t *vdcu_param_get(vdcu_param_t *const *parameter_set, uint8_t id)
{
	vdcu_param_t *parameter;

	for(; *parameter_set != NULL; parameter_set++)
	{
		parameter = *parameter_set;
		if(parameter->id == id)
			return parameter;
	}
	return NULL;
}

void vdcu_param_periodic_update(vdcu_param_t *const *parameter_set)
{
	static uint8_t last_updated_id = 0;

	vdcu_param_t *parameter = parameter_set[last_updated_id];

	if(parameter->state != PARAM_STATE_SENT &&
		parameter->state != PARAM_STATE_TIMEOUT)
	{
		parameter->state = PARAM_STATE_UPDATE;
		parameter->retry_counter=0;
		parameter->last_change_id++;
	}
	
	last_updated_id++;

	if(parameter_set[last_updated_id] == NULL)
		last_updated_id = 0;
}

void vdcu_param_change(vdcu_param_t *parameter, uint16_t value)
{
	if(value == parameter->value)
		return;//ignore updates without value change
	
	parameter->last_change_id++;
	parameter->retry_counter=0;
	parameter->value = value;
	parameter->state = PARAM_STATE_MODIFIED;
}

void vdcu_param_process(vdcu_param_t *const *parameter_set)
{
	static uint8_t SEQ=0;
	if(SEQ > candb_messages[CANDB_MSG_VDCU_PARAM]->fields[CANDB_VDCU_PARAM_FIELD_SEQ]->type_specific.num.max)
		SEQ=0;

	vdcu_param_t *parameter;

	for(; *parameter_set != NULL; parameter_set++)
	{
		parameter=(*parameter_set);

		switch(parameter->state)
		{
			case PARAM_STATE_TIMEOUT:
				DEBUG_STR("PAR: (");
				DEBUG_STR(parameter->name);
				DEBUG_STR(") RETRY ");
				DEBUG_NUM(parameter->retry_counter, 1);
				DEBUG_NL();
				VDCU_send_Param(parameter->id, parameter->value, parameter->last_change_id, SEQ++);
				parameter->state = PARAM_STATE_SENT;
				parameter->sent_ts = SysTick_uptime();
				break;
				
			case PARAM_STATE_MODIFIED:
				DEBUG_STR("PAR: (");
				DEBUG_STR(parameter->name);
				DEBUG_STR(") modified, sending...\n");
				VDCU_send_Param(parameter->id, parameter->value, parameter->last_change_id, SEQ++);
				parameter->state = PARAM_STATE_SENT;
				parameter->sent_ts = SysTick_uptime();
				break;
			
			case PARAM_STATE_UPDATE:
				DEBUG_STR("PAR: (");
				DEBUG_STR(parameter->name);
				DEBUG_STR(") periodic update\n");
				VDCU_send_Param(parameter->id, parameter->value, parameter->last_change_id, SEQ++);
				parameter->state = PARAM_STATE_SENT;
				parameter->sent_ts = SysTick_uptime();
				break;
			
			case PARAM_STATE_SENT:
				if(parameter->sent_ts + VDCU_PARAM_TIMEOUT_MS < SysTick_uptime())
				{
					DEBUG_STR("PAR: (");
					DEBUG_STR(parameter->name);
					DEBUG_STR(") TIMEOUT\n");
					if(parameter->retry_counter < VDCU_PARAM_RETRY_COUNT)
					{
						parameter->state = PARAM_STATE_TIMEOUT;
						parameter->retry_counter++;
					}
					else
					{
						parameter->state = PARAM_STATE_FAILED;
						DEBUG_STR("PAR: (");
						DEBUG_STR(parameter->name);
						DEBUG_STR(") FAILED, giving up...\n");
					}

				}
				break;
			
			default:
				break;
		}
	}
}

void vdcu_param_ack_handler(const struct candb_msg *msg, vdcu_param_t *const *current_parameter_set)
{
	DEBUG_STR("PAR: ACK\n");
	vdcu_param_t *parameter;
	float buffer;

	if(msg->id != candb_messages[CANDB_MSG_VDCU_PARAM_ACK]->id)//wrong message ID
		return;
	for(vdcu_param_t *const *parameter_ptr = current_parameter_set; *parameter_ptr != NULL; parameter_ptr++)
	{
		parameter=(*parameter_ptr);
		//received ack message correspons to this parameter (parameter ID match)
		candb_field_num_converted(msg->fields[CANDB_VDCU_PARAM_ACK_FIELD_PARAM_ID], 0, &buffer);
		if(parameter->id == buffer)
		{
			//AND it is ack on latest request
			candb_field_num_converted(msg->fields[CANDB_VDCU_PARAM_ACK_FIELD_SEQ_PARAM], 0, &buffer);
			if(parameter->last_change_id == buffer)
			{
				//value confirmed?
				candb_field_num_converted(msg->fields[CANDB_VDCU_PARAM_ACK_FIELD_PARAM], 0, &buffer);
				if(parameter->value == buffer)
					parameter->state = PARAM_STATE_CONFIRMED_MATCH;
				else
					parameter->state = PARAM_STATE_CONFIRMED_MISMATCH;

				if(parameter->state != PARAM_STATE_SENT)
					DEBUG_STR("PAR: ACK unexpected!\n");
			}
			else
				DEBUG_STR("PAR: old ACK, ignored\n");
			
		}
	}
}