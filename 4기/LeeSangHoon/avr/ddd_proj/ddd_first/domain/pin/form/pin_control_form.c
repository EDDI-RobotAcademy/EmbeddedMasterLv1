#include "pin_control_form.h"
#include "../service/request/pin_request.h"
#include "../pin_map.h"
#include "../global_pin_map.h"

void set_pin_control_form(enum _PIN_MAP pin_number, enum _PIN_OPS_MODE pin_direction)
{
    pin_control_form.pin_number = pin_number;
    pin_control_form.pin_io_direction = pin_direction;
}

struct _pin_request convert_pin_control_data (struct _pin_control_form pin_control_form)
{
    // 07 - 000111
    // 15 - 001111
    // 23 - 010111
    // -----------
    //      000111
    //      011000 -> 24
    pin_request.hw_pin_address = pin_map_direction_vo[pin_control_form.pin_number >> 3];
    pin_request.shifted_value = 1 << (pin_control_form.pin_number & ~(24));

    return pin_request;
}
