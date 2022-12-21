#include <stdio.h>
#include <stdlib.h>


#include "dto.h"
#include "../../entity/receive/rf_receive.h"


void led_status_printf (int led_status, int ch)
{
    //printf("led_status :%d\n", led_status);
    //printf("led_status_printf in\n");
    switch(led_status)
    {
        case LED_STATUS_ON:
            printf("rf ch%d, led ON\n", ch);
            break;

        case LED_STATUS_OFF:
            printf("rf ch%d, led OFF\n", ch);
            break;

        case LED_STATUS_KEEP:
            if(dto_data->led_status == LED_STATUS_ON)   { printf("rf ch%d, led ON\n", ch); }
            else if(dto_data->led_status == LED_STATUS_ON)   { printf("rf ch%d, led OFF\n", ch); }
            break;

        default:
            printf("default\n");
            break;
    }
}


void servo_data_trans_object(int comm, int ch)
{
    if(comm == RF)
    {
        dto_data->servo = 2.5 * rf_receive_object_data[ch].data - 1000;
        printf("RF CH%d servo motor : %.2f\n",ch, dto_data->servo);
    }
    else if(comm == WIFI)
    {

    }

    else if(comm == UART)
    {

    }

    else if(comm == BLUE_TOOTH)
    {

    }

}

void dc_motor_data_trans_object(int comm, int ch, int sub_order)
{
    if(comm == RF)
    {
        dto_data->dc_motor = 0.3188 * rf_receive_object_data[ch].data - 191.25;
        dto_data->dc_motor_sub_order = sub_order;

        printf("RF CH%d dc motor : %.2f\n",ch, dto_data->dc_motor);
        if(dto_data->dc_motor_sub_order == 1)
        {
            printf("RF CH%d dc motor sub order : ON\n", ch);
        }
        else if(dto_data->dc_motor_sub_order == 0)
        {
            printf("RF CH%d dc motor sub order : OFF\n", ch);
        }
        
        
    }

    else if(comm == WIFI)
    {

    }

    else if(comm == UART)
    {

    }

    else if(comm == BLUE_TOOTH)
    {

    }

}

void led_data_trans_object(int comm, int ch)
{
    //printf("led_data_trans_object in\n");
    if(comm == RF)
    {
        dto_data->led = rf_receive_object_data[ch].data;
        //printf("dto_data->led :%d\n", dto_data->led);
        //printf("rf_receive_object_data[ch].data :%d\n", rf_receive_object_data[ch].data);
        if(dto_data->led >= 1200)
        {
            //printf("led 1200 up in\n");
            dto_data->led_status = LED_STATUS_ON;
            led_status_printf(dto_data->led_status, ch);
        }
        else if(dto_data->led <= 800)
        {
            //printf("led 800 down in\n");
            dto_data->led_status = LED_STATUS_OFF;
            led_status_printf(dto_data->led_status, ch);
        }
        else if( (dto_data->led_status > 800) && (dto_data->led_status < 1200) )
        {
            //printf("led 1200 down 800 up in\n");
            dto_data->led_status = LED_STATUS_KEEP;
            led_status_printf(dto_data->led_status, ch);
        }
    }

    else if(comm == WIFI)
    {

    }

    else if(comm == UART)
    {

    }

    else if(comm == BLUE_TOOTH)
    {

    }
}

