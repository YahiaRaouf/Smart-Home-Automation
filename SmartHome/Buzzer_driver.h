/*
 * Buzzer_driver.h
 *
 *  Created on: Oct 6, 2024
 *      Author: yahia raouf
 */

#ifndef BUZZER_DRIVER_H_
#define BUZZER_DRIVER_H_

#include "gpio.h"

#define BUZZER_PIN		PIN3_ID
#define BUZZER_PORT		PORTD_ID

//Initializes the buzzer pin direction and turn off the buzzer.
void BUZZER_init();

//Activates the buzzer.
void BUZZER_On();

//Deactivates the buzzer.
void BUZZER_Off();

#endif /* BUZZER_DRIVER_H_ */
