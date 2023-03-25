#include "../service/led_control.h"

void led_turn_on(led_object *led_object_ptr)
{
    const pin *pin_ptr = led_object_ptr->pin_info_ptr;

    *(pin_ptr->port_register_ptr) |= _BV(pin_ptr->bit_number);
}

void led_turn_off(led_object *led_object_ptr)
{
    const pin *pin_ptr = led_object_ptr->pin_info_ptr;

    *(pin_ptr->port_register_ptr) &= ~(_BV(pin_ptr->bit_number));
}

void led_toggle(led_object *led_object_ptr)
{
    switch (led_object_ptr->status)
    {
        case LED_OFF:
            led_turn_on(led_object_ptr);
            break;
        case LED_ON:
            led_turn_off(led_object_ptr);
            break;
    }
}
