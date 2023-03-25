#ifndef __LED_CONTROL_FORM_H__
#define __LED_CONTROL_FORM_H__

#include "../entity/led.h"
#include "../../pin/service/request/pin_request.h"

struct _led_control_form
{
    enum _LED_STATUS led_status;
    // TODO: Convert data to led_request, pin_request
    /*
    enum _PIN_MAP pin_number;
    enum _PIN_OPS_MODE pin_io_direction;
    */
};

struct _led_control_form led_control_form;

void set_led_control_form(enum _LED_STATUS);
struct _pin_request convert_led_control_data (struct _led_control_form);

#endif // __LED_CONTROL_FORM_H__
