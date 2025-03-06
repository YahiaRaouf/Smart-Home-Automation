/*
 * main.c
 *
 *  Created on: Oct 4, 2024
 *      Author: yahia raouf
 */

/*****************************************************************************************************************************
 * 														#includes
 ******************************************************************************************************************************/
#include "avr/io.h"
#include "util/delay.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "LDR_sensor_driver.h"
#include "DC_MOTOR_driver.h"
#include "Flame_sensor_driver.h"
#include "Buzzer_driver.h"
#include "LED_driver.h"

/*****************************************************************************************************************************
 * 														Main Function
 ******************************************************************************************************************************/

int main() {

	//declaring variables and flags and initializing them
	uint16 lightIntensity = 0;
	uint16 roomTemp = 0;
	uint8 fanFLag = 0;

	//Set the global interrupt enable
	SREG |= (1 << 7);

	//Set the pin direction of the LM35 and LDR sensors as inputs
	GPIO_setupPinDirection(LM35_PORT, LM35_PIN, PIN_INPUT);
	GPIO_setupPinDirection(LDR_PORT, LDR_PIN, PIN_INPUT);

	//initialize the drivers
	LED_init();
	LCD_init();
	DC_MOTOR_init();
	FlameSensor_init();
	BUZZER_init();

	while (1) {

		//check if there is Flame
		if (FlameSensor_getValue()) {
			LCD_moveCursor(0, 0);
			LCD_displayString("Critical Alert!");
			LCD_moveCursor(1, 0);
			LCD_displayString("                ");
			BUZZER_On();

		} else {
			BUZZER_Off();

			//Start to show data on LCD
			if (fanFLag == 0) {
				LCD_displayString("FAN is OFF     ");
			} else
				LCD_displayString("Fan is ON      ");

			LCD_moveCursor(1, 0);
			LCD_displayString("T=");
			LCD_intgerToString(LM35_getTemperature());
			LCD_displayCharacter('C');
			LCD_moveCursor(1, 8);
			LCD_displayString("LDR:");
			LCD_intgerToString(LDR_getLightIntensity());
			LCD_displayString("%  ");
			LCD_moveCursor(0, 0);
		}

		/*	Based on the LDR readings, the system controls three LEDs according to light intensity thresholds:
			o Intensity < 15%: All 3 LEDs (Red, Green, and Blue) turn ON.
			o Intensity 16–50%: Red and Green LEDs turn ON.
			o Intensity 51–70%: Only the Red LED turns ON.
			o Intensity > 70%: All LEDs are turned OFF.
		*/

		lightIntensity = LDR_getLightIntensity();

		if (lightIntensity <= 15) {
			LED_on(GREEN);
			LED_on(BLUE);
			LED_on(RED);
		}

		else if (lightIntensity > 15 && lightIntensity <= 50) {
			LED_on(GREEN);
			LED_off(BLUE);
			LED_on(RED);
		}

		else if (lightIntensity > 50 && lightIntensity <= 70) {
			LED_off(GREEN);
			LED_off(BLUE);
			LED_on(RED);
		}

		else if (lightIntensity > 70) {
			LED_off(GREEN);
			LED_off(BLUE);
			LED_off(RED);
		}


		/*
		 	Fan speed is automatically adjusted based on room temperature, controlled by a PWM signal.
		 	The fan operates at different speeds based on temperature ranges:
			o Temperature ≥ 40°C: Fan ON at 100% speed.
			o Temperature ≥ 35°C and < 40°C: Fan ON at 75% speed.
			oTemperature ≥ 30°C and < 35°C: Fan ON at 50% speed.
			o Temperature ≥ 25°C and < 30°C: Fan ON at 25% speed.
			o Temperature < 25°C: Fan OFF.
			o Fire Detection and Alert: The system raises
		 */

		roomTemp = LM35_getTemperature();

		if (roomTemp < 25) {
			DC_MOTOR_Rotate(Stop, 0);
			fanFLag = 0;
		}

		else if (roomTemp >= 25 && roomTemp < 30) {
			DC_MOTOR_Rotate(AntiClockwise, 25);
			fanFLag = 1;
		}

		else if (roomTemp >= 30 && roomTemp < 35) {
			DC_MOTOR_Rotate(AntiClockwise, 50);

			fanFLag = 1;
		}

		else if (roomTemp >= 35 && roomTemp < 40) {
			DC_MOTOR_Rotate(AntiClockwise, 75);
			fanFLag = 1;
		}

		else {
			DC_MOTOR_Rotate(AntiClockwise, 100);
			fanFLag = 1;
		}
	}
}
