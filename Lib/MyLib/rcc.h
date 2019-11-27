#ifndef RCC_INIT_H
#define RCC_INIT_H
#include "stm32f4xx.h"
#include "clocks.h"
#include "log.h"

void RCC_init(void);
void Delay_C(uint32_t nTime);
void system_reset(void);

#endif



