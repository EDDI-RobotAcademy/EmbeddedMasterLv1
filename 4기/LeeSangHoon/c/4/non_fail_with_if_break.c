#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ERROR			7
#define LOOP_END		50

int main(void)
{
	int i, j, k;
	int data;
	bool error_flag = false;

	srand(time(NULL));

	for (i = 0; i < LOOP_END; i++)
	{
		for (j = 0; j < LOOP_END; j++)
		{
			for (k = 0; k < LOOP_END; k++)
			{
				data = rand() % (LOOP_END + 1);
				printf("data = %d\n", data);
			}

			if (error_flag)
			{
				break;
			}

			printf("if - break 작업 이후\n");
		}

		if (error_flag)
		{
			break;
		}

		printf("if - break 작업 이후\n");
	}

	return 0;
}
