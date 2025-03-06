/*
 * LED_driver.c
 *
 *  Created on: Oct 4, 2024
 *      Author: yahia raouf
 */

#include "LED_driver.h"
#include "gpio.h"

void LED_init() {
	//set the direction of each pin
	GPIO_setupPinDirection(LED_PORT, GREEN, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT, BLUE, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT, RED, PIN_OUTPUT);

	//check if the LEDs are connected using positive logic
	#if(POSITIVE_LOGIC)
		GPIO_writePin(LED_PORT, GREEN , LOGIC_LOW);
		GPIO_writePin(LED_PORT, BLUE , LOGIC_LOW);
		GPIO_writePin(LED_PORT, RED, LOGIC_LOW);
	#else
		GPIO_writePin(LED_PORT, GREEN, LOGIC_HIGH);
		GPIO_writePin(LED_PORT, BLUE, LOGIC_HIGH);
		GPIO_writePin(LED_PORT, RED, LOGIC_HIGH);
	#endif
}

//This function turns on the LED
void LED_on(LED_ID id) {
	GPIO_writePin(LED_PORT , id , POSITIVE_LOGIC);
}

//this function turns of the LED
void LED_off(LED_ID id){
	GPIO_writePin(LED_PORT , id , ~(POSITIVE_LOGIC));
}
