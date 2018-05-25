/*
 * led.h
 *
 *  Created on: 25 mai 2018
 *      Author: INGECOM
 */

#ifndef LED_H_
#define LED_H_

/* Includes ------------------------------------------------------------------*/
#include "BlueNRG_x_device.h"
#include "BlueNRG1_sysCtrl.h"
#include "BlueNRG1_gpio.h"
#include "myDef.h"




/* Class ---------------------------------------------------------------------*/
class Led
{
public:
	static Led& getLed(Led_TypeDef oneLed)
	{
		Led *ledtmp;

		switch (oneLed)
		{
		case LED1:
			static Led instance1(oneLed);
			ledtmp = &instance1;
			break;

		case LED2:
			static Led instance2(oneLed);
			ledtmp = &instance2;
			break;

		case LED3:
			static Led instance3(oneLed);
			ledtmp = &instance3;
			break;

		default:
			break;
		}
		return *ledtmp;
	}

	void init(void);
	void toggleLed ( void );

private:
	/* Creation unique d'une instance LED */
	Led();
	Led(Led_TypeDef oneLed);
	~Led();

	Led_TypeDef pinLed;
};


#endif /* LED_H_ */
