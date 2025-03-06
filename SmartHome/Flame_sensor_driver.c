/*
 * Flame_sensor_driver.c
 *
 *  Created on: Oct 6, 2024
 *      Author: yahia raouf
 */

#include "Flame_sensor_driver.h"

void FlameSensor_init() {
	///set the direction of the flame sensor pin
	GPIO_setupPinDirection(OUT_PORT, OUT_PIN, PIN_INPUT);
}

uint8 FlameSensor_getValue() {

	uint8 fire = 0;

	//read the value of the pin and return a logical 1 or logical 0
	if (GPIO_readPin(OUT_PORT, OUT_PIN)) {
		fire = 1;
	}

	else
		fire = 0;
	return fire;
}
