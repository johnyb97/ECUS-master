#include "field_tracker.h"
#include "candb_msg.h"

#define TRACKER_SLOT(SIZE)	\
		(tracker_field_t[]){{\
			.msg=NULL,\
			.msg_field=NULL,\
			.last_timestamp=0,\
			.field_index=0,\
			.data={\
				.buffer=(float [SIZE]){},\
				.length=SIZE,\
				.usage=0,\
			},\
		}}\


tracker_t default_tracker = {
	.fields=(tracker_field_t *[]){
		TRACKER_SLOT(200),
		TRACKER_SLOT(200),
		TRACKER_SLOT(200),
		TRACKER_SLOT(200),
		TRACKER_SLOT(200),
		NULL
	},
};

tracker_t *field_tracker_get_default(void)
{
	return &default_tracker;
}

static float *field_tracker_round_slot(tracker_data_t *data, float *slot_ptr)
{
	if(slot_ptr >= data->buffer+data->length)
	{
		slot_ptr -= data->length;
	}
	return slot_ptr;
}

void field_tracker_value_add(tracker_field_t *field, float value)
{
	tracker_data_t *data = &field->data;
	if(data->start_ptr==NULL)
	{
		data->start_ptr = data->buffer;
		data->usage = 0;
	}
	float *next_data_slot = field_tracker_round_slot(data, data->start_ptr + data->usage);
	*next_data_slot = value;

	//if full, move start to next position, because value start was overwritten by newest one
	if(data->length == data->usage)
		data->start_ptr = field_tracker_round_slot(data, data->start_ptr + 1);

	data->usage = min(data->usage+1, data->length);
}

float *field_tracker_read_value(tracker_field_t *field, uint16_t *iateration_counter)
{
	tracker_data_t *data = &field->data;
	float *output;

	if(*iateration_counter >= data->usage)
		return NULL;
	else
		output = field_tracker_round_slot(data, data->start_ptr + *iateration_counter);
		
	(*iateration_counter)++;
	return output;
}

/**
 * @brief Iterate over watched fields, and copy value if updated
 * 
 * @param tracker 
 */
void field_tracker_process(tracker_t *tracker)
{
	for(tracker_field_t **field_ptr_ptr=tracker->fields; *field_ptr_ptr!=NULL; field_ptr_ptr++)
	{
		tracker_field_t *field = *field_ptr_ptr;

		if(field->msg_field != NULL)
		{
			if(field->last_timestamp != *field->msg_field->timestamp)
			{
				field->last_timestamp = *field->msg_field->timestamp;
				float value;
				candb_field_num_converted(field->msg_field, field->field_index, &value);
				field_tracker_value_add(field, value);
			}
		}
	}
}

void field_tracker_track_new(tracker_field_t *field, const candb_msg_t *msg, const candb_msg_field_t *msg_field, uint8_t field_index)
{
	field->data.usage=0;
	field->msg=msg;
	field->msg_field=msg_field;
	field->field_index=field_index;
}