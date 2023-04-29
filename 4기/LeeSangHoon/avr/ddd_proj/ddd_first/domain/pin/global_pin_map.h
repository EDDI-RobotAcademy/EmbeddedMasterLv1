#ifndef __GLOBAL_PIN_MAP_H__
#define __GLOBAL_PIN_MAP_H__

static unsigned char *pin_map_direction_vo[3] = {
    (unsigned char *)0x2a,      // DDRD
    (unsigned char *)0x24,      // DDRB
    (unsigned char *)0x27       // DDRC
};

static unsigned char *pin_map_port_vo[3] = {
    (unsigned char *)0x2b,      // PORTD
    (unsigned char *)0x25,      // PORTB
    (unsigned char *)0x28       // PORTC
};

#endif // __GLOBAL_PIN_MAP_H__
