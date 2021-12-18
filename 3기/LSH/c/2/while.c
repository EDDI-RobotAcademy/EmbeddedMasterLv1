#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int cnt = 0;
	bool loop = true;

	while(loop)
	{
		printf("cnt = %d\n", ++cnt);

		if (cnt == 7)
			loop = false;
	}

	return 0;
}
