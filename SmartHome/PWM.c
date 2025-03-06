/*
 * PWM.c
 *
 *  Created on: Oct 4, 2024
 *      Author: yahia raouf
 */

#include "avr/io.h"
#include "PWM.h"

void PWM_Timer0_Start(uint8 duty_cycle){
	/*
	  1.setting the timer mode to Fast PWm
	  2.Setting the prescalar to 1024
	  3.Set Operation mode to Non-Inverting
	 */
	TCCR0 |= (1<<WGM00) | (1<<WGM01) | (1<<CS00) | (1<<CS02) | (1<<COM01);

	/*setting the Output compare register value to the duty cycle*/
	OCR0 = duty_cycle;
	GPIO_setupPinDirection(PORTB_ID , PIN3_ID , PIN_OUTPUT);
}
