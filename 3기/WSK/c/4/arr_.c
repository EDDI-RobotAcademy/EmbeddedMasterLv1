#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DICE_NUM	3
#define PLAYER_NUM	2

// 주사위를 3개 굴릴 수 있도록 만든다
// 처음 2개의 주사위의 합이 짝수가 나온다면
// 마지막 주사위를 1개 굴릴 수 있다.
// 또한 마지막 주사위는 특수 스킬을 가지고 있다.
// 3을 뽑으면 상대편에서 3을 스틸해서 자신에게 더할 수 있다.
// 4를 뽑으면 그냥 죽는다.

// 1. 주사위를 굴리는 함수
// 2. 짝수 판정하는 함수
// 3. 마지막 주사위를 굴릴 수 있는지 판정하는 함수
// 4. 주사위 게임 전체를 관장하는 함수
// 5. 마지막 주사위에 대한 스킬 판정하는 함수

int roll_dice (int min, int max)
{
	int range = max - min + 1;

	return rand() % range + min;
}

bool isEven (int num)
{
	return num % 2 == 0;
}

void operate_dice_skill(int dice_arr[PLAYER_NUM][DICE_NUM])
{
	int i,j;

	// 스킬이 적용되는 주사위는 맨 마지막 주사위에 적용하도록 하자!
	for (i = 0; i < PLAYER_NUM; i++)
	{
		switch(dice_arr[i][DICE_NUM - 1])
		{
			case 3:
				for(i = 0; j < PLAYER_NUM; j++)
				{
					if(i == j)
					{
						continue;
					}

					dice_arr[i][DICE_NUM - 1] += 3;
					dice_arr[j][DICE_NUM - 1] -= 3;
				break;
			case 4:
				break;
		}


bool decision_death (int dice_arr[PLAYER_NUM][DICE_NUM])
{
	int i;

bool isNotTwoDiceEven (int arr[PLAYER_NUM][DICE_NUM], int location)
{
	int i, sum = 0;
	const int CHECK_NUM = 2;

	for (i = 0; i < CHECK_NUM; i++)
	{
		sum += arr[location][i];
	}

	return isEven(sum);
}

// 상대방이 있다는 것을 유의해야 함
void game_start (void)
{
	int i, j;
	int dice_arr[PLAYER_NUM][DICE_NUM] = { 0 };
	const int MIN = 1;
	const int MAX = 6;

	for (i = 0; i <PLAYER_NUM; i++)
	{
		for (j = 0; j < DICE_NUM; j++)
		{
			if(j > 1 && isNotTwoDiceEven())
			{
				continue;
			}

			dice_arr[i][j] = roll_dice(MIN, MAX);
		}	
	}

	operate_dice_skill(dice_arr);
	decision_winner
}
int main(void)
{
	int i;
	const int MAX = 10;

	srand(time(NULL));

	for (i = 0; i < MAX; i++)
	{
		printf("주사위 값 = %d\n", roll_dice(1, 6));
	}

	return 0;
}

