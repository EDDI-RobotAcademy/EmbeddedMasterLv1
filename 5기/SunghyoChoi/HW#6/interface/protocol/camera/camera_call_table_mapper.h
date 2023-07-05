#ifndef __CAMERA_CALL_TABLE_MAPPER_H__
#define __CAMERA_CALL_TABLE_MAPPER_H__

#include "camera_func.h"

#define __CAMERA_CALL_TABLE(nr,sym) [nr] = sym,

__CAMERA_CALL_TABLE(0, camera_selfie)
__CAMERA_CALL_TABLE(1, camera_photo)
__CAMERA_CALL_TABLE(2, camera_video)
__CAMERA_CALL_TABLE(3, camera_panorama)
__CAMERA_CALL_TABLE(4, camera_slow_motion)



#endif