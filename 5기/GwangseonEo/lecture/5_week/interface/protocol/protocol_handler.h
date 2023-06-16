#ifndef __PROTOCOL_HANDLER_H__
#define __PROTOCOL_HANDLER_H__

void proc_camera (void);
void proc_dc_motor (void);
void proc_bldc_motor (void);
void proc_pmsm_motor (void);
void proc_acim_motor (void);
void proc_power_led (void);
void proc_i2c (void);
void proc_spi (void);
void proc_lidar (void);
void proc_can (void);
void proc_ecap (void);

#endif