#include "led_control_form.h"
#include "../../pin/global_pin_map.h"
#include "../../pin/form/pin_control_form.h"

void set_led_control_form(enum _LED_STATUS status)
{
    led_control_form.led_status = status;
}

// struct _pin_request led_port_request
struct _pin_request convert_led_control_data (struct _led_control_form led_control_form)
{
    led_port_request.hw_pin_address = pin_map_port_vo[pin_control_form.pin_number >> 3];
    led_port_request.shifted_value =
        led_control_form.led_status << (pin_control_form.pin_number & ~(24));
    //volatile unsigned char *hw_pin_address;
    //uint8_t shifted_value;

    return led_port_request;
}
