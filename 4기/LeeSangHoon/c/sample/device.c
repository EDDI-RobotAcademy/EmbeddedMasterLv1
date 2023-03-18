#include <stdio.h>
#include "device.h"

void proc_camera (void *dto)
{
    data_transfer_object *casting_dto = dto;
    printf("Camera Processing - num: %d, name: %s\n",
        casting_dto->num, casting_dto->name);
}

int proc_dc_motor (void *dto)
{
    data_transfer_object *casting_dto = dto;
    printf("DC Motor Processing - num: %d, name: %s\n",
        casting_dto->num, casting_dto->name);

    return 3;
}

float proc_bldc (void *dto)
{
    data_transfer_object *casting_dto = dto;
    printf("BLDC Motor Processing - num: %d, name: %s\n",
        casting_dto->num, casting_dto->name);

    return 0.7f;
}

void proc_pmsm (void *dto)
{
    data_transfer_object *casting_dto = dto;
    printf("PMSM Motor Processing - num: %d, name: %s\n",
        casting_dto->num, casting_dto->name);
}

void proc_acim (void *dto)
{
    data_transfer_object *casting_dto = dto;
    printf("ACIM Motor Processing - num: %d, name: %s\n",
        casting_dto->num, casting_dto->name);
}

void proc_led (void *dto)
{
    data_transfer_object *casting_dto = dto;
    printf("LED Toggle - num: %d, name: %s\n",
        casting_dto->num, casting_dto->name);
}

void proc_i2c (void *dto)
{
    data_transfer_object *casting_dto = dto;
    printf("MPU6050 Processing - num: %d, name: %s\n",
        casting_dto->num, casting_dto->name);
}

void proc_spi (void *dto)
{
    data_transfer_object *casting_dto = dto;
    printf("25LC010A EEPROM Processing - num: %d, name: %s\n",
        casting_dto->num, casting_dto->name);
}

void proc_can (void *dto)
{
    data_transfer_object *casting_dto = dto;
    printf("CAN Communication - num: %d, name: %s\n",
        casting_dto->num, casting_dto->name);
}

void proc_ecap (void *dto)
{
    data_transfer_object *casting_dto = dto;
    printf("ECAP RF Receiving - num: %d, name: %s\n",
        casting_dto->num, casting_dto->name);
}
