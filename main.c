#include "lcd.h"
#include "C:/Keil/Labware/inc/TM4C123GH6PM.h"

int main (void)
{
	
	Init_Systick();
	Init();
	InitPortF();
	char * a = "Group ID : 1";
	
	while(1)
	{
		LCD_Command(0x01); //clear display
	  Systick_Wait1ms(2);	//2MS
		Print(a);
		Distance_exceeds100(120);  //Green LED will be turned on because distance is 120 meter
	}

}