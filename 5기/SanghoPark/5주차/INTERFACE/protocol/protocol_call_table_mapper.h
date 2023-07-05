#ifndef __PROTOCOL_CALL_TABLE_MAPPER_H__
#define __PROTOCOL_CALL_TABLE_MAPPER_H__

#include "protocol_handler.h"

#define __PROTOCOL_CALL_TABLE(nr, sym) [nr] = sym,

__PROTOCOL_CALL_TABLE(CAMERA, proc_camera)
__PROTOCOL_CALL_TABLE(DC_MOTOR, proc_dc_motor)
__PROTOCOL_CALL_TABLE(BLDC_MOTOR, proc_bldc_motor)
__PROTOCOL_CALL_TABLE(PMSM_MOTOR, proc_pmsm_motor)
__PROTOCOL_CALL_TABLE(ACIM_MOTOR, proc_acim_motor)
__PROTOCOL_CALL_TABLE(POWER_LED, proc_power_led)
__PROTOCOL_CALL_TABLE(I2C, proc_i2c)
__PROTOCOL_CALL_TABLE(SPI, proc_spi)
__PROTOCOL_CALL_TABLE(LIDAR, proc_lidar)
__PROTOCOL_CALL_TABLE(CAN, proc_can)
__PROTOCOL_CALL_TABLE(ECAP, proc_ecap)

#endif