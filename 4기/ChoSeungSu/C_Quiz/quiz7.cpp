#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void init_num(int *p)
{
    int i , sub_i;

    for (i=0; i< MAX ; i++)
    {
        *(p+i) = rand() % 10 + 1;
        for (sub_i = 0; sub_i< i ; sub_i ++)
        {
            if(p[i] == p[sub_i])
            {
                i--;
                break;
            }
        }
    }
}

// 중복 검사 알고리즘 
// 1st. 배열 첫번째 칸에 난수 생성
// 2st. i = sub_i 랑 같으니깐 반복문 속 반복문 바로 탈출 
// 3st. i ++ 
// 4st. 배열 두번째 칸에 난수 생성
// 5st. 두번째 반복문 들어감
// 6st. 첫번째 배열 값이랑 두번째 배열값이랑 같음? 
// 7st. i값 1 감소시킨다음에 첫번째 배열값 다시 만들기 
// 계속 이런 과정 반복하면서 이전 배열값이랑 다음 배열값이 다르면 반복문 계속 진행 
// 같은 값이 나오면 2~7 과정 반복하고 반복문 진행 

// 많이   비효율적. 

int main()
{
    int num_arr[MAX];

    srand(time(NULL));

    init_num(num_arr);

    int i;

    for (i=0; i<MAX ; i++)
    {
        printf("num = %d\n", num_arr[i]);
    }

}