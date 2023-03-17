#include "led_repository.h"
#include "../../utility/avr_pin.h"

#include <avr/io.h>

static void setDirectionRegister (uint8_t pin)
{
    if (pin == PIN_PORT13) { DDRB = 0x20; }
}

static void setStatus(uint8_t pin, uint8_t status)
{
    if (pin == PIN_PORT13) { PORTB = 0x20; }
}

void led_out (led led_entity)
{
    unsigned char *real_hw_address = get_pinmap_port_group(get_led_pin());
    LED_STATUS status = get_led_status();

    *real_hw_address = status;
}
