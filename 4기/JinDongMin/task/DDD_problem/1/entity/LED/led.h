#ifndef __LED_H__
#define __LED_H__

#include <stdbool.h>

#define TURN_ON     true
#define TURN_OFF    false

typedef struct _led led;

struct _led
{
    bool status;
};

void initialize_led(led *);
void set_led_status(led *, bool);
bool get_led_status(const led);

#endif // __LED_H__