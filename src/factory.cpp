/*
 * factory.cpp
 *
 *  Created on: 25 mai 2018
 *      Author: INGECOM
 */

/* Includes ------------------------------------------------------------------*/
#include <stddef.h>
#include <stdlib.h>
#include "factory.h"
#include "ledFactory.h"
#include "button.h"
#include "led.h"

/* Const/destruct ------------------------------------------------------------*/
Factory::Factory()
{
	pBt1 = NULL;
	pBt2 = NULL;
	pLed3 = NULL;
}


Factory::~Factory()
{
	delete pBt1;
	delete pBt2;

	delete pLed3;
}


/* Public function -----------------------------------------------------------*/
void Factory::buildSystem()
{
	/* init the pointers */
	//getButton(Bt1)->init();
	//getLed(LED3)->init();
	Led::getLed(LED3);

	/* Make the relations */
}


void Factory::checkButton(void)
{

	if (getButton(Bt1)->checkState() == Pressed) {
		getLed(LED3)->toggleLed();
	}
}

Button* Factory::getButton(ButNum_typedef bttmp)
{
	Button *btptr;

	if (bttmp == Bt1) {
		if (pBt1 != NULL) {
			pBt1 = new Button(bttmp);
		}
		btptr = pBt1;
	}

	else if  (bttmp == Bt2) {
		if (pBt2 != NULL) {
			pBt2 = new Button(bttmp);
		}
		btptr = pBt2;
	}

	return btptr;
}



LedFactory* Factory::getLed(Led_TypeDef ledselect)
{
	LedFactory *ledtmp;

	if (ledselect == LED1) {
		if (pLed1 != NULL) {
			pLed1 = new LedFactory(ledselect);
		}
		ledtmp = pLed1;
	}

	else if  (ledselect == LED2) {
		if (pLed2 != NULL) {
			pLed2 = new LedFactory(ledselect);
		}
		ledtmp = pLed2;
	}

	else if  (ledselect == LED3) {
		if (pLed3 != NULL) {
			pLed3 = new LedFactory(ledselect);
		}
		ledtmp = pLed3;
	}

	return ledtmp;
}


