#ifndef LED_H_
#define LED_H_
#include "stdint.h"

void InitPortF(void);
void Output(uint32_t data);
void Distance_exceeds100(float distance);

#endif