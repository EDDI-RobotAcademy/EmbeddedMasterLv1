#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_random_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main(void)
{
    int i;
    char user_answer;

    srand(time(NULL));

    printf("주사위를 굴릴까요? [Y/n] ");
    scanf("%c", &user_answer);

    if ((user_answer == 'y') || (user_answer == 'Y'))
    {
        int dice_num = get_random_int(1, 6);
        printf("주사위를 굴려서 나온 숫자는 %d 입니다.\n", dice_num);
    }
    printf("프로그램을 종료합니다\n");

    return 0;
}