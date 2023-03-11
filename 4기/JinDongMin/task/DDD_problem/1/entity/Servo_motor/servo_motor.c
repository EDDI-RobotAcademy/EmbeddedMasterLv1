#include "servo_motor.h"

void initialize_servo_motor(servo_motor *_servo_motor) { }

void control_servo_motor(servo_motor *_servo_motor, int _speed)
{
    _servo_motor->speed = _speed;
}

int get_servo_motor_speed(const servo_motor _servo_motor)
{
    return _servo_motor.speed;
}