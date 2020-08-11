################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BBB_I2C_ADC_lib/BBB_ADC_lib.c 

OBJS += \
./BBB_I2C_ADC_lib/BBB_ADC_lib.o 

C_DEPS += \
./BBB_I2C_ADC_lib/BBB_ADC_lib.d 


# Each subdirectory must supply rules for building sources it contributes
BBB_I2C_ADC_lib/%.o: ../BBB_I2C_ADC_lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -I"/home/sharath/Eclipse_git/BBB_I2C_ADC_Libraries/BBB_I2C_ADC_lib" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


