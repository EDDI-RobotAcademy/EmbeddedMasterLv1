#include "dc_motor_control_data.h"
#include "../../common/utility/common.h"

void scale_clock_wise_dc_motor (int criteria_data, float scale_factor)
{
    dc_motor_control_data.direction = CLOCK_WISE;
    dc_motor_control_data.control_data = criteria_data * scale_factor;
}

void scale_counter_clock_wise_dc_motor (int criteria_data, float scale_factor)
{
    dc_motor_control_data.direction = COUNTER_CLOCK_WISE;
    dc_motor_control_data.control_data = DC_MOTOR_MAX - criteria_data * scale_factor;
}

void config_dc_motor_control_data (int direction, int control_data)
{
    dc_motor_control_data.direction = direction;
    dc_motor_control_data.control_data = control_data;
}

void scale_info2dc_motor (int direction, int data_range, int criteria_data)
{
    float scale_factor = DC_MOTOR_MAX / (float)data_range;

    if (direction == CLOCK_WISE)
    {
        scale_clock_wise_dc_motor(criteria_data, scale_factor);
    }
    else if (direction == COUNTER_CLOCK_WISE)
    {
        scale_counter_clock_wise_dc_motor(criteria_data, scale_factor);
    }
    else { dc_motor_control_data.direction = STOP; }
}