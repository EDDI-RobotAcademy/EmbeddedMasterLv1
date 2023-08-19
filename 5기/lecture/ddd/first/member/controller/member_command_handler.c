#include "member_command_handler.h"
#include "../entity/member.h"

#include "../service/member_service_command.h"
#include "../service/member_service_handler.h"
#include "../service/member_service_command_table.h"

#include "../service/request/member_request.h"

//#include "../../utility/ui/console/input_process.h"
#include "../../ui/console/user_input.h"
#include "../../session/session.h"

#include <stdio.h>
#include <string.h>

void member_register (void)
{
    char id[5] = "id: ";
    char password[11] = "password: ";

    char user_input_id[MAX_USER_INPUT] = { 0 };
    char user_input_password[MAX_USER_INPUT] = { 0 };

    printf("member controller: register()\n");

    get_user_input_with_msg(id, user_input_id);
    get_hidden_user_input_with_msg(password, user_input_password);

    member_request *member_request_object = init_member_request(user_input_id, user_input_password);
    member_service_table[MEMBER_REGISTER_SERVICE](member_request_object);

    free_member_request(member_request_object);
}

void member_login (void)
{
    char id[5] = "id: ";
    char password[11] = "password: ";

    char user_input_id[MAX_USER_INPUT] = { 0 };
    char user_input_password[MAX_USER_INPUT] = { 0 };
    printf("member controller: login()\n");

    get_user_input_with_msg(id, user_input_id);
    get_hidden_user_input_with_msg(password, user_input_password);

    member_request *member_request_object = init_member_request(user_input_id, user_input_password);
    member_service_table[MEMBER_LOGIN_SERVICE](member_request_object);

    if (session_object.session_id) { printf("로그인 성공!\n"); }
    else { printf("로그인 실패!\n"); }
}

void member_list (void)
{
    printf("unique value: %d\n", unique_member_value_count);
    //printf("id: %s", member_info_table[0].id)
}