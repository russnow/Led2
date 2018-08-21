#ifndef MAIN_H
#define MAIN_H

#include "mcu_ini.h"





#define GREENSTM_ON()		GPIO_SetBits(GPIOB, GPIO_Pin_7)
#define GREENSTM_OFF()	GPIO_ResetBits (GPIOB, GPIO_Pin_7)
#define BLUE_ON()				GPIO_SetBits(GPIOB, GPIO_Pin_6)
#define BLUE_OFF()			GPIO_ResetBits (GPIOB, GPIO_Pin_6)
#define HIGH_LED_ON()		GPIO_SetBits(GPIOB, GPIO_Pin_5)
#define HIGH_LED_OFF()	GPIO_ResetBits(GPIOB, GPIO_Pin_5)
#define LOW_LED_ON()		GPIO_SetBits(GPIOB, GPIO_Pin_4)
#define LOW_LED_OFF()		GPIO_ResetBits(GPIOB, GPIO_Pin_4)
#define DELAY						10 

#endif

