#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Heart_Min  0
#define Heart_Max  255
#define Velocity_Min  -10 // m/s
#define Velocity_Max  10 // m/s 
#define Accel_Min  5 // m/s^
#define Accel_Max  -5 // m/s^ 

typedef struct center_of_gravity_velocity
{
    int x;
    int y;
    int z;

} velocity;

typedef struct center_of_gravity_acceleration
{
    int x;
    int y;
    int z;

} acceleration;

typedef struct health_care_nano_sensor
{
    unsigned char heart;
    velocity * vel;
    acceleration * accel;

} sensor;

sensor * Init_sensor (void)
{
    sensor * init = (sensor *)malloc(sizeof(sensor));
    init -> vel = (velocity *)malloc(sizeof(velocity));
    init -> accel = (acceleration *)malloc(sizeof(acceleration));

    return init;
}

int Custom_rand(int min, int max)
{
    return rand() % (max - min + 1) + min; // 최소값, 최대값 사이 범위 만드는 공식
}


sensor * Get_data_sensor (sensor * sensor)
{   
    sensor -> heart = Custom_rand(Heart_Min, Heart_Max);

    sensor -> vel -> x = Custom_rand(Velocity_Min, Velocity_Max);
    sensor -> vel -> y = Custom_rand(Velocity_Min, Velocity_Max);
    sensor -> vel -> z = Custom_rand(Velocity_Min, Velocity_Max);

    sensor -> accel -> x = Custom_rand(Accel_Min, Accel_Max);
    sensor -> accel -> y = Custom_rand(Accel_Min, Accel_Max);
    sensor -> accel -> z = Custom_rand(Accel_Min, Accel_Max);

    return sensor; 
}

void print_sensor_data (sensor *sensor)
{
    printf("herat = %d\n", sensor -> heart);

	printf("velocity x = %d\n", sensor->vel->x);
	printf("velocity y = %d\n", sensor->vel->y);
	printf("velocity z = %d\n", sensor->vel->z);


	printf("acceleration x = %d\n", sensor->accel->x);
	printf("acceleration y = %d\n", sensor->accel->y);
	printf("acceleration z = %d\n", sensor->accel->z);

}


int main()
{
    sensor * sensor;

    srand(time(NULL));

    sensor = Init_sensor();

    sensor = Get_data_sensor(sensor);

    print_sensor_data(sensor);

}

