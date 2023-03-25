#ifndef __LED_SERVICE_TABLE_H__
#define __LED_SERVICE_TABLE_H__

#include "led_service.h"

typedef void (* led_service_call_ptr_t) (struct _pin_request);

const led_service_call_ptr_t led_service_call_table[] = {
    led_on,
    led_off,
    led_toggle
};

#endif // __LED_SERVICE_TABLE_H__
