#include "avr_pin.h"

#include <avr/io.h>

unsigned char *get_pinmap_port_group (PIN_MAP pin)
{
    if (pin > PIN_PORT13) { return PORTC; }

    if (pin > PIN_PORT7) { return PORTB; }

    return PORTD;
}
