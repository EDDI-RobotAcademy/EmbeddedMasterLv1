#ifndef __PROTOCOL_CALL_TABLE_MAPPER_H__
#define __PROTOCOL_CALL_TABLE_MAPPER_H__ 

#include "protocol_handler.h"
// 핸들러들 mapping 할것임
#define __PROTOCOL_CALL_TABLE(nr, sym) [nr] = sym,
// linux kernel에서 많이 쓰는 기법
// CALL TABLE의 nr(vector table 번호), sym(심볼)
// nr과 sym이 들어오면 [nr] 이 해당 sym에 해당 된다.
// nr sym이 들어왔을 때 이 배열은 뭐다 라는게 쭉 함수 밑으로 배치가 됨.

__PROTOCOL_CALL_TABLE(0, proc_camera)
__PROTOCOL_CALL_TABLE(1, proc_dc_motor)
__PROTOCOL_CALL_TABLE(2, proc_bldc_motor)
__PROTOCOL_CALL_TABLE(3, proc_pmsm_motor)
__PROTOCOL_CALL_TABLE(4, proc_acim_motor)
__PROTOCOL_CALL_TABLE(5, proc_power_led)
__PROTOCOL_CALL_TABLE(6, proc_i2c)
__PROTOCOL_CALL_TABLE(7, proc_spi)
__PROTOCOL_CALL_TABLE(8, proc_lidar)
__PROTOCOL_CALL_TABLE(9, proc_can)
__PROTOCOL_CALL_TABLE(10, proc_ecap)

// handler 쪽에 구현체가 있어야함.


#endif