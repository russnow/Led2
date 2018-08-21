#include "main.h"


uint16_t delay_count=0;
//------------------------------------------------------------------------------------------------
//Functsiu budet vyzyvat kazduy 1ms
//------------------------------------------------------------------------------------------------
void SysTick_Handler(void)
{
	if (delay_count > 0)
	{
		delay_count--;
	}
}
//------------------------------------------------------------------------------------------------
//gdem poka delay count ne stanet raven nulyu
//------------------------------------------------------------------------------------------------
void delay_ms(uint16_t delay_temp)
{
	delay_count = delay_temp;
	while(delay_count) //gdem poka delay count ne stanet raven nulyu
	{
		
	}
}

//------------------------------------------------------------------------------------------------
//Podklyutchaem peremennuy i initsializiruyem systemnyi timer //1ms
//------------------------------------------------------------------------------------------------
int main (void)
	{
		
		LEDs_ini();
		SysTick_Config(SystemCoreClock/1000); //initsializiruyem systemnyi timer //1ms	
		while(1)
			{
				GREENSTM_ON();
				HIGH_LED_OFF();
				delay_ms(DELAY);
				BLUE_ON();
				GREENSTM_OFF();
				delay_ms(DELAY);
				BLUE_OFF();
				LOW_LED_ON();
				delay_ms(DELAY);
				LOW_LED_OFF();
				HIGH_LED_ON();
				delay_ms(DELAY);
					
			}
	}
