#include "pin_repository.h"

void set_direction (struct _pin_request pin_request)
{
    *pin_request.hw_pin_address = pin_request.shifted_value;
}
