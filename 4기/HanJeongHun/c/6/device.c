#include <stdio.h>
#include "device.h"

void proc_camera (void)
{
    printf("Camera Processing\n");
}

int proc_dc_motor (void)
{
    printf("DC Motor Processing\n");

    return 3;
}

float proc_bldc (void)
{
    printf("BLDC Motor Processing\n");

    return 0.7f;
}

void proc_pmsm (void)
{
    printf("PMSM Motor Processing\n");
}

void proc_acim (void)
{
    printf("ACIM Motor Processing\n");
}

void proc_led (void *p)
{
    printf("LED Toggle\n");
}

void proc_i2c (void)
{
    printf("MPU6050 Processing\n");
}

void proc_spi (void)
{
    printf("25LC010A EEPROM Processing\n");
}

void proc_can (void)
{
    printf("CAN Communication\n");
}

void proc_ecap (void)
{
    printf("ECAP RF Receiving\n");
}
