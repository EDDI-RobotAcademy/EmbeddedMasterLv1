#include "../entity/wifi_receive.h"
#include "data_transfer_object/wifi_receive_data_transfer_object.h"
#include "../../common/utility/common.h"
#include "../../dc_motor/entity/dc_motor_control_data.h"

void wifi_data_scale2dc_motor (void)
{
#if 0
    int range;
    int direction = wifi_receive_dto.sub_order;

    if (direction == CLOCK_WISE)
    {
        range = DC_MOTOR_GEAR_MAX - DC_MOTOR_GEAR_MIN;
        // TODO: 별도의 DTO를 추가하는게 더 좋음
        scale_info2dc_motor(direction, range, wifi_receive_dto.channel_data - RF_MIDDLE);
    }
    else if (direction == COUNTER_CLOCK_WISE)
    {
        range = RF_MIDDLE - RF_MIN;
        scale_info2dc_motor(direction, range, wifi_receive_dto.channel_data - RF_MIN);
    }
#endif
}