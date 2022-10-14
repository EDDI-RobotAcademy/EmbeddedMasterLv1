#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ERROR		7
#define LOOP_END	50

#define DATA_RECEIVE_ERROR	-3

int main(void)
{
	int i, j, k;
	int data;

	srand(time(NULL));

	for (i = 0; i < LOOP_END; i++)
	{
		for (j = 0; j < LOOP_END; j++)
		{
			for (k = 0; k < LOOP_END; k++)
			{
				data = rand() % (LOOP_END + 1); // 범위는 [0, LOOP_END]
				printf("data = %d\n", data);

				if (data == ERROR)
				{
					printf("Error 발생!\n");
					goto error_handler;
				}
			}
		}
	}

	return 0;

error_handler:
	printf("에러 핸들링 시작!\n");
	return DATA_RECEIVE_ERROR;
}
