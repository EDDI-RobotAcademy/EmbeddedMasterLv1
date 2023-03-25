#include "led_repository.h"
#include "../../pin/pin_map.h"

#include <avr/io.h>

void set_legacy_direction (led led_entity)
{
    pin_vo pin = led_entity.pin;
    PIN_MAP pin_map = pin.pin_map;

    if (pin_map > (PIN_A0 - 1))
    {
        DDRC = 1 << (pin_map - PIN_A0);
    }
    else if (pin_map > (PIN_PORT8 - 1))
    {
        DDRB = 1 << (pin_map - PIN_PORT8);
    }
    else
    {
        DDRD = 1 << pin_map;
    }
}

void gpio_write (led led_entity)
{
    LED_STATUS status = led_entity.status;
    pin_vo pin = led_entity.pin;
    PIN_MAP pin_map = pin.pin_map;

    if (pin_map > (PIN_A0 - 1))
    {
        PORTC = status << (pin_map - PIN_A0);
    }
    else if (pin_map > (PIN_PORT8 - 1))
    {
        PORTB = status << (pin_map - PIN_PORT8);
    }
    else
    {
        PORTD = status << pin_map;
    }
}

