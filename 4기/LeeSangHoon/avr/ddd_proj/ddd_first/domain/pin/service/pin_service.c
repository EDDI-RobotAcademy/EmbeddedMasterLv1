#include "pin_service.h"
#include "../repository/pin_repository_table.h"

void set_pin_direction (struct _pin_request pin_request)
{
    pin_repository_call_table[SET_DIRECTION](pin_request);
    //pin_request.hw_pin_address = pin_request.shifted_value;
}
