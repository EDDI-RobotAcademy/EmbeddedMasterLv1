#include <stdio.h>
#include <stdlib.h>


#include "dto.h"
#include "../../entity/receive/rf_receive.h"

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

