#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ZERO	0
#define ONE	1
#define TWO	2

int main(void)
{
	int num;
	bool loop = true;

	srand(time(NULL));

	while(loop)
	{
		num = rand() % 100 + 1;

		switch(num % 3)
		{
			case ZERO:
				printf("ZERO\tnum = %d\n", num);
				break;

			case ONE:
				printf("ONE\tnum = %d\n", num * 3);
				break;

			case TWO:
				printf("게임이 종료되었습니다.\n");
				loop = false;
				break;
		}
				
	}


	return 0;
}
