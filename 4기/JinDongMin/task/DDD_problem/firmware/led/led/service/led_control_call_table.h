#ifndef __LED_CONTROL_CALL_TABLE_H__
#define __LED_CONTROL_CALL_TABLE_H__

#include "led_control.h"

#define CALL_BUFFER_COUNT   (LED_CONTROL_END)

typedef void (* led_control_call_ptr_t) (led_object *);

const led_control_call_ptr_t led_control_call_table[CALL_BUFFER_COUNT] = {
    (led_control_call_ptr_t const) led_turn_on,
    (led_control_call_ptr_t const) led_turn_off,
    (led_control_call_ptr_t const) led_toggle
};

#endif // __LED_CONTROL_CALL_TABLE_H__
