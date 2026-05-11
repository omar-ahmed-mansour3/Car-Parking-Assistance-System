/*
 * led.h
 *
 *  Created on: Sep 28, 2025
 *      Author: Omar Mansour
 */

#ifndef LED_H_
#define LED_H_
# include "gpio.h"

/***************************************************************
 * 							Functions Prototypes
 ***************************************************************/

void LED_init(uint8 LED_portNum, uint8 LED_pinNum);
void LED_onPosLogic(uint8 LED_portNum, uint8 LED_pinNum);
void LED_offPosLogic(uint8 LED_portNum, uint8 LED_pinNum);
void LED_onNegLogic(uint8 LED_portNum, uint8 LED_pinNum);
void LED_offNegLogic(uint8 LED_portNum, uint8 LED_pinNum);

#endif /* LED_H_ */
