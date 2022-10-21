#include <stdio.h>

int main(void)
{
	int i = 0;
	char ch = 'A';

	for (; i < 26; i++, ch++)
	{
		printf("%c, %c\n", ch, ch ^ 0x20);
	}

	return 0;
}
