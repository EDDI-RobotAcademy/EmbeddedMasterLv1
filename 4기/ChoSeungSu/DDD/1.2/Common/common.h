#ifndef __COMMON_H__
#define __COMMMON_H__

#define DO_NOTHING      -1

#define DC_MIN          0
#define DC_MAX          255

#define STOP                    0
#define CLOCK_WISE              1
#define COUNTER_CLOCK_WISE      2

enum rf_scale_method {
    RF_SCALE_DC_MOTOR,
    RF_SCALE_SERVO_MOTOR,
    RF_SCALE_LED,
    RF_SCALE_END
};

#endif