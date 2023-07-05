#ifndef __CAMERA_CALL_TABLE_MAPPER_H__
#define __CAMERA_CALL_TABLE_MAPPER_H__

#include "camera_handler.h"

#define __CAMERA_CALL_TABLE(nr,sym) [nr] = sym,

__CAMERA_CALL_TABLE(0, proc_cam_active)
__CAMERA_CALL_TABLE(1, proc_cam_zoom)
__CAMERA_CALL_TABLE(2, proc_cam_focus)
__CAMERA_CALL_TABLE(3, proc_cam_brightness)
__CAMERA_CALL_TABLE(4, proc_cam_motion)


#endif