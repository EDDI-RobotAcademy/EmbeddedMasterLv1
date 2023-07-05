#ifndef __PROTOCOL_HANDLER_H__
#define __PROTOCOL_HANDLER_H__

void proc_camera(void *p);
void proc_dc_motor(void *p);
void proc_bldc_motor(void *p);
void proc_pmsm_motor(void *p);
void proc_acim_motor(void *p);
void proc_power_led(void *p);
void proc_i2c(void *p);
void proc_spi(void *p);
void proc_lidar(void *p);
void proc_can(void *p);
void proc_ecap(void *p);


#endif
