#include "Systick_Wait.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"


void Systick_Wait(uint32_t delay)
{
	NVIC_ST_RELOAD_R = delay - 1;
	NVIC_ST_CURRENT_R = 0;
	while ((NVIC_ST_CTRL_R & 0x00010000) == 0)
	{
	}
}