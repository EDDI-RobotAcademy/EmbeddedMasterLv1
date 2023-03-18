#ifndef __LED_H__
#define __LED_H__

#include "../Common/common.h"


typedef struct _led_object
{
    uint8_t status  : 1 ;

} led_object ;

typedef enum
{
    LED_ON = 0,
    LED_OFF = 1

}LED_STATUS;


void blink_led(led_object * led_obj_ptr);


#endif 

