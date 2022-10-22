#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN		5
#define MAX		10

#define CAMERA		5
#define LIDAR		6
#define RADAR		7
#define STEERING	8
#define BLDC		9
#define ULTRASONIC	10

int main(void)
{
	int rand_num, i;

	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		rand_num = rand() % (MAX - MIN + 1) + MIN;
		
		switch (rand_num)
		{
			case CAMERA:
				printf("Camera 처리 함수 동작!\n");
				break;

			case LIDAR:
				printf("Lidar 처리 함수 동작!\n");
				break;

			case RADAR:
				printf("Radar 처리 함수 동작!\n");
				break;

			case STEERING:
				printf("Steering 처리 함수 동작!\n");
				break;

			case BLDC:
				printf("BLDC 처리 함수 동작!\n");
				break;

			case ULTRASONIC:
				printf("UltraSonic 처리 함수 동작!\n");
				break;

			default:
				printf("그런거 없어요!\n");
		}
	}

	return 0;
}
