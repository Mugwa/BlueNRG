/*
 * led.cpp
 *
 *  Created on: 25 mai 2018
 *      Author: INGECOM
 */

/* Includes ------------------------------------------------------------------*/
#include "led.h"

/* Const/destruct ------------------------------------------------------------*/
/*
 * @brief init the output led
 * @retval none
 */
Led::Led()
{
}

/*
 * @brief init the output led
 * @param led: led to be configured
 * 			@arg  LED1
 * 			@arg  LED2
 * 			@arg  LED3
 * @retval none
 */
Led::Led(Led_TypeDef oneLed)
{
	pinLed = oneLed;

	GPIO_InitType  GPIO_InitStruct;

	/* Enable the GPIO Clock */
	SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_GPIO, ENABLE);

	/* Configure the LED pin */
	GPIO_InitStruct.GPIO_Pin = pinLed;
	GPIO_InitStruct.GPIO_Mode = GPIO_Output;
	GPIO_InitStruct.GPIO_Pull = ENABLE;
	GPIO_InitStruct.GPIO_HighPwr = ENABLE;

	GPIO_Init(&GPIO_InitStruct);
}

/*
 * @brief destroy the output led
 * @retval none
 */
Led::~Led()
{

}

/* Public function -----------------------------------------------------------*/
/*
 * @brief: Tester le Singleton
 */
void Led::toggleLed ( void )
{
	GPIO_ToggleBits(pinLed);
}

