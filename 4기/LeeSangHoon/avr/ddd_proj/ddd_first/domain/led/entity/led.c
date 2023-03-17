#include <stdio.h>
#include <stdlib.h>

#include "led.h"
#include "../../utility/avr_pin.h"

void led_entity_init (PIN_MAP pin, LED_STATUS status)
{
    led_entity.pin = pin;
    led_entity.status = status;
}

LED_STATUS get_led_status (void)
{
    return led_entity.status;
}

void set_led_status (LED_STATUS status)
{
    led_entity.status = status;
}

PIN_MAP get_led_pin (void)
{
    return led_entity.pin;
}



