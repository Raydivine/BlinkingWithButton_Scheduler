//#include "stm32f4xx_hal.h"
#include "main.h"
#include "stm32f4xx_hal_gpio.h"
#include "Time.h"
#include "Task.h"


void testFunc(void);
void waitForTaskSwitch(void);

int main(void)
{
	initSysTick();
	initTcb();
	waitForTaskSwitch();

    while(1)
    {

    }
}

void initSysTick()
{
	if(SysTick_Config(SystemCoreClock / 1000))
	{
		//Capture error
		while(1);
	}
}

int dummy(int value){
	return value*3;
}

