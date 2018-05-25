/*
 * ledFactory.cpp
 *
 *  Created on: 25 mai 2018
 *      Author: INGECOM
 */

#ifndef LEDFACTORY_CPP_
#define LEDFACTORY_CPP_

/* Includes ------------------------------------------------------------------*/
#include "ledFactory.h"

/* Const/destruct ------------------------------------------------------------*/
/*
 * @brief init the output led
 * @retval none
 */
LedFactory::LedFactory()
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
LedFactory::LedFactory(Led_TypeDef oneLed)
{
	pinLed = oneLed;
}

/*
 * @brief destroy the output led
 * @retval none
 */
LedFactory::~LedFactory()
{

}

/* Public function -----------------------------------------------------------*/
/*
 * @brief: Init :)
 */
void LedFactory::init ( void )
{
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
 * @brief: Tester le Singleton
 */
void LedFactory::toggleLed ( void )
{
	GPIO_ToggleBits(pinLed);
}




#endif /* LEDFACTORY_CPP_ */
