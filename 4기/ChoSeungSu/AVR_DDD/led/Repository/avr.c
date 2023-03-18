#include "avr.h"

void set_pin_data(pin led_pin, uint8_t bit_data)
{
    *(led_pin.direction) = bit_data; 
}