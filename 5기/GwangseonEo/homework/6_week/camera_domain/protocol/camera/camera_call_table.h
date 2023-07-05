#ifndef __CAMERA_CALL_TABLE_H__
#define __CAMERA_CALL_TABLE_H__

#include "stdio.h"
#include "camera.h"

typedef void (* camera_call_ptr_t)(void);

void camera_not_implemented(void)
{
    printf("아직 구현되지 않은 카메라 기능입니다.\n");
}

const camera_call_ptr_t camera_call_table[CAMERA_CALL_BUFFER_COUNT]={
    [0 ... CAMERA_CALL_BUFFER]=&camera_not_implemented,
    #include "camera_call_table_mapper.h"
};

#endif