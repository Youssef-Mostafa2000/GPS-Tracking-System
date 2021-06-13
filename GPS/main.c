#include "C:/Keil/Labware/TM4C123GH6PM.h"
#include "stdint.h"
#include "uart.h"
#include "lcd.h"
#include "string.h"
#include "stdlib.h"
#include "systick.h"
#include "stdio.h"
#include "math.h"
#include "gps.h"
#include "led.h"

int main()
{ 
 Init_Systick();
 UART_Init();
 Init();
 
 char read ;
 char reading [100];
 char longitude [12];
 char latitude [12];
 uint8_t comma=0;
 uint8_t status =0;
 uint8_t index=0; 
 char Distance [12]="abcdefghij";
 float long_swap [2];
 float lat_swap [2];
 float Total_Distance=0;
 uint8_t reading_counter=0;
 char longf [12];
 char latf [12];
 
 while(1)
 {
  LCD_Command(0x01); //clear display
   Systick_Wait1ms(2); //2MS
  index=0;
  read = UART2_Receive();
  comma = 0;
  if(read=='$')
  {
   read = UART2_Receive();
   if(read=='G')
   {
    read = UART2_Receive();
    if(read=='P')
    {
        read = UART2_Receive();
       if(read=='R')
       {
           read = UART2_Receive();
          if(read=='M')
          {
              read = UART2_Receive();
              if(read=='C')
              {
                  read = UART2_Receive();
                  if(read==',')
                  {
                   read = UART2_Receive();
                   if(read==',')
                    {
                     comma++;
                    }
                    reading_counter++;
                   while(read!='*')  //start reading from the first comma
                   {
                    reading[index]=read;
                    
                    index++;
                    read = UART2_Receive();
                    if(read==',')
                    {
                     comma++;
                    }
                    if (comma==1)
                    {
                     status = index;
                    }
                    
                   }
                   
                   
                   if (reading[status]=='A')  //if gps found a fixed signal 
                   {
                    
                     strncpy(latitude,reading+status+2,10); //obtain the latitude
                     strncpy(longitude,reading+status+2+10+3,11);  //obtain the longitude
                   }
                   else  //if gps didn't find a fixed signal
                   {
                    Print("Connecting...");
                    Systick_Wait1ms(1000);
                    UART0_Send('N'); 
                    continue;
                   }
                   
                   if(reading_counter==1)  //first reading
                   {
                    for(int i=0;i<2;i++)
                    {
                      long_swap[i] = atof(longitude);
                      lat_swap[i]=atof(latitude);
                     
                    }
                    
                   }
                   else if(reading_counter>1)
                   {
                    long_swap[0]=long_swap[1];
                    lat_swap[0]=lat_swap[1];
                    long_swap[1] = atof(longitude);
                    lat_swap[1]=atof(latitude);
                   }
                   
                   Total_Distance+=Calc_Distance(ToRadian(ToDegrees(long_swap[0])),ToRadian(ToDegrees(long_swap[1])),ToRadian(ToDegrees(lat_swap[1])),ToRadian(ToDegrees(lat_swap[0])));
                   Distance_exceeds100(Total_Distance);
                   
                   
                   sprintf(Distance,"%f",Total_Distance);
                   
                   for(uint8_t i=0;i<12;i++)
                   {
                     UART0_Send(longitude[i]);
                   }
                   UART0_Send(' ');
                   UART0_Send(' ');
                   UART0_Send(' ');
                   for(uint8_t i=0;i<12;i++)
                   {
                     UART0_Send(latitude[i]);
                   }
                   UART0_Send('*');
                   UART0_Send(' ');
                   
                   for(uint8_t i=0;i<12;i++)
                   {
                     UART0_Send(Distance[i]);
                   }
                   UART0_Send(' ');
                   UART0_Send(' ');
                   Print(Distance);
                   Systick_Wait1ms(10000);
                  }
              }
          }
       }
     }
    }
   }
  }
}