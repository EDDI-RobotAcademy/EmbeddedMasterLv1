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

	// 고정 랜덤이 아닌 계속 값이 바뀌는 랜덤
	srand(time(NULL));
	// for로 무한 루프 만들기 (조건이 없으니 무조건)
	// 리눅스에서는 차이 없음, 윈도우는 for(;;)가 1 clock더 빠름
	for (; i < 10; i++)
	{
		// rand()는 랜덤값을 만드는 라이브러리
		rand_num = rand() % (MAX - MIN + 1) + MIN;
		// switch 문을 작성하는 방법
		// 1. switch를 작성하고 괄호를 열고 닫고 중괄호를 열고 닫는다.
		// 2. 괄호 내부에 switch 조건으로 사용할 변수를 배치한다.
		// 3. case에 특정 조건에 해당하는 값을 아래와 같이 적어준다.
		// 4. case 아래쪽에 해당 조건에서 동작할 코드를 작성한다.
		// 5. case를 끝낼때 break 키워드를 작성해줍니다.
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
