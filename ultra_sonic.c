/*
 * ultra_sonic.c
 *
 *  Created on: Oct 2, 2025
 *      Author: Omar Mansour
 */

#include"ultra_sonic.h"


volatile uint16 echo_high_time ;
volatile uint8 edge_count =0;


void Ultrasonic_init(void)
{
	GPIO_setupPinDirection(ULTRASONIC_SENSOR_TRIGGER_PORT,ULTRASONIC_SENSOR_TRIGGER_PIN,PIN_OUTPUT);
	ICU_ConfigType a_Icu_Config;
	a_Icu_Config.clock = F_CPU_8;
	a_Icu_Config.edge = RISING_EDGE;
	ICU_init(&a_Icu_Config);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(ULTRASONIC_SENSOR_TRIGGER_PORT,ULTRASONIC_SENSOR_TRIGGER_PIN,LOGIC_HIGH);


	_delay_us(10); /////////////////////////////////////////////////////////////////////////////////

	GPIO_writePin(ULTRASONIC_SENSOR_TRIGGER_PORT,ULTRASONIC_SENSOR_TRIGGER_PIN,LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();
	 uint8 error_timer=0;

	while(edge_count<2 && error_timer<60 )
	{

		_delay_ms(1);
		error_timer++;
	}


	if(error_timer==60) // will only occur if sth bad happens,reset everything a
	{
		edge_count=0;
		error_timer =0;
		echo_high_time=0;
		return 0;
	}
	edge_count=0;
	error_timer =0;
	return (uint16)((echo_high_time)/117.6 +1) ;

}


void Ultrasonic_edgeProcessing(void)
{

	edge_count++;

	if(edge_count==1)
	{


		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING_EDGE);


	}
	else if(edge_count==2)
	{


		echo_high_time = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(RISING_EDGE);

	}


}




