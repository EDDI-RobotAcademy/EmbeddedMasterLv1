#ifndef __PIN_H__
#deifne __PIN_H__

// Value Object
typedef struct _pin pin;

struct _pin
{
    uint8_t *port_register_ptr;
    int bit_number;
};

void init_pin(pin *, const uint8_t *, int);

#endif // __PIN_H__
