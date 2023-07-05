#include <stdio.h>

#include "camera_handler.h"

void proc_cam_active(void)
{
    printf("카메라를 활성화합니다.\n");
}

void proc_cam_zoom(void)
{
    printf("줌 조절 기능을 실행합니다.\n");
}

void proc_cam_focus(void)
{
    printf("포커스 조절 기능을 실행합니다.\n");
}

void proc_cam_brightness(void)
{
    printf("밝기 조절을 실행합니다.\n");
}

void proc_cam_motion(void)
{
    printf("모션 감지 기능을 실행합니다.");
}