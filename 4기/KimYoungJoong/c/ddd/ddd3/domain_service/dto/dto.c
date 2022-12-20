#include <stdio.h>
#include <stdlib.h>


#include "dto.h"
#include "../../entity/receive/rf_receive.h"

void servo_data_trans_object(int comm, int ch)
{
    //dto_data = (data_trans_object*)malloc(sizeof(data_trans_object));
    if(comm == RF)
    {
        dto_data->servo = 2.5 * rf_receive_object_data[ch].data - 1000;
        printf("RF CH%d  servo motor : %02f\n",ch,  dto_data[ch].servo);
    }

}

