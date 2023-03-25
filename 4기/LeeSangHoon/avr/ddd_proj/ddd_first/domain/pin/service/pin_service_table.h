#ifndef __PIN_SERVICE_TABLE_H__
#define __PIN_SERVICE_TABLE_H__

#include "pin_service.h"

typedef void (* pin_service_call_ptr_t) (struct _pin_request);

const pin_service_call_ptr_t pin_service_call_table[] = {
    set_pin_direction
};

#endif // __PIN_SERVICE_TABLE_H__
