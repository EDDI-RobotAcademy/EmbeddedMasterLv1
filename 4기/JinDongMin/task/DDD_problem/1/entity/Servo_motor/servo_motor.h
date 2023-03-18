#ifndef __SERVO_MOTOR_H__
#define __SERVO_MOTOR_H__

#define MIN_SPEED_OF_SERVO_MOTOR 500
#define MAX_SPEED_OF_SERVO_MOTOR 2500

typedef struct _servo_motor servo_motor;

struct _servo_motor
{
    int speed;
};

void initialize_servo_motor(servo_motor *);
void control_servo_motor(servo_motor *, int);
int get_servo_motor_speed(const servo_motor);

#endif // __SERVO_MOTOR_H__