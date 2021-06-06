#include "Systick Init.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"

void Init_Systick()
{
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_RELOAD_R = 0x00FFFFFF;
	NVIC_ST_CTRL_R = 0x00000005;
}