/*
 * Flame_sensor_driver.h
 *
 *  Created on: Oct 6, 2024
 *      Author: yahia raouf
 */

#ifndef FLAME_SENSOR_DRIVER_H_
#define FLAME_SENSOR_DRIVER_H_

#include "gpio.h"

#define OUT_PIN		PIN2_ID
#define OUT_PORT	PORTD_ID

//Initializes the flame sensor pin direction.
void FlameSensor_init();

//Reads the value from the flame sensor and returns it.
uint8 FlameSensor_getValue();

#endif /* FLAME_SENSOR_DRIVER_H_ */
