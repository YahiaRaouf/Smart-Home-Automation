/*
 * LDR_sensor_driver.c
 *
 *  Created on: Oct 4, 2024
 *      Author: yahia raouf
 */

#include "util/delay.h"
#include "LDR_sensor_driver.h"

uint16 LDR_getLightIntensity() {
	//initialize the ADC
	ADC_init();

	//value of light intensity
	uint16 lightIntensity = 0;

	//this delay is added to give time for the ADC to get ready
	_delay_ms(7);

	//this equation is responsible to calculate the precentage of light intensity sensed by the LDR
	lightIntensity = (uint16) (((uint32) ADC_readChannel(LDR_SENSOR_CHANNEL_ID)
			* LDR_SENSOR_MAX_LIGHT_INTENSITY * ADC_REF_VOLT_VALUE)
			/ (ADC_MAXIMUM_VALUE * LDR_SENSOR_MAX_VOLT_VALUE));

	return lightIntensity;
}

