#include <stdio.h>
#include <stdbool.h>	//c99 표준이 support되는지 확인해야함

int main(void)
{
	int cnt = 0;
	bool loop = true;
	
	while(loop)
	{
		printf("cnt = %d\n",++cnt);
		if(cnt==7){
			loop=false;}
	}
	return 0;
}
