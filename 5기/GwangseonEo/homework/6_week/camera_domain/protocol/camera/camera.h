#ifndef __CAMERA_H__
#define __CAMERA_H__

enum camera{
    CAM_ACTIVE,
    CAM_ZOOM,
    CAM_FOCUS,
    CAM_BRIGHTNESS,
    CAM_MOTION,
    CAM_END
};

#define CAMERA_CALL_BUFFER_COUNT    (CAM_END)
#define CAMERA_CALL_BUFFER          ((CAM_END)-1)

#endif