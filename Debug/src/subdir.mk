################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GPIO_drivers.c \
../src/lightSensor_example.c 

OBJS += \
./src/GPIO_drivers.o \
./src/lightSensor_example.o 

C_DEPS += \
./src/GPIO_drivers.d \
./src/lightSensor_example.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I"/home/sharath/Eclipse_git/BBB_I2C_ADC_Libraries/BBB_I2C_ADC_lib" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


