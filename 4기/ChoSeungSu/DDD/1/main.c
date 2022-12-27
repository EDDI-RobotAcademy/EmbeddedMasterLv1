#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define CHANNEL_MAX     8

#define RF_MAX             1400
#define RF_MIN             600
#define DC_MAX             255
#define DC_MIN             0
#define SERVO_MAX          2500
#define SERVO_MIN          500

#define LED_THRESHOLD 1000
#define LED_ON        1
#define LED_OFF       0

typedef struct _rf_recevie_object
{
    int channel;
    int data;              // void * 로 받고 data type에 따라 변경하도록 설계하면 확장가능성이 높아질것임 .
} rf_receive_object;


typedef enum _CHANNEL {
    RIGHT_DC_MOTOR,
    LEFT_DC_MOTOR,
    SERVO_MOTOR,
    LED1,
    LED2,
    LED3,
    LED4,
    LED5
} CHANNEL;


int init_rf_random_data(void)
{
    srand(time(NULL));
    return rand() % (RF_MAX - RF_MIN + 1) + RF_MIN ;
}

int init_rf_random_channel(void)
{
    srand(time(NULL));    
    return rand() % CHANNEL_MAX;
}

void receive_rf_signal(rf_receive_object * rf_module)
{
    rf_module->data = init_rf_random_data();
    rf_module->channel = init_rf_random_channel();
}

void convert_rf_data(rf_receive_object * rf_module)
{
    CHANNEL channel = rf_module->channel;
    int data = rf_module ->data;
    switch (channel)
    {
    case RIGHT_DC_MOTOR:
        rf_module->data = dc_convert(data);
        break;
    case LEFT_DC_MOTOR:
        rf_module->data = dc_convert(data);
        break;
    case SERVO_MOTOR:
        rf_module->data = servo_convert(data);
        break;
    case LED1:
        rf_module->data = led_convert(data);
        break;
    case LED2:
        rf_module->data = led_convert(data);
        break;
    case LED3:
        rf_module->data = led_convert(data);
        break;
    case LED4:
        rf_module->data = led_convert(data);
        break;
    case LED5:
        rf_module->data = led_convert(data);
        break;
    default:
        printf("Error");
        break;
    }
}

int dc_convert (int rf_data)
{
    int rf_range = RF_MAX - RF_MIN;
    int dc_range = DC_MAX - DC_MIN;
    int scale_factor = dc_range /rf_range;

    float target = (rf_data - RF_MIN) * scale_factor ;
    int result =(int)target;
    return result;
}

int servo_convert (int rf_data)
{
    int rf_range = RF_MAX - RF_MIN;
    int servo_range = SERVO_MAX - SERVO_MIN;
    int scale_factor = servo_range /rf_range;

    float target = (rf_data - RF_MIN) * scale_factor + 500;
    int result =(int)target;
    return result;
}

int led_convert (int rf_data)
{
    if (rf_data >= LED_THRESHOLD)  {return LED_ON;}
    else if (rf_data < LED_THRESHOLD) {return LED_OFF;}
}

void print_convert_data(rf_receive_object * rf_module)
{
    CHANNEL channel = rf_module->channel;
    int data = rf_module ->data;
    printf("channel : %d\n",channel);
    printf("data : %d\n" , data);
}


int main()
{
    rf_receive_object rf_module;
    rf_receive_object * ptr ;
    ptr = &rf_module;

    int i ;
    for(i = 0 ; i <3 ; i ++)
    {   
        receive_rf_signal(ptr);
        convert_rf_data(ptr);
        print_convert_data(ptr);
    }

    return 0;
}
