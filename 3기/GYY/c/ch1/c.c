#include <stdio.h>

int main(void)
{
	printf("변수 타입 char의 할당되는 메모리 크기는 %lu\n",sizeof(char));
	printf("변수 타입 short의 할당되는 메모리 크기는 %lu\n",sizeof(short));
	printf("변수 타입 int의 할당되는 메모리 크기는 %lu\n",sizeof(int));
	printf("변수 타입 float의 할당되는 메모리 크기는 %lu\n",sizeof(float));
	printf("변수 타입 double의 할당되는 메모리 크기는 %lu\n",sizeof(double));
	printf("변수 타입 long double의 할당되는 메모리 크기는 %lu\n",sizeof(long double));
	

return 0;
}
