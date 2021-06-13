#ifndef SYSTICK_H_
#define SYSTICK_H_

void Init_Systick(void);
void Systick_Wait(uint32_t delay);
void Systick_Wait1ms(uint32_t delay);

#endif // !SYSTICK_H_
