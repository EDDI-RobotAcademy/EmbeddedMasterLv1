#include "member_command_handler.h"
#include "../entity/member.h"

#include "../service/member_service_command.h"
#include "../service/member_service_handler.h"
#include "../service/member_service_command_table.h"

#include "../service/request/member_request.h"

#include <stdio.h>
#include <string.h>

void member_register (void)
{
    char id[3] = "id";
    char password[9] = "password";

    printf("member controller: register()\n");

    member_request *member_request_object = init_member_request(id, password);
    member_service_table[MEMBER_REGISTER_SERVICE](member_request_object);

    free_member_request(member_request_object);
}

void member_login (void)
{
    char user_id[MAX_USER_INPUT] = { 0 };
    char user_password[MAX_USER_INPUT] = { 0 };
    char message[] = "로그인 시퀀스를 진행합니다!\n";
    int message_length = strlen(message);


    printf("로그인 성공!\n");
}

void member_list (void)
{
    printf("unique value: %d\n", unique_member_value_count);
    //printf("id: %s", member_info_table[0].id)
}