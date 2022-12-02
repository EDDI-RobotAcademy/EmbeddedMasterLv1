#ifndef ASSEMBLYTEST_DEVICE_H
#define ASSEMBLYTEST_DEVICE_H

void proc_camera (void);
int proc_dc_motor (void);
float proc_bldc (void);
void proc_pmsm (void);
void proc_acim (void);
void proc_led (void *);
void proc_i2c (void);
void proc_spi (void);
void proc_can (void);
void proc_ecap (void);

#endif //ASSEMBLYTEST_DEVICE_H
