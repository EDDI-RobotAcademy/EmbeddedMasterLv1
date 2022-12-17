// shortcut 동작 방식에 대해서 서술해보시오(&&와 ||에 대해서 각각)
#include <stdio.h>

int main (void)
{
	int test1 = 3, test2 = 7;

	if (++test1 == 4 || ++test2)
	{
		;
	}
	printf("test1 = %d, test2 = %d\n", test1, test2);

	if (++test1 == 3 && --test2)
	{
		;
	}
	printf("test1 = %d, test2 = %d\n", test1, test2);

	return 0;
}
