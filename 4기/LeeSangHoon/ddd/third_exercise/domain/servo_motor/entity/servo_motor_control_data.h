#ifndef __SERVO_MOTOR_CONTROL_DATA_H__
#define __SERVO_MOTOR_CONTROL_DATA_H__

typedef struct _servo_motor_control_object servo_motor_control_object;

struct _servo_motor_control_object
{
    int control_data;
};

servo_motor_control_object servo_motor_control_data;

void config_servo_motor_control_data (int);

#endif
