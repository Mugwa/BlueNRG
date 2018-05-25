/*
 * button.cpp
 *
 *  Created on: 25 mai 2018
 *      Author: INGECOM
 */

/* Includes ------------------------------------------------------------------*/
#include <stddef.h>
#include "button.h"

/* Const/destruct ------------------------------------------------------------*/
/*
 * @brief: init the button
 */
Button::Button()
{
	pLed1 = NULL;
	pLed2 = NULL;
	pLed3 = NULL;
}

/*
 * @brief: init the button
 */
Button::Button(ButNum_typedef selectBt)
{
	pinBt = selectBt;
	pLed1 = NULL;
	pLed2 = NULL;
	pLed3 = NULL;
}


/*
 * @brief: destroy the button
 */
Button::~Button()
{

}


/* Public function -----------------------------------------------------------*/
/*
 * @brief
 */
void Button::init()
{
	GPIO_InitType  GPIO_InitStruct;

	/* Enable the GPIO Clock */
	SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_GPIO, ENABLE);

	/* Configure the LED pin */
	GPIO_InitStruct.GPIO_Pin = pinBt;
	GPIO_InitStruct.GPIO_Mode = GPIO_Input;
	GPIO_InitStruct.GPIO_Pull = ENABLE;
	GPIO_InitStruct.GPIO_HighPwr = ENABLE;

	GPIO_Init(&GPIO_InitStruct);
}

/*
 * @brief
 */
void Button::initRelation(Led_TypeDef oneLed, LedFactory* ptr)
{
	switch (oneLed)
	{
	case LED1:
		pLed1 = ptr;
		break;

	case LED2:
		pLed2 = ptr;
		break;

	case LED3:
		pLed3 = ptr;
		break;

	default:
		break;
	}
}

/*
 * @brief
 */
ButState_typedef Button::checkState()
{
	ButState_typedef retval = Released;

	/* Check the button's state */
	if (GPIO_ReadBit(pinBt) == Bit_RESET) {
		retval = Pressed;
	}

	return retval;
}

