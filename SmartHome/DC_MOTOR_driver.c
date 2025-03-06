/*
 * DC_MOTOR_driver.c
 *
 *  Created on: Oct 6, 2024
 *      Author: yahia raouf
 */

#include "DC_MOTOR_driver.h"
#include "PWM.h"

//this function initializes the DC motor
void DC_MOTOR_init() {
	//setting the direction of the Motor Pins
	GPIO_setupPinDirection(IN1_PORT, IN1_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(IN2_PORT, IN2_PIN, PIN_OUTPUT);

	//initiating the PINs with Logic zero (Stop state)
	GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_LOW);
	GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_LOW);
}

//this function sets the state (stop ,clockwise , anticlockwise) and speed (0% -> 100%);
void DC_MOTOR_Rotate(DcMotor_State state, uint8 speed) {
	uint8 duty_cycle = 0;

	//calculate the duty cycle of the PWM signal actuating the motor
	duty_cycle = (speed * 255) / 100;

	//the switch case is dependent on the state sent by the function
	switch (state) {

	case Stop:
		GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_LOW);
		GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_LOW);
		PWM_Timer0_Start(duty_cycle);
		break;

	case CLockWise:
		GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_HIGH);
		GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_LOW);
		PWM_Timer0_Start(duty_cycle);
		break;

	case AntiClockwise:
		GPIO_writePin(IN1_PORT, IN1_PIN, LOGIC_LOW);
		GPIO_writePin(IN2_PORT, IN2_PIN, LOGIC_HIGH);
		PWM_Timer0_Start(duty_cycle);
		break;
	}
}
