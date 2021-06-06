#include "Systick_Wait1ms.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"


void Systick_Wait1ms(uint32_t delay)
{
	unsigned long i;
	for (i = 0; i < delay; i++)
	{
		Systick_Wait(48000);
	}
}