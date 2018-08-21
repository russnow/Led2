#include "stm32l1xx.h"
#include "stm32l1xx_rcc.h"
#include "stm32l1xx_gpio.h"

#define GREENSTM_ON()		GPIO_SetBits(GPIOB, GPIO_Pin_7)
#define GREENSTM_OFF()	GPIO_ResetBits (GPIOB, GPIO_Pin_7)
#define BLUE_ON()				GPIO_SetBits(GPIOB, GPIO_Pin_6)
#define BLUE_OFF()			GPIO_ResetBits (GPIOB, GPIO_Pin_6)
#define HIGH_LED_ON()		GPIO_SetBits(GPIOB, GPIO_Pin_5)
#define HIGH_LED_OFF()	GPIO_ResetBits(GPIOB, GPIO_Pin_5)
#define LOW_LED_ON()		GPIO_SetBits(GPIOB, GPIO_Pin_4)
#define LOW_LED_OFF()		GPIO_ResetBits(GPIOB, GPIO_Pin_4)
#define DELAY						10

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
//Zadayem peremennuy functsiu
//------------------------------------------------------------------------------------------------	
void LEDs_ini(void)
{
	GPIO_InitTypeDef GPIO_Init_LED;
		
		RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE); //vkluchayet tactirovanie na portu B 
		
		
		
		GPIO_Init_LED.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
		GPIO_Init_LED.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_Init_LED.GPIO_Speed =  GPIO_Speed_2MHz;
		GPIO_Init_LED.GPIO_OType = GPIO_OType_PP;
		GPIO_Init_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOB , &GPIO_Init_LED);
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
