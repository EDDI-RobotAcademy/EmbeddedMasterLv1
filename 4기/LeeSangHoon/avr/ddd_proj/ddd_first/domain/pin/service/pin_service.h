#ifndef __PIN_SERVICE_H__
#define __PIN_SERVICE_H__

#include "request/pin_request.h"

enum pin_domain_service {
    PIN_DIRECTION,
    PIN_END
};

void set_pin_direction (struct _pin_request);

#endif // __PIN_SERVICE_H__
