/*
 * buzzer.c
 *
 *  Created on: Sep 29, 2025
 *      Author: Omar Mansour
 */

#include"buzzer.h"
void BUZZER_init(uint8 BUZZER_portNum, uint8 BUZZER_pinNum)
{
	GPIO_setupPinDirection( BUZZER_portNum,  BUZZER_pinNum, PIN_OUTPUT);
}
void BUZZER_on(uint8 BUZZER_portNum, uint8 BUZZER_pinNum)
{
	GPIO_writePin(BUZZER_portNum, BUZZER_pinNum, LOGIC_HIGH);
}
void BUZZER_off(uint8 BUZZER_portNum, uint8 BUZZER_pinNum)
{
	GPIO_writePin(BUZZER_portNum, BUZZER_pinNum, LOGIC_LOW);
}

