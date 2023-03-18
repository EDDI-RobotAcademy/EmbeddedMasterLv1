#include "../service/led_control.h"

void turn_on_led(led_object *led_object_ptr)
{
    const pin *pin_ptr = led_object_ptr->pin_info_ptr;

    *(pin_ptr->port_register_ptr) |= _BV(pin_ptr->bit_number);

    change_led_status(led_object_ptr, LED_ON);
}

void turn_off_led(led_object *led_object_ptr)
{
    const pin *pin_ptr = led_object_ptr->pin_info_ptr;

    *(pin_ptr->port_register_ptr) &= _BV(pin_ptr->bit_number);

    change_led_status(led_object_ptr, LED_OFF);
}

void toggle_led(led_object *led_object_ptr)
{
    switch (led_object_ptr->status)
    {
        case LED_OFF:
            turn_on_led(led_object_ptr);
            break;
        case LED_ON:
            turn_off_led(led_object_ptr);
            break;
    }
}
