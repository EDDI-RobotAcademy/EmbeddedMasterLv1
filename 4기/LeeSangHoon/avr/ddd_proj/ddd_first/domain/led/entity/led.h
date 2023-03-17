#ifndef __LED_H__
#define __LED_H__

#include "../../utility/avr_pin.h"

#include <stdint.h>

typedef enum _LED_STATUS LED_STATUS;
enum _LED_STATUS
{
    LED_STATUS_ON = 0,
    LED_STATUS_OFF,
    LED_STATUS_PWM,
    END
};

typedef struct _led led;
struct _led
{
    uint8_t pin;
    uint8_t status;
};

led led_entity;

void led_entity_init (PIN_MAP pin, LED_STATUS status);
LED_STATUS get_led_status (void);
void set_led_status (LED_STATUS status);
PIN_MAP get_led_pin (void);

#endif // __LED_H__
