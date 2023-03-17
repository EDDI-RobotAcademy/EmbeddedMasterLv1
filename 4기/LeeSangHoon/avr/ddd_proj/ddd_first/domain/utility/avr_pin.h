#ifndef __AVR_PIN_H__
#define __AVR_PIN_H__

typedef enum _PIN_MAP PIN_MAP;
enum _PIN_MAP
{
    PIN_PORT0 = 0,
    PIN_PORT1 = 1,
    PIN_PORT2 = 2,
    PIN_PORT3 = 3,
    PIN_PORT4 = 4,
    PIN_PORT5 = 5,
    PIN_PORT6 = 6,
    PIN_PORT7 = 7,

    PIN_PORT8 = 8,
    PIN_PORT9 = 9,
    PIN_PORT10 = 10,
    PIN_PORT11 = 11,
    PIN_PORT12 = 12,
    PIN_PORT13 = 13,

    PIN_A0 = 14,
    PIN_A1,
    PIN_A2,
    PIN_A3,
    PIN_A4,
    PIN_A5
};

unsigned char *get_pinmap_port_group (PIN_MAP pin);

#endif
