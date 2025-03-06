/*
 * LED_driver.h
 *
 *  Created on: Oct 4, 2024
 *      Author: yahia raouf
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include "gpio.h"

//if LED is connected using positive logic then set to 1 , if it is connected using negative logic then set to 0
#define POSITIVE_LOGIC	1

#define LED_PORT		PORTB_ID

//enumeration to give each LED an ID
typedef enum {
	RED = 5, GREEN = 6, BLUE = 7
} LED_ID;

//This function is used to initialize a led buy setting its pin direction and set the PORT according to the LED connenction logic
void LED_init();

//This is used to turn on the led given its ID
void LED_on(LED_ID id);

//This is used to turn off the led given its ID
void LED_off(LED_ID id);

#endif /* LED_DRIVER_H_ */
