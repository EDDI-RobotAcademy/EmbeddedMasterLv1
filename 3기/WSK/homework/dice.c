#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int com_dice, user_dice;

	srand(time(NULL));

	com_dice = rand() % 6 + 1;
	user_dice = rand() % 6 + 1;

	printf("컴퓨터의 주사위 결과 : %d\n", com_dice);
	printf("사용자의 주사위 결과 : %d\n", user_dice);

	if(com_dice > user_dice)
		printf("컴퓨터 승\n");
	else if(com_dice < user_dice)
		printf("사용자 승\n");
	else
		printf("비겼습니다.\n");

	return 0;
}

