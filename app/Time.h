#ifndef Time_H
#define Time_H

#include <stdint.h>

#if !defined(TEST)
  #include "stm32f4xx_hal.h"
#endif

#define ONE_SEC					    1000
#define ONE_HUND_TWENTY_MILISEC		120
#define ONE_HUND_MILISEC		    100
#define TWO_HUND_MILISEC		    200
#define FIVE_HUND_MILISEC		    500

uint32_t updateTime();
uint32_t getCurrentTime();
void delay(uint32_t delayCycle);
uint32_t isTimerExpire(uint32_t delayCycle, uint32_t *previousTime);

#endif // Time_H
