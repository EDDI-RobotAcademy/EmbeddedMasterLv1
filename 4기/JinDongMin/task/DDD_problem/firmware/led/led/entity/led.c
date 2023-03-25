#include "led.h"

void init_led(led_object *led_object_ptr, const pin *pin_ptr)
{
    led_object_ptr->pin_info_ptr = pin_ptr;
}

void change_led_status(led_object *led_object_ptr, LED_STATUS status)
{
    led_object_ptr->status = status;
}

LED_STATUS get_led_status(const led_object *led_object_ptr)
{
    return led_object_ptr->status;
}
