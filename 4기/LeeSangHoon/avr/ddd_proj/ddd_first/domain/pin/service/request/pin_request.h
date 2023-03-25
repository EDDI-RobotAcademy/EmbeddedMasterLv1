#ifndef __PIN_REQUEST_H__
#define __PIN_REQUEST_H__

struct _pin_request
{
    unsigned char *hw_pin_address;
    int shifted_value;
};

struct _pin_request pin_request;

#endif // __PIN_REQUEST_H__
