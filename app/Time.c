#include "Time.h"

uint32_t counter = 0;
uint32_t currentTime = 0;

uint32_t updateTime()
{
	if(counter++ >= 100)
	{
		counter = 0;
		currentTime++;
	}

	return currentTime;
}

uint32_t getCurrentTime()
{
	return HAL_GetTick();
}

void delay(uint32_t delayCycle)
{
	static uint32_t previousTime = 0;

	while((currentTime - previousTime) < delayCycle);
	previousTime = currentTime;
}

uint32_t isTimerExpire(uint32_t delayCycle, uint32_t *previousTime)
{
	//if((currentTime - *previousTime) < delayCycle)
	if((getCurrentTime() - *previousTime) < delayCycle)
		return 0;
	else
	{
		//*previousTime = currentTime;
		*previousTime = getCurrentTime();
		return 1;
	}
}
