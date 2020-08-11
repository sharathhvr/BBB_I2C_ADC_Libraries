/*
 ============================================================================
 Name        : BBB_ADC_Library.c
 Author      : Sharath
 Version     :
 Copyright   : Tested on Debian 10 (4.19.94-ti-r42)
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "BBB_ADC_lib.h"
#include "GPIO_drivers.h"



int main(void) {

	unsigned int analog_data=0;

	gpio_export(60);

	gpio_configure_dir(60,GPIO_DIR_OUT);



	while(1)
	{
		analog_data=readAnalog_pin(AIN6);

		//Testing Light sensor

		if(analog_data > 3000)
		{
			//activate buzzer
			gpio_write_value(60,GPIO_HIGH_VALUE);
		}
		else
		{
			//deactivate buzzer
			gpio_write_value(60,GPIO_LOW_VALUE);
		}

	//	usleep(2);


	}
	return EXIT_SUCCESS;
}
