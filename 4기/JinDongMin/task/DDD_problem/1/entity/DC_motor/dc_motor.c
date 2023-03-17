#include "dc_motor.h"

void initialize_dc_motor(dc_motor *_dc_motor) { }

void control_dc_motor(dc_motor *_dc_motor, int _speed)
{
    _dc_motor->speed = _speed;
}

int get_dc_motor_speed(const dc_motor _dc_motor)
{
    return _dc_motor.speed;
}