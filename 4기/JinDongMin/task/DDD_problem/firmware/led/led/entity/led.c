#include "led.h"

void init_led(led_object *led_object_ptr, pin *pin_ptr)
{
    led_object_ptr->pin_info_ptr = pin_ptr;
}

void change_led_status(led_object *led_object_ptr, int status)
{
    led_object_ptr->status = status;
}
