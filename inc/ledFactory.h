/*
 * ledFactory.h
 *
 *  Created on: 25 mai 2018
 *      Author: INGECOM
 */

#ifndef LEDFACTORY_H_
#define LEDFACTORY_H_


/* Includes ------------------------------------------------------------------*/
#include "BlueNRG_x_device.h"
#include "BlueNRG1_sysCtrl.h"
#include "BlueNRG1_gpio.h"
#include "myDef.h"




/* Class ---------------------------------------------------------------------*/
class LedFactory
{
public:
	/* Creation unique d'une instance LED */
	LedFactory();
	LedFactory(Led_TypeDef oneLed);
	~LedFactory();

	void init(void);
	void toggleLed ( void );

private:
	Led_TypeDef pinLed;
};



#endif /* LEDFACTORY_H_ */
