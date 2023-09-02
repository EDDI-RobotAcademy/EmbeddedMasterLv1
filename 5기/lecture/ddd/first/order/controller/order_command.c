#include "order_command.h"

#include "../../ui/console/user_input.h"

#include <stdio.h>
#include <stdlib.h>

char order_command_msg[] = "다음 명령들 중 하나를 입력해주세요!\n"
                            "0 (order register)\n"
                            "1 (order list)\n";

void print_order_command (void)
{
    printf("%s", order_command_msg);
}

int input_user_order_command (void)
{
    char real_user_input[MAX_USER_INPUT] = { 0 };
    get_user_input(real_user_input);
    return atoi(real_user_input);
}