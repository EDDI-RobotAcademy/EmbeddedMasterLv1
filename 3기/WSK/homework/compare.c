#include <stdio.h>

int main(void)
{
	int x, y;
	
	printf("두 변수의 대소 비교\n");
	printf("x를 입력하세요.\n");
	scanf("%d", &x);
	printf("y를 입력하세요.\n");
	scanf("%d", &y);

	if(x > y)
		printf("x가 더 큽니다.\n");
	else if(x < y)
		printf("y가 더 큽니다.\n");
	else
		printf("x와 y는 같습니다.\n");
	
	return 0;
}

