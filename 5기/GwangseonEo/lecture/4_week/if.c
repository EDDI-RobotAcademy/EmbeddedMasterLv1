#include <stdio.h>

void test(void)
{
	int arr[3] = {2,1,0};

	for(int i=0;i<3;i++)
	{
		arr[i] = i;
		printf("arr[%d] = %d\r\n", i, arr[i]);
	}
}

int main(void){
	int a = 1;
	int b = 2;
	
	if (b>a) test();
		
	return 0;	
}
