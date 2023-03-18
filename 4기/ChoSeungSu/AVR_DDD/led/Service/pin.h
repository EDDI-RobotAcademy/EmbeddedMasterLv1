#ifndef __PIN_H__
#define __PIN_H__

#include "../Common/common.h"
#include "../Entity/led.h"

typedef struct _pin
{
    uint8_t * direction;

}pin;

typedef enum
{
    DDRB = 0x24,
    PORTB = 0x25

}register_map;


void pin_direction(pin led_pin, uint8_t pin_addr);

#endif