/*
 * led.c
 *
 *  Created on: Sep 28, 2025
 *      Author: Omar Mansour
 */
#include "led.h"

void LED_init(uint8 LED_portNum, uint8 LED_pinNum)
{
	GPIO_setupPinDirection( LED_portNum,  LED_pinNum, PIN_OUTPUT);
}

void LED_onPosLogic(uint8 LED_portNum, uint8 LED_pinNum)
{
	GPIO_writePin(LED_portNum, LED_pinNum, LOGIC_HIGH);
}

void LED_offPosLogic(uint8 LED_portNum, uint8 LED_pinNum)
{
	GPIO_writePin(LED_portNum, LED_pinNum, LOGIC_LOW);
}

void LED_onNegLogic(uint8 LED_portNum, uint8 LED_pinNum)
{
	GPIO_writePin(LED_portNum, LED_pinNum,LOGIC_LOW );
}

void LED_offNegLogic(uint8 LED_portNum, uint8 LED_pinNum)
{
	GPIO_writePin(LED_portNum, LED_pinNum, LOGIC_HIGH);
}








