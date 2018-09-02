#ifndef _CIRCULAR_BUFFER_LIB
	#define _CIRCULAR_BUFFER_LIB
	#include "config.h"
	#include "misc.h"

	typedef struct
	{
		void *buffer;			// data buffer
		void *buffer_end;		// end of data buffer
		void *volatile head;	// pointer to head
		void *volatile tail;	// pointer to tail
		const char *name;
		volatile size_t usage;			// number of items in the buffer
		size_t capacity;				// maximum number of items in the buffer
		size_t sz;						// size of each item in the buffer
		volatile bool overflow;			// flag, if overflow happened
	} circular_buffer_t;

	static inline uint16_t cb_empty_space(circular_buffer_t *cb)
	{
		return cb->capacity-cb->usage;
	}

	static inline uint16_t cb_used_space(circular_buffer_t *cb)
	{
		return cb->usage;
	}
	#define CB_INIT_STATIC(_cb_buffer, NAME)	{\
		.name = NAME,\
		.buffer = _cb_buffer,\
		.buffer_end = (char *)_cb_buffer + array_length(_cb_buffer) * sizeof(_cb_buffer[0]),\
		.capacity = array_length(_cb_buffer),\
		.usage = 0,\
		.sz = sizeof(_cb_buffer[0]),\
		.head = _cb_buffer,\
		.tail = _cb_buffer,\
		.overflow = false,\
	}

	void cb_init(circular_buffer_t *cb, void *buffer, size_t capacity, size_t sz);
	void cb_reset(circular_buffer_t *cb);
	status_t cb_push(circular_buffer_t *cb, const void *item);
	status_t cb_pop(circular_buffer_t *cb, void *item);
	status_t cb_peek(circular_buffer_t *cb, size_t offset, void **item);
	#ifdef CAN_BLOCK_OPERATIONS
		status_t cb_push_block(circular_buffer_t *cb, const void *item, size_t length);
		array_info cb_get_block(circular_buffer_t *cb);
		status_t cb_discard_block(circular_buffer_t *cb, size_t length);
	#endif

#endif