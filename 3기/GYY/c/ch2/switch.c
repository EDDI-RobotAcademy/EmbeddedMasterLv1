#include <stdio.h>

#include <time.h>

#include <stdlib.h>
#include <stdbool.h>

#define	ZERO	0

#define	ONE	1
#define	TWO	2
int main(void)
{
	int num;
	bool loop = true;

	//난수 생성기를 레알 랜덤으로 만들어줌
	srand(time(NULL));// 반드시 이 형식으로 
	
	while(loop)
	{	//1~100까지의 랜덤한 숫자
		num = rand() % 100 + 1;

		switch(num%3)
		{
			case ZERO:
				printf("ZERO\tnum=%d\n",num);
			break;

			case ONE:
			
				printf("ONE\tnum=%d\n",num);
			break;

			case TWO:

				printf("게임이 종료되었습니다.\n");
				loop = false;
			break;
		}
	}

	return 0;
}
