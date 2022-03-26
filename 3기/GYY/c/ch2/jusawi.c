#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int num;
	int mynum;
	srand(time(NULL));

	printf("당신의 주사위 숫자는 몇 입니까?\n");
	scanf("%d", &mynum);

	num=rand()%6+1;

	if(num>mynum)
	{
		printf("당신은 졌습니다.\n");
	}
	else if(num==mynum)
	{
		printf("비겼습니다.\n");
	}
	else
	{
		printf("당신이 이겼습니다.\n");
	}
return 0;
}
