/*
 * lm35_sensor.c
 *
 *  Created on: Oct 6, 2024
 *      Author: yahia raouf
 */

#include <util/delay.h> /* For the delay functions */
#include "lm35_sensor.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void) {
	ADC_init();

	uint8 temp_value = 0;

	/* Make delay for some time until g_adcResult value is updated with the ADC interrupt */
	_delay_ms(7);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8) (((uint32) ADC_readChannel(SENSOR_CHANNEL_ID)
			* SENSOR_MAX_TEMPERATURE * ADC_REF_VOLT_VALUE)
			/ (ADC_MAXIMUM_VALUE * SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

