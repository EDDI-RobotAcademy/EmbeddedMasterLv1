#ifndef __CAMERA_INTERFACE_TABLE_MAPPER_H__
#define __CAMERA_INTERFACE_TABLE_MAPPER_H__

#include "camera_handler.h"

#define __CAMERA_INTERFACE_TABLE(nr, sym) [nr] = sym,

__CAMERA_INTERFACE_TABLE(CAM_INITIAL, proc_cam_init)
__CAMERA_INTERFACE_TABLE(CAM_OPMODE, proc_cam_opmode)
__CAMERA_INTERFACE_TABLE(CAM_SETTINGS, proc_cam_settings)
__CAMERA_INTERFACE_TABLE(CAM_CAPTURE, proc_cam_capture)

#endif