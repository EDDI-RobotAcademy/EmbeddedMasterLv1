#ifndef __CAMERA_H__
#define __CAMERA_H__

enum camera
{
    ACTIVE,
    I2C,
    READ_ADD,
    MIPI,
    LVDS,
    END
};

#define CAMERA_CALL_BUFFER_COUNT    (END)
#define CAMERA_CALL_BUFFER          ((END)-1)

#endif