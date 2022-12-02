#include <stdio.h>

void receive_rf_signal (void)
{
    rf_receive_object_data.channel[current_rf_channel++] = handle_rf_channel_data();

    if (current_rf_channel == RF_CHANNEL_MAX) { current_rf_channel = 0; }
}

int handle_rf_channel_data (void)
{
    return custom_random(RF_MIN, RF_MAX);
}

void print_rf_channel_data (void)
{
    int i;

    printf("ch1 = %d, ch2 = %d, ch3 = %d, ch4 = %d, ch5 = %d, ch6 = %d, ch7 = %d, ch8 = %d\n",
           rf_receive_object_data.channel[0], rf_receive_object_data.channel[1],
           rf_receive_object_data.channel[2], rf_receive_object_data.channel[3],
           rf_receive_object_data.channel[4], rf_receive_object_data.channel[5],
           rf_receive_object_data.channel[6], rf_receive_object_data.channel[7]);
}

int is_all_rf_channel_set (void)
{
    int i;

    if (current_rf_channel == 0) { return EVERY_RF_CHANNEL_SET; }
    else { return SOME_RF_CHANNEL_SET; }
}

int check_dc_motor_direction(int channel)
{
    if (rf_receive_object_data.channel[channel - 1] > 1020)
        return CLOCK_WISE;
    else if (rf_receive_object_data.channel[channel - 1] < 980)
        return COUNTER_CLOCK_WISE;
    else
        return STOP;
}

int clock_wise_dc_motor_scale (int channel)
{
    int rf_range = RF_MAX - RF_MIDDLE;
    float scale_factor = DC_MAX / (float)rf_range;

    return (rf_receive_object_data.channel[channel - 1] - RF_MIDDLE) * scale_factor;
}

int counter_clock_wise_dc_motor_scale (int channel)
{
    int rf_range = RF_MIDDLE - RF_MIN;
    float scale_factor = DC_MAX / (float)rf_range;

    return DC_MAX - (rf_receive_object_data.channel[channel - 1] - RF_MIN) * scale_factor;
}

int rf_data_convert_to_dc_motor_control (int channel)
{
    int scaled_channel_data;

    if (check_dc_motor_direction(channel) == CLOCK_WISE)
    {
        scaled_channel_data = clock_wise_dc_motor_scale(channel);
    }
    else if (check_dc_motor_direction(channel) == COUNTER_CLOCK_WISE)
    {
        scaled_channel_data = counter_clock_wise_dc_motor_scale(channel);
    }
    else
    {
        scaled_channel_data = 0;
    }

    return scaled_channel_data;
}

int rf_data_convert_to_servo_motor_control (int channel)
{
    int rf_range = RF_MAX - RF_MIN;
    float scale_factor = (SERVO_MAX - SERVO_MIN) / (float)rf_range;

    return (rf_receive_object_data.channel[channel - 1] - RF_MIN) * scale_factor + 500;
}

int rf_data_convert_to_led_control (int channel)
{
    if (rf_receive_object_data.channel[channel - 1] >= LED_ON_THRESHOLD) { return 1; }
    else if (rf_receive_object_data.channel[channel - 1] <= LED_OFF_THRESHOLD) { return 0; }
}

void rf_data_handle (void)
{
    int i;
    int scaled_channel1, scaled_channel2, scaled_channel3;

    // 무엇을 하는지는 알겠지만 구조적 측면에서 매우 지저분한 느낌이 강함
    // 향후 유지보수나 추가 확장을 진행할 경우 상당히 혜비한 느낌을 줄 수 있음.
    // 또한 현재 사용하는 모터의 종류가 바뀌는 상황에 대한 대응시
    // 지속적으로 이 파일 자체가 무거워지는 현상이 발생하여 점점 파악이 어려워질 것이다.
    scaled_channel1 = rf_data_convert_to_dc_motor_control(CHANNEL1);
    scaled_channel2 = rf_data_convert_to_servo_motor_control(CHANNEL2);
    scaled_channel3 = rf_data_convert_to_led_control(CHANNEL3);

    printf("ch1: %d, ch2: %d, ch3: %s\n", scaled_channel1, scaled_channel2, scaled_channel3 ? "On" : "Off");
}