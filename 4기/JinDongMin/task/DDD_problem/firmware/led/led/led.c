#include "led.h"

void change_led_status(led_object *led_object_ptr, int status)
{
    led_object_ptr->status = status;
}
