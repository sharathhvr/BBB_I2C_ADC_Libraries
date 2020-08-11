/*
 * BBB_ADC_lib.h
 *
 *  Created on: Aug 10, 2020
 *      Author: sharath
 */

#ifndef BBB_ADC_LIB_H_
#define BBB_ADC_LIB_H_

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define ADC_FILE_PATH "/sys/bus/iio/devices/iio:device0/"

typedef enum ADCPins{AIN0,AIN1,AIN2,AIN3,AIN4,AIN5,AIN6}ADC_Pins;

unsigned int readAnalog_pin(ADC_Pins AINx);

#endif /* BBB_ADC_LIB_H_ */
