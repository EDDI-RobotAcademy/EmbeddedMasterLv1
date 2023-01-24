#include "led.h"

void set_led_status(led *_led, bool _status)
{
    _led->status = _status;
}

bool get_led_status(const led _led)
{
    return _led.status;
}