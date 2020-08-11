/*
 * BBB_ADC_lib.c
 *
 *  Created on: Aug 10, 2020
 *      Author: sharath
 */


#include "BBB_ADC_lib.h"


unsigned int readAnalog_pin(ADC_Pins AINx)
{
	char read_buf[6];
	int analog_data=0;
	char buf[100];
	memset(&buf, '\0', sizeof(buf));
	sprintf(buf,ADC_FILE_PATH"in_voltage%d_raw",(int)AINx);
	int fd=open(buf,O_RDONLY);
	if(fd < 0)
	{
		perror("Error opening file:");
	}
	int analog_read=read(fd,read_buf,sizeof(read_buf));
	if(analog_read < 0)
	{
		perror("Error reading file:");
	}

	close(fd);
	analog_data = atoi(read_buf);
	return analog_data;
}
