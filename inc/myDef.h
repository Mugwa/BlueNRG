/*
 * myDef.h
 *
 *  Created on: 25 mai 2018
 *      Author: INGECOM
 */

#ifndef MYDEF_H_
#define MYDEF_H_

/* Led -----------------------------------------------------------------------*/
typedef enum
{
	LED1 = GPIO_Pin_6,
	LED2 = GPIO_Pin_7,
	LED3 = GPIO_Pin_14
} Led_TypeDef;

typedef enum
{
	ON,
	OFF
} Led_StateDef;


/* Button --------------------------------------------------------------------*/
typedef enum
{
	Bt1 = GPIO_Pin_13,
	Bt2 = GPIO_Pin_5
}ButNum_typedef ;

typedef enum
{
  Released = 0,
  Pressed,
} ButState_typedef;



#endif /* MYDEF_H_ */
