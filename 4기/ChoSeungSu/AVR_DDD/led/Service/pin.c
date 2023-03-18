#include "pin.h"

// pin init_pin(void)
// {
//     pin led_pin;

//     led_pin.direction = 0x00; // inital pin address 

//     return led_pin; 
// }

void pin_direction(pin led_pin, uint8_t pin_addr)
{
    led_pin.direction = pin_addr;
}

