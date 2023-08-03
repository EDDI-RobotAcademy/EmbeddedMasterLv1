#include "command.h"
#include "../utility/ui/console/input_process.h"

#include <stdio.h>
#include <stdlib.h>

char basic_msg[] = "다음 명령들 중 하나를 입력해주세요!\n"
                   "0 (program exit)\n"
                   "1 (member)\n";

int user_input_command = 1;

bool check_user_input_close (void)
{
    return user_input_command == 0;
}

void print_basic_command (void)
{
    printf("%s", basic_msg);
}

int input_user_command (void)
{
    char real_user_input[USER_COMMAND_INPUT_MAX] = { 0 };
    custom_user_input(real_user_input);
    return atoi(real_user_input);
}