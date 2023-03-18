#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC		16

int main(void)
{
	int i, data;

	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		data = rand() % 256;
		// rand() % 256 => 0 ~ 255
		// 2^8 2^7 2^6 2^5 2^4 2^3 2^2 2^1 2^0
		//  1   0   0   0   0   0   0   0   0    256
		//  0   1   1   1   1   1   1   1   1    255
		//  0   0   0   0   1   0   0   0   0    16
		//  0   0   0   0   0   1   1   1   1    15
		//  1   1   1   1   1   0   0   0   0   ~15
		//  0   X   X   X   X   X   X   X   X    0 ~ 255
		//  ---------------------------------------------
		//  0   X   X   X   X   0   0   0   0

		printf("data = %d, data & ~(MAGIC - 1) = %d\n", data, data & ~(MAGIC - 1));
	}

	return 0;
}
