/*
 * ultra_sonic.h
 *
 *  Created on: Oct 2, 2025
 *      Author: Omar Mansour
 */

#ifndef ULTRA_SONIC_H_
#define ULTRA_SONIC_H_
#include"std_types.h"
#include"gpio.h"
#include"icu.h"
#include <util/delay.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ULTRASONIC_SENSOR_ECHO_PORT PORTD_ID
#define ULTRASONIC_SENSOR_ECHO_PIN PIN6_ID

#define ULTRASONIC_SENSOR_TRIGGER_PORT PORTD_ID
#define ULTRASONIC_SENSOR_TRIGGER_PIN PIN7_ID

/*******************************************************************************
 *                                FUNCTION PROTOTYOES                          *
 *******************************************************************************/


void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);


#endif /* ULTRA_SONIC_H_ */
