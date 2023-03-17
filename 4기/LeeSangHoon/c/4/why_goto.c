#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR			7
#define LOOP_END		50

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
				data = rand() % (LOOP_END + 1);
				printf("data = %d\n", data);

				// 이 시점에 에러가 발생했다고 가정을 해보자는 뜻
				if (data == ERROR) {
					printf("Error 발생!\n");
				}
			}
		}
	}
}
