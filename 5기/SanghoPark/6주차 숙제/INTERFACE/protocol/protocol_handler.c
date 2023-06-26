#include "protocol_handler.h"
#include "../camera/camera_handler.h"
#include "../camera/camera_interface_table.h"

#include <stdio.h>
void proc_camera (void* pCamera)
{
    printf("Camera 프로토콜을 처리합니다.\n");
	
    camera_interface_table[*(unsigned int*)pCamera]();
}

void proc_dc_motor (void* pDcMotor)
{
    printf("DC Motor 프로토콜을 처리합니다.\n");
	
    printf("DC Motor %d : 미구현 스펙 입니다.\n", *(unsigned int*)pDcMotor);
}

void proc_bldc_motor (void* pBldcMotor)
{
    printf("BLDC Motor 프로토콜을 처리합니다.\n");
	
    printf("BLDC Motor %d : 미구현 스펙 입니다.\n", *(unsigned int*)pBldcMotor);
}

void proc_pmsm_motor (void* pPmsmMotor)
{
    printf("PMSM Motor 프로토콜을 처리합니다.\n");
	
    printf("PMSM Motor %d : 미구현 스펙 입니다.\n", *(unsigned int*)pPmsmMotor);
}

void proc_acim_motor (void* pAcimMotor)
{
    printf("ACIM Motor프로토콜을 처리합니다.\n");
	
    printf("ACIM Motor %d : 미구현 스펙 입니다.\n", *(unsigned int*)pAcimMotor);
}

void proc_power_led (void* pPowerLed)
{
    printf("Power LED 프로토콜을 처리합니다.\n");
	
    printf("Power LED %d : 미구현 스펙 입니다.\n", *(unsigned int*)pPowerLed);
}

void proc_i2c (void* pI2c)
{
    printf("I2C 프로토콜을 처리합니다.\n");
	
    printf("I2C %d : 미구현 스펙 입니다.\n", *(unsigned int*)pI2c);
}

void proc_spi (void* pSpi)
{
    printf("SPI 프로토콜을 처리합니다.\n");
	
    printf("SPI %d : 미구현 스펙 입니다.\n", *(unsigned int*)pSpi);
}

void proc_lidar (void* pLidar)
{
    printf("LIDAR 프로토콜을 처리합니다.\n");
	
    printf("LIDAR %d : 미구현 스펙 입니다.\n", *(unsigned int*)pLidar);
}

void proc_can (void* pCan)
{
    printf("CAN 프로토콜을 처리합니다.\n");
	
    printf("CAN %d : 미구현 스펙 입니다.\n", *(unsigned int*)pCan);
}

void proc_ecap (void* pEcap)
{
    printf("프로토콜을 처리합니다.\n");
	
    printf("ECAP %d : 미구현 스펙 입니다.\n", *(unsigned int*)pEcap);
}