#include "member_command.h"

#include <stdio.h>

char member_command_msg[] = "다음 명령들 중 하나를 입력해주세요!\n"
                            "0 (member register)\n"
                            "1 (member login)\n"
                            "2 (member list)\n";

void print_member_command (void)
{
    printf("%s", member_command_msg);
}

int input_user_member_command (void)
{
    return 0;
}