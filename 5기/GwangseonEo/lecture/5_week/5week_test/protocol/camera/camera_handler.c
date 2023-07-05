#include <stdio.h>

#include "camera_handler.h"

void proc_cam_active(void)
{
    printf("카메라를 활성화합니다..\n");
}

void proc_cam_zoom(void)
{
    printf("카메라 줌 모드를 실행합니다.\n");
}

void proc_cam_focus(void)
{
    printf("카메라 포커스 모드를 실행합니다.\n");
}

void proc_cam_brightness(void)
{
    printf("카메라 밝기 조절 모드를 실행합니다.\n");
}
