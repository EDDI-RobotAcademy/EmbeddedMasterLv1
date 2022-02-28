#include <stdio.h>

void conversion_big_to_small(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] > 64 && str[i] < 92)
		{
			str[i] ^= 0x20;
		}
	}
}

int main(void)
{
	char str[] = "WhErE ArE YOu FROM ?";

	printf("default: %s\n", str);

	conversion_big_to_small(str);

	printf("conversion: %s\n", str);
}
