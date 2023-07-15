#ifndef __PROTOCOL_CALL_TABLE_MAPPER_H__
#define __PROTOCOL_CALL_TABLE_MAPPER_H__

#include "protocol_handler.h"

#define __PROTOCOL_CALL_TABLE(nr, sym) [nr] = sym,

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

#endif