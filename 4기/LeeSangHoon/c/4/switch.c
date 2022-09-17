#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#include "spi_interface.h"

#define MIN				5
#define MAX				10

#define CAMERA			5
#define LIDAR			6
#define RADAR			7
#define STEERING		8
#define BLDC			9
#define ULTRASONIC		10

int main(void)
{
	int rand_num, i = 0;

	srand(time(NULL));
	// for로 무한 루프 만들기 (조건이 없으니 무조건)
	// 리눅스에서는 차이 없음, 윈도우는 for(;;)가 1 clock더 빠름
	for (; i < 10; i++)
	{
		rand_num = rand() % (MAX - MIN + 1) + MIN;
		switch(rand_num)
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
