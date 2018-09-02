#include "goodix.h"
#include "debug.h"

// #include "debug_enable.h"


static const uint8_t gt_reg_coord_status[]={0x81,0x4E};
static const uint8_t zero=0;

void gt_process_touches(gt_handle_t *handle)
{
	DEBUG_STR("-> GT process\n");
	for(uint8_t idx=0; idx<handle->contacts; idx++)
	{
		CONVERT_FROM_LE_2B_INPLACE(handle->coords[idx].x);
		CONVERT_FROM_LE_2B_INPLACE(handle->coords[idx].y);
		CONVERT_FROM_LE_2B_INPLACE(handle->coords[idx].size);
		DEBUG_NUM(handle->coords[idx].track_id,2);
		DEBUG_NUM(handle->coords[idx].x,4);
		DEBUG_NUM(handle->coords[idx].y,4);
		DEBUG_NUM(handle->coords[idx].size,4);
		DEBUG_CH('\t');
	}
	DEBUG_NL();

	if(handle->callback != NULL)
		handle->callback(handle->coords, handle->contacts);
		
	handle->updated=true;
}

void gt_read_touches(gt_handle_t *handle)
{
	DEBUG_STR("-> GT read\n");
	handle->contacts=handle->touch_status_reg&0x0F;

	if(handle->contacts>0 && handle->contacts<=GT_MAX_TOUCHES)
	{
		//select register
		i2c_add_task_start_write(handle->i2c, 0x5D);
		i2c_add_task_write(handle->i2c, gt_reg_coord_status, 2, true);

		//read touch data
		i2c_add_task_start_read(handle->i2c, 0x5D);
		i2c_add_task_read(handle->i2c, (uint8_t*)&handle->coords, handle->contacts*8, true);

		//clear status register, as we read all data
		i2c_add_task_start_write(handle->i2c, 0x5D);
		i2c_add_task_write(handle->i2c, gt_reg_coord_status, 2, false);
		i2c_add_task_write_ext(handle->i2c, &zero, 1, true, (void(*)(void*))gt_process_touches, handle);
	}
	else
	{
		i2c_add_task_start_write(handle->i2c, 0x5D);
		i2c_add_task_write(handle->i2c, gt_reg_coord_status, 2, false);
		i2c_add_task_write(handle->i2c, &zero, 1, true);
	}
}

void gt_handle_irq(gt_handle_t *handle)
{
	DEBUG_STR("-> GT irq\n");
	//select register
	i2c_add_task_start_write(handle->i2c , 0x5D);
	i2c_add_task_write(handle->i2c, gt_reg_coord_status, 2, true);

	//read register(status)
	i2c_add_task_start_read(handle->i2c, 0x5D);
	i2c_add_task_read_ext(handle->i2c, &handle->touch_status_reg, 1, true, (void(*)(void*))gt_read_touches, handle);
}
