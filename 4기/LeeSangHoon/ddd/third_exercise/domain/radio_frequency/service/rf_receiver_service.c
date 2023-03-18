#include "../../radio_frequency/entity/rf_receiver.h"
#include "data_transfer_object/rf_receiver_data_transfer_object.h"
#include "../../common/utility/common.h"
#include "../../dc_motor/entity/dc_motor_control_data.h"
#include "../../common/utility/scale/custom_scale.h"
#include "../../servo_motor/entity/servo_motor_control_data.h"
#include "../../led/entity/led_control_data.h"

int check_dc_motor_direction()
{
    if (rf_receiver_dto.channel_data > 1020)
    {
        rf_receiver_dto.channel_sub_order = CLOCK_WISE;
    }
    else if (rf_receiver_dto.channel_data < 980)
    {
        rf_receiver_dto.channel_sub_order = COUNTER_CLOCK_WISE;
    }
    else
    {
        rf_receiver_dto.channel_sub_order = STOP;
    }

    return rf_receiver_dto.channel_sub_order;
}

void rf_signal_scale2dc_motor (void)
{
    int rf_range;
    int scaled_signal4dc_motor;
    float scale_factor;
    int direction = check_dc_motor_direction();

    if (direction == CLOCK_WISE)
    {
        rf_range = RF_MAX - RF_MIDDLE;
        scale_factor = DC_MOTOR_MAX / (float)rf_range;
        scaled_signal4dc_motor = scale_data(rf_receiver_dto.channel_data - RF_MIDDLE, scale_factor, DC_MOTOR_MIN);
    }
    else if (direction == COUNTER_CLOCK_WISE)
    {
        rf_range = RF_MIDDLE - RF_MIN;
        scale_factor = DC_MOTOR_MAX / (float)rf_range;
        scaled_signal4dc_motor = reverse_scale_data(rf_receiver_dto.channel_data - RF_MIN, scale_factor, DC_MOTOR_MAX);
    }

    config_dc_motor_control_data(direction, scaled_signal4dc_motor);
}

void rf_signal_scale2servo_motor (void)
{
    int rf_range = RF_MAX - RF_MIN;
    int scaled_signal4servo_motor;
    float scale_factor = (SERVO_MOTOR_MAX - SERVO_MOTOR_MIN) / (float)rf_range;

    scaled_signal4servo_motor = scale_data(rf_receiver_dto.channel_data - RF_MIN, scale_factor, SERVO_MOTOR_MIN);
    config_servo_motor_control_data(scaled_signal4servo_motor);
}

void rf_signal_scale2led (void)
{
    if (rf_receiver_dto.channel_data >= LED_ON_THRESHOLD) { config_led_control_data(LED_ON); }
    else if (rf_receiver_dto.channel_data <= LED_OFF_THRESHOLD) { config_led_control_data(LED_OFF); }
}