#include "../../entity/radio_frequency/rf_receiver.h"
#include "data_transfer_object/rf_receive_data_transfer_object.h"
#include "rf_receive_data_scale.h"
#include "../../common/common.h"

int check_dc_motor_direction()
{
    if (rf_receive_dto.channel_data > 1020)
    {
        rf_receive_dto.channel_sub_order = CLOCK_WISE;
    }
    else if (rf_receive_dto.channel_data < 980)
    {
        rf_receive_dto.channel_sub_order = COUNTER_CLOCK_WISE;
    }
    else
    {
        rf_receive_dto.channel_sub_order = STOP;
    }

    return rf_receive_dto.channel_sub_order;
}

void rf_signal_scale2dc_motor (void)
{
    int range;
    int direction = check_dc_motor_direction();

    if (direction == CLOCK_WISE)
    {
        range = RF_MAX - RF_MIDDLE;
        // TODO: 별도의 DTO를 추가하는게 더 좋음
        scale_info2dc_motor(direction, range, rf_receive_dto.channel_data - RF_MIDDLE);
    }
    else if (direction == COUNTER_CLOCK_WISE)
    {
        range = RF_MIDDLE - RF_MIN;
        counter_clock_wise_dc_motor_scale(direction, range, rf_receive_dto.channel_data - RF_MIN);
    }
}
