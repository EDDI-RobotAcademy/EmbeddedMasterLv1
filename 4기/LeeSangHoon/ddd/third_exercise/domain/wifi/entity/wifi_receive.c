#include "wifi_receive.h"
#include "../../utility/random/custom_random.h"
#include "../../common/utility/common.h"

#include <stdio.h>

void receive_wifi_data (void)
{
    get_random_wifi_data();
}

// 실제로는 인터페이스화 해서 처리해야 했으나 랜덤값 처리라 현실 상황이 아니므로 그냥 내비뒀음
void get_random_wifi_data (void)
{
    wifi_receive_object_data.service_number = custom_random(DC_MOTOR, LED);

    if (wifi_receive_object_data.service_number == DC_MOTOR)
    {
        wifi_receive_object_data.service_number_data = custom_random(DC_MOTOR_GEAR_MIN, DC_MOTOR_GEAR_MAX);
        wifi_receive_object_data.dc_motor_direction = custom_random(CLOCK_WISE, COUNTER_CLOCK_WISE);
    }
    else if (wifi_receive_object_data.service_number == SERVO_MOTOR)
    {
        wifi_receive_object_data.service_number_data = custom_random(SERVO_LEFT_MAX, SERVO_RIGHT_MAX);
    }
    else if (wifi_receive_object_data.service_number == LED)
    {
        wifi_receive_object_data.service_number_data = custom_random(ON, OFF);
    }
}

void print_wifi_data (void)
{
    printf("service code: %d, data: %d",
           wifi_receive_object_data.service_number,
           wifi_receive_object_data.service_number_data);

    if (wifi_receive_object_data.service_number == DC_MOTOR)
    {
        printf(", direction: %s\n",
               wifi_receive_object_data.dc_motor_direction == CLOCK_WISE ? "CW" : "CCW");
    }
}