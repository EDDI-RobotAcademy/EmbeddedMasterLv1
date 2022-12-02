#ifndef __DC_MOTOR_CONTROL_DATA_H__
#define __DC_MOTOR_CONTROL_DATA_H__

typedef struct _dc_motor_control_object dc_motor_control_object;

struct _dc_motor_control_object
{
    int direction;
    int control_data;
};

dc_motor_control_object dc_motor_control_data;

void scale_clock_wise_dc_motor (int, float);
void scale_counter_clock_wise_dc_motor (int, float);
void scale_info2dc_motor (int, int, int);

#endif
