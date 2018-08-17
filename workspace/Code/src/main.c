#include "stm32l1xx.h"
#include "stm32l1xx_rcc.h"
#include "stm32l1xx_gpio.h"

int main (void)
{
	RCC->AHBENR|=RCC_AHBENR_GPIOBEN; //Enable tactirovanie porta B
	
	GPIOB->MODER=0x5000;//Ukazyvaem na PB6 & PB7 chto eto out
	
	GPIOB->OTYPER=0; //podtyafivaem pins
	
	GPIOB->OSPEEDR=0;
	
	
	while(1)
	{
		GPIOB->ODR=0xC0;
	}
}
