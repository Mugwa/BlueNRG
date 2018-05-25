/*
 * factory.h
 *
 *  Created on: 25 mai 2018
 *      Author: INGECOM
 */

#ifndef FACTORY_H_
#define FACTORY_H_

/* Includes ------------------------------------------------------------------*/
#include "BlueNRG_x_device.h"
#include "BlueNRG1_sysCtrl.h"
#include "BlueNRG1_gpio.h"
#include "ledFactory.h"
#include "button.h"


/* Class ---------------------------------------------------------------------*/
class Factory
{
public:
	static Factory& getFactor()
	{
		static Factory instance;
		return instance;
	}


	void buildSystem();
	void checkButton(void);

	Button* getButton(ButNum_typedef);
	LedFactory* getLed(Led_TypeDef);

private:
	Factory();
	~Factory();
	Button *pBt1, *pBt2;
	LedFactory *pLed1, *pLed2;
	LedFactory *pLed3;
};


#endif /* FACTORY_H_ */
