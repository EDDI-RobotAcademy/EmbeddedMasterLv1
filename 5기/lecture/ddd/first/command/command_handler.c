#include "../member/controller/member_command.h"
#include "../member/controller/member_command_handler.h"
#include "../member/controller/member_command_call_table.h"

#include "../product/controller/product_command.h"
#include "../product/controller/product_command_handler.h"
#include "../product/controller/product_command_call_table.h"

#include "command_handler.h"

#include <stdio.h>
#include <stdlib.h>

// 여기서 각종 메모리 해제를 모두 진행해야함
void program_exit (void)
{
    printf("프로그램을 종료합니다!\n");
    exit(0);
}

void invoke_member_call_table (void)
{
    int member_command;

    print_member_command();
    member_command = input_user_member_command();
    member_call_table[member_command]();
}

void invoke_product_call_table (void)
{
    int product_command;

    print_product_command();
    product_command = input_user_product_command();
    product_call_table[product_command]();
}