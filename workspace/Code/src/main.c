#include "stm32l1xx.h"
#include "stm32l1xx_rcc.h"
#include "stm32l1xx_gpio.h"

int main (void)
{
	uint32_t i;
	RCC->AHBENR|=RCC_AHBENR_GPIOBEN; //Enable tactirovanie porta B
	RCC->AHBENR|=RCC_AHBENR_GPIOHEN;
	GPIOB->MODER=0x5500;//Ukazyvaem na PB6 & PB7 chto eto out
	//GPIOH->MODER=0x5;
	
	GPIOB->OTYPER=0; //podhvatyvaem piny
	//GPIOH->OTYPER=0;
	
	GPIOB->OSPEEDR=0;
	//GPIOH->OSPEEDR=0;
	
	while(1)
	{
		
		GPIOB->ODR=0xF0;
		for (i=0; i<200000; i++) {}
		GPIOB->ODR=0x0;
		for (i=0;i<200000; i++) {}
			
	}
}
