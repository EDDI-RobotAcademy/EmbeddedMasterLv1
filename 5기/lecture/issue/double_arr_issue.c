#include <stdio.h>

int main (void)
{
	int arr[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	int *ptr_arr[3] = { &arr[0][1], &arr[2][0], &arr[1][1] };
	int (*arr_ptr)[3] = arr;
	int (*other_arr_ptr)[4] = arr;
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("arr_ptr[%d] = %d\n", i, *arr_ptr[i]);
	}
	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("ptr_arr[%d] = %d\n", i, *ptr_arr[i]);
	}
	printf("\n");

	for (i = 0; i < 3; i++)
	{
		printf("other_arr_ptr[%d] = %d\n", i, *other_arr_ptr[i]);
	}

	return 0;
}
