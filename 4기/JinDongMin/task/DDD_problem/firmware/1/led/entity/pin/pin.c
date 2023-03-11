#include "pin.h"

void init_pin(pin *pin_ptr, const uint8_t *port_reg_ptr, int bit_num)
{
    pin_ptr->port_register_ptr = port_reg_ptr;
    pin_ptr->bit_number = bit_num;

    change_pin_mode(pin_ptr, DEFAULT_PIN_MODE);
}

void change_pin_mode(pin *pin_ptr, int pin_mode)
{
    uint8_t *port_reg_ptr = pin_ptr->port_register_ptr;
    int bit_num = pin_ptr->bit_number;

    if (pin_mode == READ)
    {
        (*port_reg_ptr) &= ~(1 << bit_num);
    }
    else
    {
        (*port_reg_ptr) |= (1 << bit_num);
    }
}
