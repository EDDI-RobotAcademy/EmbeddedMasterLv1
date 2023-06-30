#include "camera_handler.h"
#include <stdio.h>

void proc_active(void){
    printf("카메라 활성화\n");
}

void proc_i2c(void){
    printf("이미지 센서 i2c 동작 확인\n");
}

void proc_read_add(void){
    printf("이미지 센서 Address 확인\n");
}

void proc_mipi(void){
    printf("이미지 센서 mipi 출력 확인\n");
}

void proc_lvds(void){
    printf("이미지 센서 lvds 출력 확인\n");
}