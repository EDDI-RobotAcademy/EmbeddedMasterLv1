#include "../led/Common/common.h"
#include "../led/Entity/led.h"
#include "../led/Service/pin.h"
#include "../led/Repository/avr.h"
#include <unistd.h>

led_object led_obj; // global led_obj

pin led_pin; // global led_pin 

pin avr_pin; // global avr_pin

int main(void)
{
    pin_direction(led_pin, DDRB);
    pin_direction(avr_pin, PORTB);

    while(1)
    {
        blink_led(& led_obj);

        set_pin_data(led_pin, 0x20); //0x20 is DDB5 

        if (led_obj.status == LED_OFF)
        {
            set_pin_data(avr_pin, 0x00); 
        }
        else if (led_obj.status == LED_ON)
        {
            set_pin_data(avr_pin, 0x20); //0x20 os PORTB5
        }

        sleep(1); //delay 1 sec 
        
    }


    return 0;
}