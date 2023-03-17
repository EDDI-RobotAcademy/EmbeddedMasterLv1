#include "pin_map.h"

unsigned char *find_pin_io_map(PIN_MAP pin)
{
    if (pin > 15)
    {
        //PORTC = 1 << (pin - PIN_A0);
    }
    else if (pin > 7)
    {
        //PORTB = 1 << (pin - PIN_PORT8);
    }
    else
    {
        //PORTD = 1 << pin;
    }
}
