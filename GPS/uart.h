#ifndef UART_H_
#define UART_H_
#include "stdint.h"

void UART_Init(void);
char UART0_Receive(void);
void UART0_Send(char data);
char UART2_Receive(void);
void UART2_Send(char data);

#endif