/*
 * GPIO_drivers.c
 *
 *  Created on: Aug 4, 2020
 *      Author: sharath
 */

#include "GPIO_drivers.h"


int gpio_export(uint32_t gpio_num)
{
	int fd, len;
	char buf[4];

	fd = open(SYS_GPIO_PATH "/export", O_WRONLY);
	if (fd < 0) {
		perror(" error opening export file\n");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", gpio_num);
	write(fd, buf, len);
	close(fd);

	return 0;
}

int gpio_configure_dir(uint32_t gpio_num, uint8_t dir_value)
{
    int fd;
    char buf[100];

    snprintf(buf, sizeof(buf), SYS_GPIO_PATH "/gpio%d/direction", gpio_num);

    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("gpio direction configure\n");
        return fd;
    }

    if (dir_value)
        write(fd, "out", 4); //3+1  +1 for NULL character
    else
        write(fd, "in", 3);

    close(fd);
    return 0;
}

int gpio_write_value(uint32_t gpio_num, uint8_t out_value)
{
    int fd;
    char buf[100];

    snprintf(buf, sizeof(buf), SYS_GPIO_PATH "/gpio%d/value", gpio_num);

    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("gpio write value\n");
        return fd;
    }

    if (out_value)
        write(fd, "1", 2);
    else
        write(fd, "0", 2);

    close(fd);
    return 0;
}

int gpio_read_value(uint32_t gpio_num)
{
    int fd;
    char buf[100];

    char read_value[1];

    memset(read_value,'\0', sizeof(read_value));

    snprintf(buf, sizeof(buf), SYS_GPIO_PATH "/gpio%d/value", gpio_num);

    fd = open(buf, O_RDONLY);
    if (fd < 0) {
        perror("gpio read value\n");
        return fd;
    }

    read(fd,read_value,sizeof(read_value));

    if (read_value[0]=='1')
    {
    	close(fd);
        return 1;
    }
    else if(read_value[0]=='0')
    {
    	close(fd);
    	return 0;
    }
    close(fd);
    return -1;
}
