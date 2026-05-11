/*
 * main.c
 *
 *  Created on: Oct 2, 2025
 *      Author: Omar Mansour
 */
#include"gpio.h"
#include"buzzer.h"
#include"icu.h"
#include"led.h"
#include"lcd.h"
#include"ultra_sonic.h"
#include <util/delay.h>


/*********************************************************************************
 * 								DEFINITIONS 									 *
 ********************************************************************************/
#define BUZZER_portNum PORTC_ID
#define BUZZER_pinNum PIN5_ID

#define RED_LED_PORT    PORTC_ID
#define RED_LED_PIN     PIN0_ID

#define GREEN_LED_PORT  PORTC_ID
#define GREEN_LED_PIN   PIN1_ID

#define BLUE_LED_PORT   PORTC_ID
#define BLUE_LED_PIN    PIN2_ID



int main()
{
	/********************************************************************************
	 * 										INITIALIZATIONS 						*
	 ********************************************************************************/

	BUZZER_init( BUZZER_portNum,BUZZER_pinNum);
	LED_init(RED_LED_PORT, RED_LED_PIN);
	LED_init(BLUE_LED_PORT, BLUE_LED_PIN);
	LED_init(GREEN_LED_PORT, GREEN_LED_PIN);
	LCD_init();
	Ultrasonic_init();
	SREG|=(1<<7);

	uint16 distance;
	uint16 previous_distance = 0;
	LCD_displayStringRowColumn(0,0,"Distance=");

	while(1)
	{

		distance = Ultrasonic_readDistance();
		if(distance != previous_distance)
		{




			LCD_displayStringRowColumn(0,9,"   ");
			LCD_moveCursor(0,9);
			LCD_intgerToString(distance);
			LCD_displayStringRowColumn(0,12,"cm");
			previous_distance = distance;
		}


		/********************************************************************************
		 * 								display distance and warnings 					*						 										*
		 ********************************************************************************/
		if(distance<=5)
		{
			LCD_displayStringRowColumn(1,6,"STOP");

			LED_onPosLogic(RED_LED_PORT,RED_LED_PIN);
			LED_onPosLogic(BLUE_LED_PORT,BLUE_LED_PIN);
			LED_onPosLogic(GREEN_LED_PORT,GREEN_LED_PIN);

			BUZZER_on(BUZZER_portNum,BUZZER_pinNum);

			_delay_ms(250);

			LED_offPosLogic(RED_LED_PORT,RED_LED_PIN);
			LED_offPosLogic(BLUE_LED_PORT,BLUE_LED_PIN);
			LED_offPosLogic(GREEN_LED_PORT,GREEN_LED_PIN);

			_delay_ms(250);

		}
		else if(distance<=10)
		{
			LCD_displayStringRowColumn(1,6,"    ");
			LED_onPosLogic(RED_LED_PORT,RED_LED_PIN);
			LED_onPosLogic(BLUE_LED_PORT,BLUE_LED_PIN);
			LED_onPosLogic(GREEN_LED_PORT,GREEN_LED_PIN);

			BUZZER_off(BUZZER_portNum,BUZZER_pinNum);
		}

		else if(distance<=15)
		{
			LCD_displayStringRowColumn(1,6,"    ");
			LED_onPosLogic(RED_LED_PORT,RED_LED_PIN);
			LED_onPosLogic(GREEN_LED_PORT,GREEN_LED_PIN);
			LED_offPosLogic(BLUE_LED_PORT,BLUE_LED_PIN);

			BUZZER_off(BUZZER_portNum,BUZZER_pinNum);
		}

		else if(distance<=20)
		{
			LCD_displayStringRowColumn(1,6,"    ");
			LED_onPosLogic(RED_LED_PORT,RED_LED_PIN);
			LED_offPosLogic(GREEN_LED_PORT,GREEN_LED_PIN);
			LED_offPosLogic(BLUE_LED_PORT,BLUE_LED_PIN);

			BUZZER_off(BUZZER_portNum,BUZZER_pinNum);
		}

		else if(distance>20)
		{
			LCD_displayStringRowColumn(1,6,"    ");
			LED_offPosLogic(RED_LED_PORT,RED_LED_PIN);
			LED_offPosLogic(GREEN_LED_PORT,GREEN_LED_PIN);
			LED_offPosLogic(BLUE_LED_PORT,BLUE_LED_PIN);

			BUZZER_off(BUZZER_portNum,BUZZER_pinNum);
		}
	}
}










