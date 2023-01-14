#include "custom_scale.h"

int scale_data (int criteria_data, float scale_factor, int base_value)
{
    //dc_motor_control_data.direction = CLOCK_WISE;
    return base_value + criteria_data * scale_factor;
}

int reverse_scale_data (int criteria_data, float scale_factor, int base_value)
{
    //dc_motor_control_data.direction = COUNTER_CLOCK_WISE;
    //dc_motor_control_data.control_data = base_value - criteria_data * scale_factor;
    return base_value - criteria_data * scale_factor;
}