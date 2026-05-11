/*
 * buzzer.h
 *
 *  Created on: Sep 29, 2025
 *      Author: agh
 */

#ifndef BUZZER_H_
#define BUZZER_H_
# include "gpio.h"

void BUZZER_init(uint8 BUZZER_portNum, uint8 BUZZER_pinNum);
void BUZZER_on(uint8 BUZZER_portNum, uint8 BUZZER_pinNum);
void BUZZER_off(uint8 BUZZER_portNum, uint8 BUZZER_pinNum);

#endif /* BUZZER_H_ */
