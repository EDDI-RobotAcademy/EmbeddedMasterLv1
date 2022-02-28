#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int run_dice(void)
{
	return rand() % 6 + 1;
}

int main(void)
{
	srand(time(NULL));

	int dice = run_dice();

	printf("dice = %d\n", dice);

	return 0;
}
