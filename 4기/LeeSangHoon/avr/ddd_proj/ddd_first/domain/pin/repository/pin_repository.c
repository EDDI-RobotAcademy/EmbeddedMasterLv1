#include "pin_repository.h"

void set_direction (struct _pin_request pin_request)
{
    (* (volatile unsigned char *)pin_request.hw_pin_address) = pin_request.shifted_value;
    //asm volatile (" " : : : "memory");
}
