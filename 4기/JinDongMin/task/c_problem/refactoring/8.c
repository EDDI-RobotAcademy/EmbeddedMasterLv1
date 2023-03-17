#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE_NUM_MIN    1
#define DICE_NUM_MAX    6

void init_random(void)
{
    srand(time(NULL));
}

int custom_random_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void play_dice_game(void)
{
    int dice_num = custom_random_int(DICE_NUM_MIN, DICE_NUM_MAX);
    printf("주사위를 굴려서 나온 숫자는 %d 입니다.\n", dice_num);
}

void execute_dice_game(void)
{
    char user_answer;

    printf("주사위를 굴릴까요? [Y/n] ");
    scanf("%c", &user_answer);

    if ((user_answer == 'y') || (user_answer == 'Y'))
    {
        play_dice_game();
    }

    printf("주사위 게임을 종료합니다.\n");
}

int main(void)
{
    init_random();

    execute_dice_game();

    return 0;
}