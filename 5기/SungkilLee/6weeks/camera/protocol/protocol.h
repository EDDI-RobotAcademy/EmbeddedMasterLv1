#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

enum protocol
{
    PICTURE,
    VIDEO,
    TIMELAPSE,
    SLOW_MOTION,
    CINEMATIC,
    PANORAMA,
    END
};

#define PROTOCOL_CALL_BUFFER_COUNT          (END)
#define PROTOCOL_CALL_BUFFER                ((END) - 1)

#endif