#include "../../entity/radio_frequency/rf_receiver.h"
#include "data_transfer_object/rf_receive_data_transfer_object.h"
#include "rf_receive_data_scale.h"
#include "../../common/common.h"

int check_dc_motor_direction()
{
    if (rf_receive_dto.channel_data > 1020)
        rf_receive_dto.channel_sub_order = CLOCK_WISE;
    else if (rf_receive_dto.channel_data < 980)
        rf_receive_dto.channel_sub_order = COUNTER_CLOCK_WISE;
    else
        rf_receive_dto.channel_sub_order = STOP;

    return rf_receive_dto.channel_sub_order;
}

int clock_wise_dc_motor_scale (void)
{
    int rf_range = RF_MAX - RF_MIDDLE;
    float scale_factor = DC_MAX / (float)rf_range;

    return (rf_receive_dto.channel_data - RF_MIDDLE) * scale_factor;
}

int counter_clock_wise_dc_motor_scale (void)
{
    int rf_range = RF_MIDDLE - RF_MIN;
    float scale_factor = DC_MAX / (float)rf_range;

    return DC_MAX - (rf_receive_dto.channel_data - RF_MIN) * scale_factor;
}

int rf_scale_dc_motor (void)
{
    int scaled_channel_data;

    if (check_dc_motor_direction() == CLOCK_WISE)
    {
        scaled_channel_data = clock_wise_dc_motor_scale();
    }
    else if (check_dc_motor_direction() == COUNTER_CLOCK_WISE)
    {
        scaled_channel_data = counter_clock_wise_dc_motor_scale();
    }
    else
    {
        scaled_channel_data = 0;
    }

    return scaled_channel_data;
}

int rf_scale_servo_motor (void)
{
    int rf_range = RF_MAX - RF_MIN;
    float scale_factor = (SERVO_MAX - SERVO_MIN) / (float)rf_range;

    return (rf_receive_dto.channel_data - RF_MIN) * scale_factor + 500;
}

int rf_scale_led (void)
{
    if (rf_receive_dto.channel_data >= LED_ON_THRESHOLD) { return 1; }
    else if (rf_receive_dto.channel_data <= LED_OFF_THRESHOLD) { return 0; }
}
