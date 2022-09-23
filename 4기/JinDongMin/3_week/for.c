#include <stdio.h>

int main(void)
{
	int i;
	char ch = 'A';

	for (i = 0; i < 26; i++, ch++)
	{
		printf("%c, %c\n", ch, ch ^ 0x20);
	}

	return 0;
}
