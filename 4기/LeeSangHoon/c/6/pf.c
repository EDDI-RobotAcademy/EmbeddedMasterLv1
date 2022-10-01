#include <stdio.h>

float pf_test(int num, char *p)
{
	printf("p = %s\n", p);
	printf("num = %d\n", num);

	return 3.3f;
}

int main(void)
{
	// float (*) (int num, char *p)
	float (* p)(int num, char *p) = pf_test;

	printf("%f\n", p(3, "안녕"));
}
