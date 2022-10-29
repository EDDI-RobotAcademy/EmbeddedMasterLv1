#if 0
헬스케어를 위한 나노 장치를 부착한 사람들이 있다.

4. 이 장치는 심장 박동수, 무게중심의 속도(x, y, z) 및 가속도를 측정한다고 가정한다.
5. 심장 박동수가 약간 증가하고 무게중심 속도가 일정하며 가속도는 초기에 발생하였다 사라졌다.
   사용자가 어떤 운동을 하고 있는지 판정할 수 있겠는가 ?
#endif

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define VELOCITY_MIN			-10
#define VELOCITY_MAX			10

#define ACCELERATION_MIN		-5
#define ACCELERATION_MAX		5

typedef struct _center_of_gravity_acceleration center_of_gravity_acceleration;
struct _center_of_gravity_acceleration
{
	int x;
	int y;
	int z;
};

typedef struct _center_of_gravity_velocity center_of_gravity_velocity;
struct _center_of_gravity_velocity
{
	int x;
	int y;
	int z;
};

typedef struct _healthcare_sensor healthcare_sensor;
struct _healthcare_sensor
{
	float heart_rate;
	center_of_gravity_velocity *velocity;
	center_of_gravity_acceleration *acceleration;
};

healthcare_sensor *init_healthcare_sensor (void)
{
	healthcare_sensor *tmp = (healthcare_sensor *)malloc(sizeof(healthcare_sensor));
	tmp->velocity = (center_of_gravity_velocity *)malloc(sizeof(center_of_gravity_velocity));
	tmp->acceleration = (center_of_gravity_acceleration *)malloc(sizeof(center_of_gravity_acceleration));

	return tmp;
}

int custom_random (int min, int max)
{
	return rand() % (max - min + 1) + min;
}

healthcare_sensor *get_sensor_data (healthcare_sensor *sensor)
{
	sensor->velocity->x = custom_random(VELOCITY_MIN, VELOCITY_MAX);
	sensor->velocity->y = custom_random(VELOCITY_MIN, VELOCITY_MAX);
	sensor->velocity->z = custom_random(VELOCITY_MIN, VELOCITY_MAX);

	sensor->acceleration->x = custom_random(ACCELERATION_MIN, ACCELERATION_MAX);
	sensor->acceleration->y = custom_random(ACCELERATION_MIN, ACCELERATION_MAX);
	sensor->acceleration->z = custom_random(ACCELERATION_MIN, ACCELERATION_MAX);

	return sensor;
}

void print_sensor_data (healthcare_sensor *sensor)
{
	printf("velocity x = %d\n", sensor->velocity->x);
	printf("velocity y = %d\n", sensor->velocity->y);
	printf("velocity z = %d\n", sensor->velocity->z);

	printf("acceleration x = %d\n", sensor->acceleration->x);
	printf("acceleration y = %d\n", sensor->acceleration->y);
	printf("acceleration z = %d\n", sensor->acceleration->z);
}

int main (void)
{
	healthcare_sensor *sensor;

	srand(time(NULL));

	sensor = init_healthcare_sensor();
	sensor = get_sensor_data(sensor);
	print_sensor_data(sensor);

	printf("무게중심 속도가 일정하며 가속도가 초기에 발생하였다 사라졌다면\n" \
		"당신은 현재 런닝 머신 혹은 조깅을 하면서 등속 운동을 하고 있을 것입니다!\n");
}
