#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define PLAY_NUM	2
#define DICE_NUM	3
#define DEATH	(-4444)

int dice_roll(int min, int max)
{
	int range=max-min+1;
	return rand()%range+min;
}

bool istwoeven(int (* arr)[DICE_NUM], int location)
{
	int i;
	int sum=0;
	const int CHECK_NUM=2;
	for(i=0;i<CHECK_NUM;i++)
	{
		sum+=arr[location][i];
	}
	return sum%2==0;
}

void operate_dice_skill(int (* arr)[DICE_NUM])
{
	int i,j;
	for(i=0;i<PLAY_NUM;i++)
	{
		switch(arr[i][DICE_NUM-1])
		{
			case 3:
				printf("스킬을 시전합니다.\n");
				for(j=0;j<PLAY_NUM;j++)
				{
					if(i==j)
					{
						continue;
					}
					arr[i][DICE_NUM]+=3;
					arr[j][DICE_NUM]-=3;
				}
				break;

			case 4:
				printf("당신은 죽었습니다.\n");
				arr[i][DICE_NUM-1]+=DEATH;
				break;
		}
	}
}

bool decision_death(int (* arr)[DICE_NUM])
{
	int i;
	bool isdead=false;
	for(i=0;i<PLAY_NUM;i++)
	{
		if(arr[i][DICE_NUM-1]<-3)
		{
			isdead=true;
			printf("플레이어 %d는 죽었습니다.\n", i);	
		}
	}	
	return isdead;
}

void decision_winner(int (* arr)[DICE_NUM])
{
	int i,j;
	int arr_sum[PLAY_NUM]={ 0 };
	if(!decision_death(arr))
	{
		for(i=0;i<PLAY_NUM;i++)
		{
			for(j=0;j<DICE_NUM;i++)
			{
				arr_sum[i]+=arr[i][j];
			}
		}
		if(arr_sum[0]>arr_sum[1])
		{
			printf("플레이어 0이 이겼습니다.\n");
		}
		
		else if(arr_sum[0]<arr_sum[1])
		{
			
			printf("플레이어 1이 이겼습니다.\n");
		}
		else
		{
			printf("둘은 비겼습니다.\n");
		}
	}
}

void print_dice(int (* arr)[DICE_NUM])
{
	int i,j;
	for(i=0;i<PLAY_NUM;i++)
	{
		printf("플레이어 %d의 주사위는 :", i);
		for(j=0;j<DICE_NUM;j++)
		{
			printf("%6d", arr[i][j]);
		}
		printf("\n");
	}
}

void game_start(void)
{
	int i,j;
	int dice_arr[PLAY_NUM][DICE_NUM] = { 0 };
       
	const int MIN=1;
	const int MAX=6;
	for(i=0;i<PLAY_NUM;i++)
	{
		for(j=0;j<DICE_NUM;j++)
		{
			if(j>1 && !istwoeven(dice_arr, i))
			{
				continue;
			}
			dice_arr[i][j]=dice_roll(MIN, MAX);
		}
	}
	operate_dice_skill(dice_arr);	
	decision_winner(dice_arr);
	print_dice(dice_arr);
}

int main(void)
{
	srand(time(NULL));
	game_start();
	return 0;
}
