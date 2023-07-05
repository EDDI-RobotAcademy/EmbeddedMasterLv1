#include "camera_handler.h"

#include <stdio.h>

void proc_cam_init (void)
{
    printf("Camera Sensor를 초기화합니다.\n");
}

void proc_cam_opmode (void)
{
    printf("Camera Sensor의 동작 모드를 설정합니다.\n");
}

void proc_cam_settings (void)
{
    printf("Camera Sensor의 해상도, 밝기, 주사율 등을 설정합니다.\n");
}

void proc_cam_capture (void)
{
    printf("Camera Sensor의 Image Capture를 제어합니다.\n");
}