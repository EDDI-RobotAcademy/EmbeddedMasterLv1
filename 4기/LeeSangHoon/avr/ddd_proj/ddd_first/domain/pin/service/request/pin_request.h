#ifndef __PIN_REQUEST_H__
#define __PIN_REQUEST_H__

#include <stdint.h>

struct _pin_request
{
    volatile unsigned char *hw_pin_address;
    uint8_t shifted_value;
};

struct _pin_request pin_request;
struct _pin_request led_port_request;

#endif // __PIN_REQUEST_H__
