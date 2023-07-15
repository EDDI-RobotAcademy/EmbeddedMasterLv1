#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "protocol_handler.h"
#include "camera/camera_call_table.h"
#include "camera/camera_handler.h"

void proc_camera(void *p){
    printf("카메라 프로토콜을 처리합니다!\n");
    
    unsigned int *pFunc = p;
    printf("p = %d\n", *pFunc);
    
    camera_call_table[*pFunc](); 
    
}

void proc_dc_motor(void *p){
    printf("dc motor 프로토콜을 처리합니다!\n");
}

void proc_bldc_motor(void *p){
    printf("bldc motor 프로토콜을 처리합니다!\n");
}

void proc_pmsm_motor(void *p){
    printf("pmsm motor 프로토콜을 처리합니다!\n");
}

void proc_acim_motor(void *p){
    printf("acim motor 프로토콜을 처리합니다!\n");
}

void proc_power_led(void *p){
    printf("power led 프로토콜을 처리합니다!\n");
}

void proc_i2c(void *p){
    printf("i2c 프로토콜을 처리합니다!\n");
}

void proc_spi(void *p){
    printf("spi 프로토콜을 처리합니다!\n");
}

void proc_lidar(void *p){
    printf("lidar 프로토콜을 처리합니다!\n");
}

void proc_can(void *p){
    printf("can 프로토콜을 처리합니다!\n");
}

void proc_ecap(void *p){
    printf("ecap 프로토콜을 처리합니다!\n");
}