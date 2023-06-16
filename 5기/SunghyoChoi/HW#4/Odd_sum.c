#include <stdio.h>

int main(void)
{
	int  End=5;
	int  sum=0;
	for (int  i=1; i<=End; ++i){
		if(i%2==1){
			sum+=i;
		}
	}
	printf("%d까지의 홀수의 합은 %d\n",End,sum);
	return 0;
}
