#include "dice_controller_command.h"

#include "../../../ui/console/user_input.h"

#include <stdio.h>
#include <stdlib.h>

char dice_command_msg[] = "다음 명령들 중 하나를 입력해주세요!\n"
                            "0 (주사위 굴리기)\n";

void print_dice_command (void)
{
    printf("%s", dice_command_msg);
}

int input_user_dice_command (void)
{
    char real_user_input[MAX_USER_INPUT] = { 0 };
    get_user_input(real_user_input);
    return atoi(real_user_input);
}