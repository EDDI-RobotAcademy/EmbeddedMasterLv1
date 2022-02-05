#include <stdio.h>

// 행렬 연산후 행렬 결과를 리턴하고자함 (2 by 2 행렬 가정)
// int (*)[2] <<< 리턴 타입
// mat_add     <<< 함수 이름
// int (*p)[2] <<< 파라미터
// int (* mat_add2(int (*src)[2]))[2];

int (* mat_add(int (*src)[2]))[2]
{
	int i, j;
	// 함수 내부에 static 변수를 선언하면
	// 반드시 해당 함수를 통해서만 static 변수의 결과를 얻을 수 있다.
	// 완벽하진 않지만 C++이나 Java의 private 역할을 수행할 수 있음
	static int res[2][2] = {
		{ 1, 1 }, { 1, 1 }
	};

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			res[i][j] += src[i][j];
		}
	}

	return res;
}

int main (void)
{
	int i, j;
	int src_mat[2][2] = {
		{ 1, 3 }, { 2, 4 }
	};

	int (*dst)[2] = mat_add(src_mat);

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("res[%d][%d] = %d\n", i, j, dst[i][j]);
		}
	}

	return 0;
}
