################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Buzzer_driver.c \
../DC_MOTOR_driver.c \
../Flame_sensor_driver.c \
../LDR_sensor_driver.c \
../LED_driver.c \
../PWM.c \
../adc.c \
../gpio.c \
../lcd.c \
../lm35_sensor.c \
../main.c 

OBJS += \
./Buzzer_driver.o \
./DC_MOTOR_driver.o \
./Flame_sensor_driver.o \
./LDR_sensor_driver.o \
./LED_driver.o \
./PWM.o \
./adc.o \
./gpio.o \
./lcd.o \
./lm35_sensor.o \
./main.o 

C_DEPS += \
./Buzzer_driver.d \
./DC_MOTOR_driver.d \
./Flame_sensor_driver.d \
./LDR_sensor_driver.d \
./LED_driver.d \
./PWM.d \
./adc.d \
./gpio.d \
./lcd.d \
./lm35_sensor.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


