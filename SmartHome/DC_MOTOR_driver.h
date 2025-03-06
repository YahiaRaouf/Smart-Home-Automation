/*
 * DC_MOTOR_driver.h
 *
 *  Created on: Oct 6, 2024
 *      Author: yahia raouf
 */

#ifndef DC_MOTOR_DRIVER_H_
#define DC_MOTOR_DRIVER_H_

#include "gpio.h"

//configuring the pins of IN1 , IN2 and ENABLE
#define IN1_PIN		PIN0_ID
#define IN2_PIN		PIN1_ID
#define EN_PIN		PIN3_ID

//configuring ports of IN1 , IN2 and ENABLE
#define IN1_PORT	PORTB_ID
#define IN2_PORT	PORTB_ID
#define EN_PORT		PORTB_ID

//creating an enum for the sates of the motor
typedef enum{
	Stop,CLockWise,AntiClockwise
}DcMotor_State;

//Initializes the DC motor by setting the direction for the motor pins and stopping the motor at the beginning.
void DC_MOTOR_init();

//Controls the motor's state (Clockwise/Anti-Clockwise/Stop) and adjusts the speed based on the input duty cycle.
void DC_MOTOR_Rotate(DcMotor_State state , uint8 speed);

#endif /* DC_MOTOR_DRIVER_H_ */
