#include "candb_msg.h"
#include <string.h>
#include "systick.h"
#include "debug.h"
#include <math.h>

// #include "debug_enable.h"

typedef union{
	uint64_t ui64;
	int64_t  si64;
	float fl;
	uint8_t raw[8];
}aligned_data_64_t;

static const candb_msg_t *candb_find_msg_by_id(uint16_t id)
{
	const candb_msg_t *const *msg_ptr_ptr = candb_messages;
	while(*msg_ptr_ptr != NULL)
	{
		if((*msg_ptr_ptr)->id == id)
			return *msg_ptr_ptr;
		msg_ptr_ptr++;
	}
	return NULL;
}

static status_t candb_field_extract(const candb_msg_field_t *field, uint8_t *data)
{
	aligned_data_64_t parsed;
	*field->timestamp = SysTick_uptime();
	for(uint8_t array_idx=0; array_idx<field->count; array_idx++)
	{
		parsed.si64=0;
		
		//version A
		uint8_t offset=field->offset+(array_idx*field->bits);
		const uint8_t used_bytes = (field->bits+offset+7)/8;//cool huh? (divide is always ceiling, so we add 7 to be sure to include even 1 bit in byte is rounded up)

		memcpy(&parsed.raw, data, used_bytes);
		parsed.ui64>>=offset;
		
		const uint64_t mask=(1<<field->bits)-1;
		parsed.ui64&=mask;
		//extracted dota are now right aligned in parsed.ui64
		
		switch(field->type)
		{
			case CANDB_MSG_FIELD_TYPE_FLOAT:
				field->type_specific.num.value[array_idx].fl = parsed.fl;
				break;
			
			case CANDB_MSG_FIELD_TYPE_INT:
				if(parsed.ui64 & 1<<(field->bits-1))//is it negative number? (top bit == 1)
				{
					uint64_t sign_mask = -1;
					bit_clr(sign_mask, mask);
					parsed.ui64 |= sign_mask;
				}
				field->type_specific.num.value[array_idx].si = parsed.si64;
				break;
			
			case CANDB_MSG_FIELD_TYPE_UINT:
				field->type_specific.num.value[array_idx].ui = parsed.ui64;
				break;
			
			case CANDB_MSG_FIELD_TYPE_BOOL:
				field->type_specific.bl.value[array_idx] = parsed.ui64;
				break;

			case CANDB_MSG_FIELD_TYPE_ENUM:
				field->type_specific.en.value[array_idx] = parsed.ui64;
				break;

			case CANDB_MSG_FIELD_TYPE_MUX:
				field->type_specific.mux.value[array_idx] = parsed.ui64;
				break;

		};
	}
	return STAT_OK;
	
}

//so recursive, much fancy....
static status_t candb_parse_fields(const candb_msg_field_t *const *const fields, uint8_t *data)
{
	status_t status=STAT_OK;

	const candb_msg_field_t *const *field_ptr_ptr=fields;

	//cycle though all fields set (msg, muxed set)
	while(*field_ptr_ptr != NULL)
	{

		const candb_msg_field_t *const field_ptr = *field_ptr_ptr;

		status_t status=candb_field_extract(field_ptr, data);
		if(status!=STAT_OK) return status;

		// if(field_ptr->type == CANDB_MSG_FIELD_TYPE_MUX)
		// {
		// 	status = candb_parse_fields(field_ptr->type_specific.mux.muxed_fields[*(field_ptr->type_specific.mux.value)], data);
		// 	if(status!=STAT_OK) return status;
		// }
		field_ptr_ptr++;
	}
	return status;
}

void candb_set_callback(candb_enum_msg_t msg, candb_msg_callback_p callback)
{
	if(callback!=NULL)
	{
		*candb_messages[msg]->callback=callback;
	}
}



// void candb_encode(uint8_t *buffer, candb_enum_msg_t msg, ...)
// {

// }

status_t candb_decode(uint32_t id, uint8_t length, uint8_t *data)
{
	DEBUG_STR("decode started\n");
	status_t status=STAT_OK;
	const candb_msg_t *msg = candb_find_msg_by_id(id);
	if(msg==NULL)
	{
		// DEBUG_CRITICAL_STR("ID NOT found! ");
		// DEBUG_CRITICAL_NUM_EX(id, 0, ' ', 16);
		// DEBUG_CRITICAL_NL();
		return STAT_ERR_NOT_FOUND;
	}
	
	// DEBUG_STR("ID found\n");
	// DEBUG_STR(msg->description.name);
	// DEBUG_NL();
	
	if(length!=msg->length)
	{
		DEBUG_STR("length mismatch: exp ");
		DEBUG_NUM_EX(msg->length, 2, ' ', 16);
		DEBUG_STR(" is ");
		DEBUG_NUM_EX(length, 2, ' ', 16);
		DEBUG_NL();
		return STAT_ERR_LENGTH_MISMATCH;
	}
	
	*msg->timestamp = SysTick_uptime();

	status = candb_parse_fields(msg->fields, data);
	if(status!=STAT_OK) return status;
	
	if(*msg->callback != NULL)
	{
		(*msg->callback)(msg);
	}
	return STAT_OK;
}

num_validity_t candb_field_num_converted(const candb_msg_field_t *const field, uint8_t index, float *value)
{
	float buffer=0;
	num_validity_t validity;

	switch(field->type)
	{
		case CANDB_MSG_FIELD_TYPE_INT:
			buffer=field->type_specific.num.value[index].si;
			break;
		
		case CANDB_MSG_FIELD_TYPE_UINT:
			buffer=field->type_specific.num.value[index].ui;
			break;
		
		case CANDB_MSG_FIELD_TYPE_FLOAT:
			buffer=field->type_specific.num.value[index].fl;
			break;
		
		default:
			buffer=NAN;
			
	}
	
	if(!isfinite(buffer))
		validity = INVALID_NAN;
	else
	{
		buffer = buffer*field->type_specific.num.factor + field->type_specific.num.offset;
		if(buffer < field->type_specific.num.min)
			validity = INVALID_MIN;
		else if(buffer > field->type_specific.num.max)
			validity = INVALID_MAX;
		else
			validity = VALID;
	}

	if(value!=NULL)
		*value=buffer;
		
	return validity;
}

const char *candb_find_description(const candb_descrition_map_t *const *map_ptr_ptr, uint8_t key)
{
	for(;  *map_ptr_ptr != NULL; map_ptr_ptr++)
	{
		if((*map_ptr_ptr)->id == key)
			return (*map_ptr_ptr)->text;
	}
	return NULL;
}
