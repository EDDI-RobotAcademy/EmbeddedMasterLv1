#include <stdio.h>

int main(void)
{
	char c = '\0';
	printf("문자를 입력하세요 : ");
	scanf("%c", &c);

	if(c > 96 && c < 123)
	{
		printf("소문자를 입력하셨습니다!\n");
		printf("대문자는 %c\n", c - 0x20);
	}

	if(c > 64 && c <91)
	{
		printf("대문자를 입력하셨습니다!\n");
		printf("소문자는 %c\n", c + 0x20);
	}

	return 0;
}
