#include "led.h"

#include "../../common.h"
#include "../pin/pin.h"
#include <util/delay.h>

void init_led(led *led_ptr, int st, const pin *pin_ptr)
{
    switch (st)
    {
        case LED_OFF:
            turn_off_led(led_ptr);
            break;
        case LED_ON:
            turn_on_led(led_ptr);
            break;
    }

    led_ptr->pin_info_ptr = pin_ptr;
}

void turn_off_led(led *led_ptr)
{
    led_ptr->status = LED_OFF;

    change_pin_mode(led_ptr->pin_info_ptr, READ);
}

void turn_on_led(led *led_ptr)
{
    led_ptr->status = LED_ON;

    change_pin_mode(led_ptr->pin_info_ptr, WRITE);
}

void blink_led(led *led_ptr, double millisecond)
{
    turn_off_led(led_ptr);
    _delay_ms(millisecond);

    turn_on_led(led_ptr);
    _delay_ms(millisecond);
}
