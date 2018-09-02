#include "circular_buffer.h"
#include "misc.h"
#include "debug.h"

char buffer[BUFF_SIZE];

#ifdef DEBUG_CB
	#pragma message "CB debug enabled!"
	#include "debug_enable.h"

	void cb_print_info(circular_buffer_t *cb)
	{
		DEBUG_STR("   TL: ");
		DEBUG_NUM(((uint32_t)cb->tail-(uint32_t)cb->buffer), 5);
		DEBUG_STR(" HD: ");
		DEBUG_NUM(((uint32_t)cb->head-(uint32_t)cb->buffer), 5);
		if(cb->tail <= cb->head)
		{
			DEBUG_STR(" LIN");
		}
		else
		{
			DEBUG_STR(" CIR");
		}
		DEBUG_STR(" USG: ");
		DEBUG_NUM(cb->usage, 5);
		DEBUG_NL();
	}

	void cb_print_block(const char *start, uint16_t length)
	{
		DEBUG_CH('>');
		for(uint16_t l=0; l<length; l++)
			DEBUG_CH(start[l]);
		DEBUG_STR("<\n");
	}
#else
	#define cb_print_info(A) do{}while(0);
	#define cb_print_block(A,B) do{}while(0);
#endif



void cb_init(circular_buffer_t *cb, void *buffer, size_t capacity, size_t sz)
{
	cb->buffer = buffer;
	if(cb->buffer == NULL)
	{
		// handle error
	}
	cb->buffer_end = (char *)cb->buffer + capacity * sz;
	cb->capacity = capacity;
	cb->usage = 0;
	cb->sz = sz;
	cb->head = cb->buffer;
	cb->tail = cb->buffer;
	cb->overflow = false;
}

void cb_reset(circular_buffer_t *cb)
{
	cb->usage = 0;
	cb->head = cb->buffer;
	cb->tail = cb->buffer;
	cb->overflow=false;
}

status_t cb_push(circular_buffer_t *cb, const void *item)
{
	if(cb->usage >= cb->capacity){
		cb->overflow=true;
		DEBUG_CRITICAL_STR("CB overflow! CB: ");
		DEBUG_CRITICAL_STR(cb->name);
		DEBUG_CRITICAL_NL();
		return STAT_ERR_OVERFLOW;
	}
	memcpy(cb->head, item, cb->sz);

	DEBUG_STR("push: ");
	DEBUG_NUM((int32_t)*((int8_t*)item), 5);
	// DEBUG_NL();

	cb->head = (char*)cb->head + cb->sz;
	if(cb->head == cb->buffer_end)
	{
		cb->head = cb->buffer;

	DEBUG_STR("circled\n");

	}
	cb->usage++;

	DEBUG_STR(" USG: ");
	DEBUG_NUM(cb->usage, 5);
	DEBUG_NL();

	return STAT_OK;
}

status_t cb_peek(circular_buffer_t *cb, size_t offset, void **item)
{
	if(cb->usage <= offset){
		// fault_end();
		return STAT_ERR_UNDERFLOW;
	}

	void *cursor;

	cursor = (char*)cb->tail + cb->sz*offset;
	if(cursor >= cb->buffer_end)
	{
		cursor -= cb->capacity*cb->sz;
	}
	*item = cursor;
	return STAT_OK;
}

status_t cb_pop(circular_buffer_t *cb, void *item)
{
	if(cb->usage == 0){
		// fault_end();
		return STAT_ERR_UNDERFLOW;
	}
	memcpy(item, cb->tail, cb->sz);
	cb->tail = (char*)cb->tail + cb->sz;
	if(cb->tail == cb->buffer_end)
	{
		cb->tail = cb->buffer;
	}
	cb->usage--;

	DEBUG_STR("pop: ");
	DEBUG_NUM((int32_t)*((int8_t*)item), 5);
	DEBUG_STR(" USG: ");
	DEBUG_NUM(cb->usage, 5);
	DEBUG_NL();

	return STAT_OK;
}

#ifdef CAN_BLOCK_OPERATIONS
status_t cb_push_block(circular_buffer_t *cb, const void *item, size_t length)
{
	DEBUG_STR("PUSH ");
	if(cb->usage+length >= cb->capacity){
		cb->overflow=true;
		DEBUG_CRITICAL_STR("CB block overflow! CB: ");
		DEBUG_CRITICAL_STR(cb->name);
		DEBUG_CRITICAL_NL();
		return STAT_ERR_OVERFLOW;
	}

	size_t block_length = min((int32_t)length, (char*)cb->buffer_end - (char*)cb->head);
	if(block_length != length)
	{
		DEBUG_STR("  SPL: ");
		DEBUG_NUM(block_length, 4);
		DEBUG_STR(" + ");
		DEBUG_NUM(length-block_length, 4);
		DEBUG_NL();
	}
	else
	{
		DEBUG_STR("  LIN: ");
		DEBUG_NUM(length, 5);
		DEBUG_NL();
	}

	cb_print_info(cb);
	memcpy(cb->head, item, block_length);
	cb->head = (char*)cb->head + cb->sz*block_length;
	if(cb->head == cb->buffer_end)
		cb->head=cb->buffer;

	if(block_length != length)
	{
		memcpy((char*)cb->head, (char*)item + block_length*cb->sz , length-block_length);
		cb->head = (char*)cb->head + cb->sz*(length-block_length);
	}
	cb->usage+=length;
	cb_print_info(cb);
	cb_print_block(item, length);
	return STAT_OK;
}

array_info cb_get_block(circular_buffer_t *cb)
{
	DEBUG_STR("GET ");
	void *eob;
	array_info block={NULL,0};

	if(cb->usage==0)
	{
		DEBUG_STR(" EMPTY?!\n");
		return block;
	}

	if(cb->head > cb->tail)//linear part
	{
		eob=cb->head;
	}
	else
	{
		eob=cb->buffer_end;
	}
	block.size=((char*)eob - (char*)cb->tail)/cb->sz;
	block.ptr=cb->tail;

	DEBUG_STR(" ST: ");
	DEBUG_NUM(((uint32_t)block.ptr-(uint32_t)cb->buffer), 5);
	DEBUG_STR(" SP ");
	DEBUG_NUM(((uint32_t)block.ptr-(uint32_t)cb->buffer+block.size), 5);
	DEBUG_STR(" SZ: ");
	DEBUG_NUM(block.size, 5);
	DEBUG_NL();
	cb_print_info(cb);
	cb_print_block(block.ptr, block.size);
	return block;
}

status_t cb_discard_block(circular_buffer_t *cb, size_t length)
{
	DEBUG_STR("DEL ");
	if(length>cb->usage)
	{
		DEBUG_CRITICAL_STR("NO DATA, CB discard BLOCK prevented UNDERFLOW!!");
		// fault_end();
		return STAT_ERR_UNDERFLOW;
	}
	DEBUG_STR(" SZ: ");
	DEBUG_NUM(length, 5);

	if(length==0)
	{
		DEBUG_STR(" EMPTY?!\n");
		return STAT_OK;
	}

	if(cb->tail >= cb->buffer_end)//if out of bounds, circle back
	{
		DEBUG_STR(" CIR");
	}
	DEBUG_NL();

	cb_print_info(cb);

	cb->tail = (char*)cb->tail + cb->sz * length;

	if(cb->tail >= cb->buffer_end)//if out of bounds, circle back
	{
		cb->tail = (char*)cb->tail - (cb->capacity * cb->sz);
	}
	cb->usage -= length;
	cb_print_info(cb);
	return STAT_OK;
}
#endif