#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DICE_NUM			3
#define PLAYER_NUM			2

#define DEATH				(-4444)

int roll_dice (int min, int max)
{
	int range = max - min + 1;

	return rand() % range + min;
}

bool isEven (int num)
{
	return num % 2 == 0;
}

/*

	-------------------------
	|		|		|		|
	-------------------------
	|		|		|		|
	-------------------------
	|		|		|		|
	-------------------------
	|		|		|		|
	-------------------------
	|		|		|		|
	   ...     ...     ...

*/
bool isTwoDiceEven (int (* arr)[DICE_NUM], int location)
{
	int i, sum = 0;
	const int CHECK_NUM = 2;

	for (i = 0; i < CHECK_NUM; i++)
	{
		sum += arr[location][i];
	}

	return isEven(sum);
}

/*
       [0]     [1]     [2]
	-------------------------
	|		|		|		|   <--- dice_arr[0]
	-------------------------
	|		|		|		|   <--- dice_arr[1]
	-------------------------

*/
void operate_dice_skill (int (* dice_arr)[DICE_NUM])
{
	int i, j;

	for (i = 0; i < PLAYER_NUM; i++)
	{
		switch (dice_arr[i][DICE_NUM - 1])
		{
			case 3:
				printf("스틸을 시전합니다!\n");

				for (j = 0; j < PLAYER_NUM; j++)
				{
					if (i == j)
					{
						continue;
					}

					dice_arr[i][DICE_NUM - 1] += 3;
					dice_arr[j][DICE_NUM - 1] -= 3;
				}
				break;

			case 4:
				printf("죽어츱니다!\n");

				dice_arr[i][DICE_NUM - 1] = DEATH;
				break;
		}
	}
}

bool decision_death (int (* dice_arr)[DICE_NUM])
{
	int i;
	bool isDead = false;

	for (i = 0; i < PLAYER_NUM; i++)
	{
		if (dice_arr[i][DICE_NUM - 1] < -3)
		{
			printf("플레이어 %d님이 패배하셨습니다!\n", i);
			isDead = true;
		}
	}

	return isDead;
}

void decision_winner (int (* dice_arr)[DICE_NUM])
{
	int i, j;
	int dice_sum[PLAYER_NUM] = { 0 };

	if (!decision_death(dice_arr))
	{
		for (i = 0; i < PLAYER_NUM; i++)
		{
			for (j = 0; j < DICE_NUM; j++)
			{
				dice_sum[i] += dice_arr[i][j];
			}
		}

		if (dice_sum[0] > dice_sum[1])
		{
			printf("플레이어 0 승리!\n");
		}
		else if (dice_sum[0] < dice_sum[1])
		{
			printf("플레이어 1 승리!\n");
		}
		else
		{
			printf("무승부!\n");
		}
	}
}

void print_dice_arr(int (* dice_arr)[DICE_NUM])
{
	int i, j;

	for (i = 0; i < PLAYER_NUM; i++)
	{
		printf("플레이어%d: ", i);
		for (j = 0; j < DICE_NUM; j++)
		{
			printf("%6d", dice_arr[i][j]);
		}
		printf("\n");
	}
}

// dice_arr가 이중 배열이기 때문에
// 단순하게 int *로 처리할 경우
// 포인터 타입은 이 배열을 분석할 수 없게 된다.
// int (*)[DICE_NUM] vs int *

#if 0
void test_print_function(int *dice_arr)
{
	int i, j;

	for (i = 0; i < PLAYER_NUM; i++)
	{
		printf("플레이어%d: ", i);
		for (j = 0; j < DICE_NUM; j++)
		{
			printf("%6d", dice_arr[i][j]);
		}
		printf("\n");
	}
}

void test_print_function2(int *dice_arr)
{
	int i;

	for (i = 0; i < PLAYER_NUM; i++)
	{
		printf("addr = 0x%x, value = %6d\n", &dice_arr[i], dice_arr[i]);
	}
}

void test_print_function3(int *dice_arr)
{
	int i;

	for (i = 0; i < PLAYER_NUM * DICE_NUM; i++)
	{
		printf("addr = 0x%x, value = %6d\n", &dice_arr[i], dice_arr[i]);
	}
}
#endif

void game_start (void)
{
	int i, j;
	int dice_arr[PLAYER_NUM][DICE_NUM] = { 0 };

	const int MIN = 1;
	const int MAX = 6;

	for (i = 0; i < PLAYER_NUM; i++)
	{
		for (j = 0; j < DICE_NUM; j++)
		{
			if (j > 1 && !isTwoDiceEven(dice_arr, i))
			{
				continue;
			}

			dice_arr[i][j] = roll_dice(MIN, MAX);
		}
	}

	operate_dice_skill(dice_arr);
	decision_winner(dice_arr);
	print_dice_arr(dice_arr);

	// 된다 ? 안된다 ? x
	//test_print_function(dice_arr);

#if 0
	test_print_function2(dice_arr);

	printf("꼼수 시전!\n");
	test_print_function3(dice_arr);
#endif
}

int main(void)
{
	srand(time(NULL));

	game_start();

	return 0;
}
