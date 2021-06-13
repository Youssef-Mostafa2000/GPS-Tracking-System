#include "C:/Keil/Labware/TM4C123GH6PM.h"
#include "Systick.h"

void Init_Systick()
{
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_RELOAD_R = 0x00FFFFFF;
	NVIC_ST_CTRL_R = 0x00000005;
}

void Systick_Wait(uint32_t delay)
{
	NVIC_ST_RELOAD_R = delay - 1;
	NVIC_ST_CURRENT_R = 0;
	while ((NVIC_ST_CTRL_R & 0x00010000) == 0)
	{
	}
}

void Systick_Wait1ms(uint32_t delay)
{
	unsigned long i;
	for (i = 0; i < delay; i++)
	{
		Systick_Wait(48000);
	}
}