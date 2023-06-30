#ifndef __CAMERA_CALL_TABLE_MAPPER_H__
#define __CAMERA_CALL_TABLE_MAPPER_H__

#include "camera_handler.h"

#define __CAMERA_CALL_TABLE(nr, sym) [nr] = sym,

__CAMERA_CALL_TABLE(0, proc_active)
__CAMERA_CALL_TABLE(1, proc_i2c)
__CAMERA_CALL_TABLE(2, proc_read_add)
__CAMERA_CALL_TABLE(3, proc_mipi)
__CAMERA_CALL_TABLE(4, proc_lvds)

#endif