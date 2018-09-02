#include "qei.h"

void qei_callback(qei_handle_t *qei)
{
	int8_t change = 0;
	bool A = gpio_read(&qei->gpio_edge);
	bool B = gpio_read(&qei->gpio_lvl);

	if(qei->act_on_rising && A)
	{
		if(B)
			change = 1;
		else
			change = -1;
	}
	
	if(qei->act_on_falling && !A)
	{
		if(B)
			change = 1;
		else
			change = -1;
	}
	
	if(qei->reverse_direction)
		change = -change;
	
	qei->position += change;

	if(qei->event_callback != NULL)
	{
		if(qei->sensitive&QEI_EVT_INC && change > 0)
		{
			if(qei->evt_cnt < 0)//was counting in the other direction
				qei->evt_cnt = 0;
			
			if(qei->evt_cnt == qei->evt_prescaler)
			{
				qei->event_callback(QEI_EVT_INC, qei->position);
				qei->evt_cnt = 0;
			}
			else
				qei->evt_cnt++;
		}
		
		if(qei->sensitive&QEI_EVT_DEC && change < 0)
		{
			if(qei->evt_cnt > 0)//was counting in the other direction
				qei->evt_cnt = 0;
			
			if(qei->evt_cnt == -qei->evt_prescaler)
			{
				qei->event_callback(QEI_EVT_DEC, qei->position);
				qei->evt_cnt = 0;
			}
			else
				qei->evt_cnt--;
		}
	}
}