#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

enum protocol
{
    CAMERA,
    DC_MOTOR,
    BLDC_MOTOR,
    PMSM_MOTOR,
    ACIM_MOTOR,
    POWER_LED,
    I2C,
    SPI,
    LIDAR,
    CAN,
    ECAP,
    END
};

#define PROTOCOL_CALL_BUFFER_COUNT          (END)
#define PROTOCOL_CALL_BUFFER                ((END) - 1)

#endif