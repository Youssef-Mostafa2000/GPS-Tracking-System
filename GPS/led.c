#include "C:/Keil/Labware/TM4C123GH6PM.h"
#include "led.h"

void InitPortF(void)
{
	SYSCTL_RCGC2_R |= 0x20 ;  //enable Port F
	while((SYSCTL_PRGPIO_R&0x00000020)==0){}  //Wait until Port F is ready
	GPIO_PORTF_LOCK_R	= 0x4C4F434B ;	
	GPIO_PORTF_DIR_R = 0x0E ;  //input PF0 , PF4 ,, output PF1-3
	GPIO_PORTF_CR_R = 0x1F ;  //enable changes for PF0-PF4
	GPIO_PORTF_DEN_R = 0x1F ;  //digital PF0-4
	GPIO_PORTF_AFSEL_R = 0 ;  //Clear PF0-4
	GPIO_PORTF_PUR_R = 0x11 ;  //pull up resistor for PF0 , PF4
	GPIO_PORTF_AMSEL_R = 0 ;  //Clear PF0-4
	GPIO_PORTF_PCTL_R = 0 ;
	
}

void Output(uint32_t data)
{
	GPIO_PORTF_DATA_R = data ;
}

void Distance_exceeds100(float distance)
{
	if(distance>=100)
	{
		Output(0x08);  //turn on Green LED when distance exceeds 100 m
	}
}