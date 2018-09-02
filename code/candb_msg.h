#ifndef _MSG_LIB
	#define _MSG_LIB
	
	#include <inttypes.h>
	#include <stdbool.h>
	#include <stdarg.h>

	#include "misc.h"
	#include "systick.h"

	#include "candb_structure.h"

	//move to misc.h?
	typedef enum {
		VALID,
		INVALID_MIN,
		INVALID_MAX,
		INVALID_NAN,
	}num_validity_t;

	void candb_set_callback(candb_enum_msg_t msg, candb_msg_callback_p callback);
	status_t candb_decode(uint32_t id, uint8_t length, uint8_t *data);
	num_validity_t candb_field_num_converted(const candb_msg_field_t *const field, uint8_t index, float *value);
	const char *candb_find_description(const candb_descrition_map_t *const *map_ptr_ptr, uint8_t key);
	
	static inline bool candb_msg_is_not_timeouted(const candb_msg_t *msg)
	{
		return (*(msg->timestamp) + msg->timeout) > SysTick_uptime();
	}


#endif