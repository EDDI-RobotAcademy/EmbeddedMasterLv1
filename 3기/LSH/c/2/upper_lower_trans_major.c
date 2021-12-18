#include <stdio.h>

int main(void)
{
	char c = '\0';

	printf("문자를 입력하세요: ");
	scanf("%c", &c);

	if ((c > 96 && c < 123) || (c > 64 && c < 91))
	{
		printf("xor는 뭐든 가능하다!\n");
		printf("입력값 = %c, 변환값 = %c\n", c, c ^ 0x20);
	}

	return 0;
}
