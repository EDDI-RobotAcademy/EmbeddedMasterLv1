#ifndef __PERIPHERAL_TABLE_H__
#define __PERIPHERAL_TABLE_H__

#include "common.h"
#include "../led/service/led_control.h"

typedef void (* peripheral_call_ptr_t)(void *);

const pheripheral_call_ptr_t pheripheral_call_table[PERIPHERAL_END] = {
    (peripheral_call_ptr_t const) turn_on_led,
    (peripheral_call_ptr_t const) turn_off_led,
    (peripheral_call_ptr_t const) toggle_led
};

#endif // __PERIPHERAL_TABLE_H__
