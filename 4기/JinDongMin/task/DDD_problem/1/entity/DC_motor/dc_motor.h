#ifndef __DC_MOTOR_H__
#define __DC_MOTOR_H__

#define MIN_SPEED_OF_DC_MOTOR   0
#define MAX_SPEED_OF_DC_MOTOR   255

typedef struct _dc_motor dc_motor;

struct _dc_motor
{
    int speed;
};

void initialize_dc_motor(dc_motor *);
void control_dc_motor(dc_motor *, int);
int get_dc_motor_speed(const dc_motor);


#endif // __DC_MOTOR_H__