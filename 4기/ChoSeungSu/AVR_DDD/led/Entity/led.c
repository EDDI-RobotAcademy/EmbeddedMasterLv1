#include "led.h"

// led_object * init_led(void)
// {
//     static led_object led_obj;
    
//     return & led_obj;
// }

void blink_led(led_object * led_obj_ptr)
{
    led_obj_ptr->status = ~led_obj_ptr->status;
}