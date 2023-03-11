#include "pin.h"

void init_pin(pin *pin_ptr, const uint8_t *potr_reg_ptr, int bit_num)
{
    pin_ptr->port_register_ptr = potr_reg_ptr;
    pin_ptr->bit_number = bit_num;
}
