#ifndef __CAMERA_INTERFACE_TABLE_H__
#define __CAMERA_INTERFACE_TABLE_H__

#include <stdio.h>
#include "camera.h"

typedef void (*camera_interface_ptr_t) (void);

void behavior_not_implemented (void)
{
    printf("미구현 동작 입니다.\n");
}

const camera_interface_ptr_t camera_interface_table[CAMERA_INTERFACE_BUFFER_COUNT] = {
    [0 ... CAMERA_INTERFACE_INTERFACE_BUFFER] = &behavior_not_implemented,
    #include "camera_interface_table_mapper.h"
};

#endif