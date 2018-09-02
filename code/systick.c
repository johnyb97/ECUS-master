#include "systick.h"
#include "clock.h"

volatile uint32_t time_from_start=0;
void(*_SysTick_callback)(uint32_t time)=NULL;

void SysTick_Handler(void)
{
	time_from_start++;
	if(_SysTick_callback)
		_SysTick_callback(time_from_start);
}

void SysTick_init(void(*callback)(uint32_t time))
{
	_SysTick_callback=callback;
	SysTick_Config(F_CPU/F_SYSTICK);
}
