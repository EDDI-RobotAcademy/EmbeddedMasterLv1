#include <stdio.h>
#include "device.h"
#include "main.h"

void proc_bldc (void *rf_r_handler_ch1)
{
    printf("bldc in\n");
}

void proc_servo (void *rf_r_handler_ch2)
{
    printf("servo in\n");
}

void proc_led (void *rf_r_handler_ch3)
{
    printf("led in\n");
}
