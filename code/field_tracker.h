#ifndef _CANDB_TRACKER
	#define _CANDB_TRACKER
	

	#include "candb_structure.h"
	#include "misc.h"


	typedef struct{
		float *const buffer;
		float *start_ptr;
		const uint16_t length;
		uint16_t usage;
	}tracker_data_t;

	typedef struct{
		const candb_msg_t *msg;
		const candb_msg_field_t *msg_field;
		uint32_t last_timestamp;
		tracker_data_t data;
		uint8_t field_index;
	}tracker_field_t;

	typedef struct{
		tracker_field_t **fields;
	}tracker_t;

	tracker_t *field_tracker_get_default(void);
	void field_tracker_value_add(tracker_field_t *field, float value);
	float *field_tracker_read_value(tracker_field_t *field, uint16_t *iateration_counter);
	void field_tracker_process(tracker_t *tracker);
	void field_tracker_track_new(tracker_field_t *field, const candb_msg_t *msg, const candb_msg_field_t *msg_field, uint8_t field_index);

#endif