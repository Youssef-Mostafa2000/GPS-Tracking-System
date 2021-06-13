#include "C:/Keil/Labware/TM4C123GH6PM.h"
#include "lcd.h"
#include "systick.h"

void LCD_Command (unsigned char command)
{
	GPIO_PORTB_DATA_R = command ;	
	GPIO_PORTA_DATA_R |= E ;
	Systick_Wait1ms(2);
	GPIO_PORTA_DATA_R &= !(RS) ;  //RS = 0
	GPIO_PORTA_DATA_R &= !(RW);  //RW = 0
	Systick_Wait1ms(2);	
	GPIO_PORTA_DATA_R &= !(E) ;
}

void LCD_Data (char data)
{
	GPIO_PORTB_DATA_R = data ;
	GPIO_PORTA_DATA_R |= (E) ;
	Systick_Wait1ms(2);
	GPIO_PORTA_DATA_R |= (RS) ;  //RS = 1
	GPIO_PORTA_DATA_R &= ! (RW);
	Systick_Wait1ms(2);
	GPIO_PORTA_DATA_R &= !(E) ;
}

void Print (char * string)
{
	int counter = 0;
	while(*string != '\0')
	{
		LCD_Data(*string);
		counter ++ ;
		string++;
		if(counter==15)
		{
			LCD_Command(0xC0);
		}
	}
}

void Init()
{
	Systick_Wait1ms(50);	
	SYSCTL_RCGCGPIO_R |= 0x03;  //clock of portA , portB
	while((SYSCTL_PRGPIO_R&0x00000003)==0){}  //Wait until Port F is ready
	GPIO_PORTA_LOCK_R	= 0x4C4F434B ;
	GPIO_PORTA_CR_R |= 0x1C;   //00011100
	GPIO_PORTA_DIR_R |= 0x1C; //PA2-4
	GPIO_PORTA_DEN_R |= 0x1C; 
	//GPIO_PORTA_AFSEL_R &= !(0x1C);
	GPIO_PORTA_PUR_R &= !(0x1C);
  GPIO_PORTA_AMSEL_R &= !(0x1C);
	//GPIO_PORTA_PCTL_R &= !(0x1C);
	GPIO_PORTA_DEN_R |= 0x80;
	GPIO_PORTA_DIR_R |= 0x80;	
		
	GPIO_PORTB_LOCK_R	= 0x4C4F434B ;
	GPIO_PORTB_CR_R |= 0xFF;  //111101
	GPIO_PORTB_DIR_R |= 0xFF; //PB0-7
	GPIO_PORTB_DEN_R |= 0xFF; 
	GPIO_PORTB_AFSEL_R = 0;
	GPIO_PORTB_PUR_R = 0;
  GPIO_PORTB_AMSEL_R = 0;  
	GPIO_PORTB_PCTL_R &= !(0x1C);

	
  LCD_Command(0x30); //wakeup
	Systick_Wait1ms(1);	
	
	LCD_Command(0x38); //use 8-bit data
	Systick_Wait1ms(1);	
	LCD_Command(0x0E); //display ON
	Systick_Wait1ms(1);	
	LCD_Command(0x01); //clear display
	Systick_Wait1ms(2);	//2MS
	LCD_Command(0x0F); //LCD ON
	Systick_Wait1ms(2);
	LCD_Command(0x02); //
	Systick_Wait1ms(1);
}