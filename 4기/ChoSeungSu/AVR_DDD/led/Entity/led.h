
#define LED_OFF 0
#define LED_ON 1

typedef struct _led_object
{
    const char status;
    const char pin;

} led_object ;

led_object * init_led(void);


