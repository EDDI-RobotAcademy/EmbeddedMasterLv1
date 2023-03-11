#ifndef __PIN_H__
#define __PIN_H__

#include <avr/io.h>

#include "../../common.h"
#define DEFAULT_PIN_MODE    READ

typedef struct {
    uint8_t *port_register_ptr;
    int bit_number;
} pin;

void init_pin(pin *, const uint8_t *, int);

void change_pin_mode(pin *, int);

#endif /* __PIN_H__ */
