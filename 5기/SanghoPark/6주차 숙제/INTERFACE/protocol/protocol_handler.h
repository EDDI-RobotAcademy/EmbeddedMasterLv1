#ifndef __PROTOCOL_HANDLER_H__
#define __PROTOCOL_HANDLER_H__

void proc_camera (void* pCamera);
void proc_dc_motor (void* pDcMotor);
void proc_bldc_motor (void* pBldcMotor);
void proc_pmsm_motor (void* pPmsmMotor);
void proc_acim_motor (void* pAcimMotor);
void proc_power_led (void* pPowerLed);
void proc_i2c (void* pI2c);
void proc_spi (void* pSpi);
void proc_lidar (void* pLidar);
void proc_can (void* pCan);
void proc_ecap (void* pEcap);

#endif