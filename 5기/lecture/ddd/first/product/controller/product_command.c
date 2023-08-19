#include "product_command.h"

#include "../../ui/console/user_input.h"

#include <stdio.h>
#include <stdlib.h>

char product_command_msg[] = "다음 명령들 중 하나를 입력해주세요!\n"
                            "0 (product register) - 막혀있음\n"
                            "1 (product list)\n";

void print_product_command (void)
{
    printf("%s", product_command_msg);
}

int input_user_product_command (void)
{
    char real_user_input[MAX_USER_INPUT] = { 0 };
    get_user_input(real_user_input);
    return atoi(real_user_input);
}