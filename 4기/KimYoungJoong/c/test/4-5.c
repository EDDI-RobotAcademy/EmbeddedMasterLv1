/*
헬스케어를 위한 나노 장치를 부착한 사람들이 있다.

​

4. 이 장치는 심장 박동수, 무게중심의 속도(x, y, z) 및 가속도를 측정한다고 가정한다.

​

5. 심장 박동수가 약간 증가하고 무게중심 속도가 일정하며 가속도는 초기에 발생하였다 사라졌다.

   사용자가 어떤 운동을 하고 있는지 판정할 수 있겠는가 ?

*/
//수정 필요
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SPEED_MIM   0
#define SPEED_MAX   10

#define ACCELERATION_MIM   -5
#define ACCELERATION_MAX   5



typedef struct _axis_speed axis_speed;
struct _axis_speed
{
    int x;
    int y;
    int z;
};

typedef struct _axis_acceleratioon_speed axis_acceleratioon_speed;
struct _axis_acceleratioon_speed
{
    int x;
    int y;
    int z;
};

typedef struct _health_Care_Sensor healthcare_sensor;
struct _health_Care_Sensor
{
    axis_speed *speed;
    axis_acceleratioon_speed *acceleratioon_speed;
};
 
healthcare_sensor *intit_healthcare_sensor (void)
{
    healthcare_sensor *tmp = (healthcare_sensor *)malloc(sizeof(healthcare_sensor));
    tmp->speed = (axis_speed *)malloc(sizeof(axis_speed));
    tmp->acceleratioon_speed = (axis_acceleratioon_speed *)malloc(sizeof(axis_acceleratioon_speed));

    return tmp;
}

int custom_random(int min, int max)
{
    return rand() % (max - min +1) + min;
}

void print_sensor_data (healthcare_sensor *sensor)
{
	printf("speed x = %d\n", sensor->speed->x);
	printf("speed y = %d\n", sensor->speed->y);
	printf("speed z = %d\n", sensor->speed->z);

	printf("acceleration x = %d\n", sensor->acceleratioon_speed->x);
	printf("acceleration y = %d\n", sensor->acceleratioon_speed->y);
	printf("acceleration z = %d\n", sensor->acceleratioon_speed->z);
}


healthcare_sensor *get_sensor_data(healthcare_sensor *sensor)
{
    sensor->speed->x = custom_random(SPEED_MIM, SPEED_MAX);
    sensor->speed->y = custom_random(SPEED_MIM, SPEED_MAX);
    sensor->speed->z = custom_random(SPEED_MIM, SPEED_MAX);

    sensor->acceleratioon_speed->x = custom_random(ACCELERATION_MIM, ACCELERATION_MAX);
    sensor->acceleratioon_speed->y = custom_random(ACCELERATION_MIM, ACCELERATION_MAX);
    sensor->acceleratioon_speed->z = custom_random(ACCELERATION_MIM, ACCELERATION_MAX);
    return sensor;
}

int main (void)
{

    healthcare_sensor *sensor;

    printf("Health Care program start\n");
    srand(time(NULL));
    sensor = intit_healthcare_sensor();
    sensor = get_sensor_data(sensor);
    print_sensor_data(sensor);


    return 0;

}
