#ifndef __CAMERA_H__
#define __CAMERA_H__

enum camera{
    SELFIE,
    PHOTO,
    VIDEO,
    PANORAMA,
    SLOW_MOTION,
    END
};

#define CAMERA_CALL_BUFFER_COUNT (END)
#define CAMERA_CALL_BUFFER ((END)-1)

#endif