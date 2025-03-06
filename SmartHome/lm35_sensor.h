/*
 * lm35_sensor.h
 *
 *  Created on: Oct 6, 2024
 *      Author: yahia raouf
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "gpio.h"
#include "adc.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         1
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

#define LM35_PIN	PIN1_ID
#define LM35_PORT	PORTA_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
