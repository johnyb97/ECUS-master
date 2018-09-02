//DO NOT use ever again!
//total madness, stay sane, write your own...

#include "i2c.h"
#include "debug.h"
#include "circular_buffer.h"

// #include "debug_enable.h"

void i2c_add_task(i2c_handle_t *handle, i2c_task_t *task)
{
	DEBUG_STR("-> I2C add task ");
	switch(task->type)
	{
		case I2C_TASK_START:
			DEBUG_STR("(ST)");
			break;
		
		case I2C_TASK_WRITE:
			DEBUG_STR("(WR) ");
			DEBUG_NUM(task->task_specific.rw.bytes,2);
			break;
		
		case I2C_TASK_READ:
			DEBUG_STR("(RD) ");
			DEBUG_NUM(task->task_specific.rw.bytes,2);
			break;
		
		default:
			DEBUG_STR("(UNK)");
	}
	DEBUG_NL();
	CpuCriticalBlock(
		cb_push(handle->cb, task);
		if(task->type == I2C_TASK_READ || task->type == I2C_TASK_WRITE)
			if(task->task_specific.rw.close)
			{
				DEBUG_STR("\tstarting...\n");
				handle->stops_queued++;
				if(handle->current_task.type==I2C_TASK_IDLE)//if there is no running i2c task
					i2c_next_task(handle);
				else
					DEBUG_STR("\tBUSY, scheduled...\n");
			}
	);
}

void i2c_cr2_modify(I2C_TypeDef *dev, uint8_t bytes, bool reload)
{
	uint32_t cr2 = (dev->CR2 & ~(I2C_CR2_NBYTES_Msk | I2C_CR2_RELOAD_Msk)) | (bytes<<I2C_CR2_NBYTES_Pos) | I2C_CR2_AUTOEND;
	if(reload)
		bit_set(cr2, I2C_CR2_RELOAD);
	dev->CR2=cr2;
}

void i2c_next_task(i2c_handle_t *handle)
{
	DEBUG_STR("-> I2C next task\n");
	uint8_t prev_task_type = handle->current_task.type;
	
	if(handle->current_task.type!=I2C_TASK_IDLE)
	{
		if(handle->current_task.callback!=NULL)
		{
			DEBUG_STR("\tCB start\n");
			handle->current_task.callback(handle->current_task.arg);
			DEBUG_STR("\tCB end\n");
		}
	}
	if(handle->stops_queued==0)
	{
		handle->current_task.type=I2C_TASK_IDLE;
		DEBUG_STR("\tempty queue\n");
		return;
	}


	CpuCriticalBlock(
		if(cb_used_space(handle->cb)>0)
			cb_pop(handle->cb, (void*)&handle->current_task);
		else
		{
			DEBUG_STR("\tend\n");
			handle->current_task.type=I2C_TASK_IDLE;
			return;
		}
	);

	switch(handle->current_task.type)
	{
		case I2C_TASK_START:
			DEBUG_STR("\tstart\n");
			handle->dev->CR2 =	(1<<I2C_CR2_NBYTES_Pos)|
								(handle->current_task.task_specific.start.address<<(1+I2C_CR2_SADD_Pos))|(I2C_CR2_AUTOEND);
			
			i2c_task_t *next;
			cb_peek(handle->cb, 0, (void*)&next);
			if(!(next->task_specific.rw.close && next->task_specific.rw.bytes==1))
				bit_set(handle->dev->CR2, I2C_CR2_RELOAD);
			
			if(handle->current_task.task_specific.start.write==false)
			{
				DEBUG_STR("\tRD WRN SET\n");
				bit_set(handle->dev->CR2,I2C_CR2_RD_WRN);
			}

			bit_set(handle->dev->CR2, I2C_CR2_START);
			break;
			
		case I2C_TASK_READ:
		case I2C_TASK_WRITE:
			if(prev_task_type == I2C_TASK_START)
			{
				handle->current_task.task_specific.rw.start_workaround=true;//cr2 nbytes is reloaded after 1st byte
			}
			else
			{
				handle->current_task.task_specific.rw.start_workaround=false;
				i2c_cr2_modify(handle->dev, handle->current_task.task_specific.rw.bytes, !handle->current_task.task_specific.rw.close);
			}
			break;


		case I2C_TASK_IDLE:
			DEBUG_STR("\tidle\n");
			break;
	}
}

void i2c_task_close(i2c_handle_t *handle)
{
	CpuCriticalBlock(
		handle->stops_queued--;
	);
	i2c_next_task(handle);
}

