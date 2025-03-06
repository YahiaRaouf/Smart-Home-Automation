/*
 * Buzzer_driver.c
 *
 *  Created on: Oct 6, 2024
 *      Author: yahia raouf
 */


#include "Buzzer_driver.h"


void BUZZER_init(void){
	//set the direction of the Buzzer pin and initialize it to off
	GPIO_setupPinDirection(BUZZER_PORT , BUZZER_PIN , PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT , BUZZER_PIN , LOGIC_LOW);
}

//turn buzzer on
void BUZZER_On(){
	GPIO_writePin(BUZZER_PORT , BUZZER_PIN , LOGIC_HIGH);
}

//turn buzzer off
void BUZZER_Off(){
	GPIO_writePin(BUZZER_PORT , BUZZER_PIN , LOGIC_LOW);
}
