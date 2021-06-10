#ifndef LCD_H_
#define LCD_H_
#include "stdint.h"
#define RS 0x10   //PA4
#define RW 0x08  //PA3
#define E 0x04  //PA2

void Init(void);
void LCD_Command (unsigned char command);
void LCD_Data (char data);
void Print (char * string);

#endif