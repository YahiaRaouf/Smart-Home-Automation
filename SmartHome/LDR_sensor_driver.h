/*
 * LDR_sensor_driver.h
 *
 *  Created on: Oct 4, 2024
 *      Author: yahia raouf
 */

#ifndef LDR_SENSOR_DRIVER_H_
#define LDR_SENSOR_DRIVER_H_

#include "gpio.h"
#include "adc.h"

//This represents which ADC channel is the LDR sensor read through
#define LDR_SENSOR_CHANNEL_ID				0

/*This represents the maximum voltage output of the LDR sensor when exposed to the lowest possible light intensity (darkness).
In a voltage divider circuit, the LDR's resistance decreases with increasing light, resulting in maximum voltage in darkness.
 This value may vary based on the circuit configuration.*/
#define LDR_SENSOR_MAX_VOLT_VALUE			2.56

//This represents the maximum light intensity the sensor can measure (0% → 100%).
#define LDR_SENSOR_MAX_LIGHT_INTENSITY		100

#define LDR_PIN		PIN0_ID
#define LDR_PORT	PORTA_ID

//Reads the LDR sensor value and returns the light intensity.
uint16 LDR_getLightIntensity();

#endif /* LDR_SENSOR_DRIVER_H_ */
