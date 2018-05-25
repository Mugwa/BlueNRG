/*
 * button.h
 *
 *  Created on: 25 mai 2018
 *      Author: INGECOM
 */

#ifndef BUTTON_H_
#define BUTTON_H_

/* Includes ------------------------------------------------------------------*/
#include "BlueNRG_x_device.h"
#include "BlueNRG1_sysCtrl.h"
#include "BlueNRG1_gpio.h"
#include "ledFactory.h"
#include "myDef.h"

/* Defines -------------------------------------------------------------------*/


/* Class ---------------------------------------------------------------------*/
class Button
{
public:
	Button();
	Button(ButNum_typedef);
	~Button();

	void init();
	void initRelation(Led_TypeDef, LedFactory*);

	ButState_typedef checkState();

private:
	ButNum_typedef pinBt;
	LedFactory *pLed1, *pLed2, *pLed3;
};



#endif /* BUTTON_H_ */
