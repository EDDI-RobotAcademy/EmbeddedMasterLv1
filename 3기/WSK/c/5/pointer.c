# include <stdio.h>

int main(void)
{
	int num_arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int *p_arr = NULL;
	int i;
	int len = sizeof(num_arr) / sizeof(int);

	p_arr = num_arr;
	
	for(i = 0; i < len; i++)
	{
		printf("p_arr[%d] = %d\n", i, p_arr[i]);
	}

	return 0;
}