void i2c_irq_handler(i2c_handle_t *handle)
{
	uint32_t isr=handle->dev->ISR;
	DEBUG_STR("-> I2C IRQ >>>\n");

	if(bit_get(isr, I2C_ISR_NACKF))
	{
		bit_set(handle->dev->ICR, I2C_ICR_NACKCF);
		DEBUG_STR("\tNACKF!\n");

		//pop all tasks til closing one
		i2c_task_t tmp_task = handle->current_task;
		while(true)
		{
			if((tmp_task.type == I2C_TASK_READ) || (tmp_task.type == I2C_TASK_WRITE))
				if(tmp_task.task_specific.rw.close)
					break;

			CpuCriticalBlock(
				if(cb_used_space(handle->cb)==0)
					break;
				
				cb_pop(handle->cb, &tmp_task);
			);
			DEBUG_STR(" POP");
		}
		DEBUG_NL();
		i2c_task_close(handle);
	}

	if(bit_get(isr, I2C_ISR_STOPF))
	{
		bit_set(handle->dev->ICR, I2C_ICR_STOPCF);//clear flag
		DEBUG_STR("\tSTOPF\n");
		switch(handle->current_task.type)
		{
			case I2C_TASK_WRITE:
			case I2C_TASK_READ:
				if(handle->current_task.task_specific.rw.close)
				{
					DEBUG_STR("\tOK scheduled\n");
					i2c_task_close(handle);
					return;
				}
				else
				{
					DEBUG_STR("\tERR stop not scheduled!\n");
				}
				break;
			default:
				DEBUG_STR("\tstop unexpected, NACKF?\n");
				break;
		}
	}

	if(bit_get(isr, I2C_ISR_TXIS))
	{
		DEBUG_STR("\tTXIS\n");
		switch(handle->current_task.type)
		{
			case I2C_TASK_START:
				DEBUG_STR("\t\tSTART\n");
				i2c_next_task(handle);
				if(handle->current_task.type!=I2C_TASK_READ && handle->current_task.type!=I2C_TASK_WRITE)
					break;//TODO: what to do when there is no next task
				__attribute__ ((fallthrough));
			case I2C_TASK_WRITE:
				DEBUG_STR("\tWR 0x");
				DEBUG_NUM_EX(*handle->current_task.task_specific.rw.data.w, 2, '0', 16);
				DEBUG_NL();
				handle->dev->TXDR = *handle->current_task.task_specific.rw.data.w++;
				handle->current_task.task_specific.rw.bytes--;
				break;

			default:
				DEBUG_STR("\t\tUNHANDLED!\n");
				return;
		}
	}

	if(bit_get(isr, I2C_ISR_RXNE))
	{
		DEBUG_STR("\tRXNE\n");
		switch(handle->current_task.type)
		{
			case I2C_TASK_START:
				DEBUG_STR("\t\tSTART\n");
				i2c_next_task(handle);
				if(handle->current_task.type!=I2C_TASK_READ && handle->current_task.type!=I2C_TASK_WRITE)
					break;//TODO: what to do when there is no next task
				__attribute__ ((fallthrough));
			case I2C_TASK_READ:
				*handle->current_task.task_specific.rw.data.r++ = handle->dev->RXDR;
				handle->current_task.task_specific.rw.bytes--;
				DEBUG_STR("\tRD 0x");
				DEBUG_NUM_EX(*handle->current_task.task_specific.rw.data.r, 2, '0', 16);
				DEBUG_NL();
				break;

			default:
				DEBUG_STR("\t\tUNHANDLED!\n");
				return;
		}
	}
	
	if(bit_get(isr, I2C_ISR_TCR))//Transfer Complete RELOAD
	{
		DEBUG_STR("\tI2C TCR\n");
		switch(handle->current_task.type)
		{
			case I2C_TASK_WRITE:
			case I2C_TASK_READ:
				if(handle->current_task.task_specific.rw.start_workaround)//first task after start is special, TCR happens after first byte sent, just configure CR2
				{
					handle->current_task.task_specific.rw.start_workaround=false;
					DEBUG_STR("\tprev start\n");
					i2c_cr2_modify(handle->dev, handle->current_task.task_specific.rw.bytes, !handle->current_task.task_specific.rw.close);
				}
				else
				{
					DEBUG_STR("\tNEXT\n");
					i2c_next_task(handle);
				}
				break;
			default:
				DEBUG_STR("\tUNHANDLED!\n");
				return;
		}
	}

	if(bit_get(isr, I2C_ISR_TC))//Transfer Complete
	{
		DEBUG_STR("\tI2C TC\n");
		switch(handle->current_task.type)
		{
			case I2C_TASK_WRITE:
			case I2C_TASK_READ:
				// i2c_next_task(handle);
				break;
			default:
				DEBUG_STR("\tUNHANDLED!\n");
				return;
		}
	}
}

void i2c_init(i2c_handle_t *handle, uint32_t tcfg)
{
	handle->stops_queued=0;
	handle->current_task.type=I2C_TASK_IDLE;

	handle->dev->TIMINGR = tcfg;
	handle->dev->CR1 = I2C_CR1_PE | I2C_CR1_TXIE | I2C_CR1_RXIE | I2C_CR1_NACKIE | I2C_CR1_STOPIE | I2C_CR1_TCIE; 
}



void i2c_add_task_start_ext(i2c_handle_t *handle, const uint8_t address, const bool write, void(*callback)(void *arg), void *callback_arg)
{
	i2c_task_t task=(i2c_task_t){
		.callback=callback,
		.arg=callback_arg,
		.type=I2C_TASK_START,
		.task_specific.start={
			.address=address,
			.write=write,
		}
	};
	i2c_add_task(handle,&task);
}

void i2c_add_task_write_ext(i2c_handle_t *handle, const uint8_t *data, const uint8_t length, const bool close, void(*callback)(void *arg), void *callback_arg)
{
	i2c_task_t task=(i2c_task_t){
		.callback=callback,
		.arg=callback_arg,
		.type=I2C_TASK_WRITE,
		.task_specific.rw={
			.data.w=data,
			.bytes=length,
			.close=close
		}
	};
	i2c_add_task(handle,&task);
}

void i2c_add_task_read_ext(i2c_handle_t *handle, uint8_t *data, const uint8_t length, const bool close, void(*callback)(void *arg), void *callback_arg)
{
	i2c_task_t task=(i2c_task_t){
		.callback=callback,
		.arg=callback_arg,
		.type=I2C_TASK_READ,
		.task_specific.rw={
			.data.r=data,
			.bytes=length,
			.close=close
		}
	};
	i2c_add_task(handle,&task);
}