#ifndef __PIN_CONTROL_FORM_H__
#define __PIN_CONTROL_FORM_H__

#include "../pin_map.h"
#include "../service/request/pin_request.h"

struct _pin_control_form
{
    enum _PIN_MAP pin_number;
    enum _PIN_OPS_MODE pin_io_direction;
};

struct _pin_control_form pin_control_form;

void set_pin_control_form(enum _PIN_MAP, enum _PIN_OPS_MODE);
struct _pin_request convert_pin_control_data (struct _pin_control_form);

#endif // __PIN_CONTROL_FORM_H__
