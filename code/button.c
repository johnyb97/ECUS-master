#include "button.h"

void button_process(button_t *const *buttons)
{
	button_t *btn;
	for(; *buttons != NULL; buttons++)
	{
		btn = *buttons;
		bool now_pressed = gpio_read(&btn->gpio) ^ btn->active_high;
		if(now_pressed)
		{
			//is still pressed
			if(btn->hold_time > 0)
			{
				if(btn->hold_time < btn->hold_threshold)//still counting holdtime
					btn->hold_time++;

				else if(btn->hold_time == btn->hold_threshold)//held for long enough
				{
					btn->hold_time ++;//add one more, to not trigger this evt next time, counting stops
					if(btn->sensitive & BTN_EVT_HOLD_TIMEOUT && btn->callback != NULL)
						btn->callback(btn, BTN_EVT_HOLD_TIMEOUT);
				}
			}
			//pressed now, was not pressed
			else
			{
				btn->hold_time=1;
				btn->clicks++;
				if(btn->sensitive & BTN_EVT_PRESS && btn->callback != NULL)
					btn->callback(btn, BTN_EVT_PRESS);
			}
		}
		//not pressed now
		else
		{
			//was pressed
			if(btn->hold_time > 0)
			{
				if(	btn->sensitive & BTN_EVT_RELEASE &&
					btn->callback != NULL)
					btn->callback(btn, BTN_EVT_RELEASE);

				if(	btn->sensitive & BTN_EVT_CLICK && 
					btn->hold_time < btn->click_long_threshold &&
					btn->callback != NULL)//NOT held for long enough
					btn->callback(btn, BTN_EVT_CLICK);
				
				if(	btn->sensitive & BTN_EVT_CLICK_LONG && 
					btn->hold_time > btn->click_long_threshold &&
					btn->hold_time < btn->hold_threshold &&
					btn->callback != NULL)
					btn->callback(btn, BTN_EVT_CLICK_LONG);

				btn->hold_time = 0;
			}
		}
	}
}