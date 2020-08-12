/*
 * ultrasonic_test.c
 *
 *  Created on: Aug 11, 2020
 *      Author: sharath
 */


#include <stdio.h>
#include <time.h>
#include "BBB_ADC_lib.h"
#include "GPIO_drivers.h"



int main(void) {

	 int echo_read=0;

	 int flag=0;

	 double result=0;

	 struct timespec start, stop;

	 memset(&start,'\0',sizeof(start));
	 memset(&stop,'\0',sizeof(stop));

	gpio_export(60);

	gpio_configure_dir(60,GPIO_DIR_OUT);

	gpio_export(66);

	gpio_configure_dir(66,GPIO_DIR_IN);



	while(1)
	{
		gpio_write_value(60,GPIO_LOW_VALUE);
		usleep(1);
		//Start trigger
		gpio_write_value(60,GPIO_HIGH_VALUE);
	//	gpio_write_value(60,GPIO_HIGH_VALUE);

		usleep(2000);
		gpio_write_value(60,GPIO_LOW_VALUE);

	//	gpio_write_value(60,GPIO_LOW_VALUE);

		echo_read=gpio_read_value(66);

		//usleep(10);

		if(echo_read == 1)
		{
			flag=1;
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
		}

		if(echo_read == 0 && flag== 1)
		{
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
			result=(stop.tv_sec-start.tv_sec)* 1e6 + (stop.tv_nsec-start.tv_nsec)/1e3;
			flag=0;
		}

		printf("result:%f\n",result);





	}
	return EXIT_SUCCESS;
}
