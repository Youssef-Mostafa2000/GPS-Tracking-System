#include "uart.h"
#include "C:/Keil/Labware/TM4C123GH6PM.h"
#include "stdint.h"
#include "string.h"

void UART_Init(void)
{
	SYSCTL_RCGC1_R |= SYSCTL_RCGCUART_R0; //clock of UART0
	SYSCTL_RCGC2_R |= SYSCTL_RCGCGPIO_R0; //clock of PORT A
	UART0_CTL_R &= !(UART_CTL_UARTEN);  //disable UART0
	UART0_IBRD_R = 312 ;  //312
	UART0_FBRD_R = 32 ;  //32
	UART0_LCRH_R |= 0x00000070;  //1 bit stop , no parity , 8 bits word length
	UART0_CTL_R |= 0x00000301; //enable UART0 , Tx and 
	
	SYSCTL_RCGC1_R |= SYSCTL_RCGCUART_R2; //clock of UART2
	SYSCTL_RCGC2_R |= SYSCTL_RCGCGPIO_R3; //clock of PORT D
	UART2_CTL_R &= !(UART_CTL_UARTEN);  //disable UART2
	UART2_IBRD_R = 312 ;  //312
	UART2_FBRD_R = 32 ;  //32
	UART2_LCRH_R |= 0x00000070;  //1 bit stop , no parity , 8 bits word length
	UART2_CTL_R |= 0x00000301; //enable UART2 , Tx and 
	
	
	GPIO_PORTA_AFSEL_R |= 0x03; //PA0 and PA1
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011;  
	GPIO_PORTA_DEN_R |= 0x03;

  GPIO_PORTD_AFSEL_R |= 0xC0; //PD6 and PD7
	GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0x00FFFFFF)+0x11000000;  
	GPIO_PORTD_DEN_R |= 0xC0;
}



void UART0_Send(char data)
{
	while((UART0_FR_R&0x00000020)!=0){}  //Transmitter Fifo full
		UART0_DR_R = data ;
}

char UART0_Receive(void)
{
	while((UART0_FR_R&0x00000010)!=0){}  //Receiver Fifo empty 
		return ((char)(UART0_DR_R&0xFF));
}

void UART2_Send(char data)
{
	while((UART2_FR_R&0x00000020)!=0){}  //Transmitter Fifo full
		UART2_DR_R = data ;
}

char UART2_Receive(void)
{
	while((UART2_FR_R&0x00000010)!=0){}  //Receiver Fifo empty
		return ((char)(UART2_DR_R&0xFF));
}