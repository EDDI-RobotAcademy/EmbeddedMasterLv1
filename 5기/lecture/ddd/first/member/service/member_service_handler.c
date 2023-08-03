#include "member_service_handler.h"

#include "request/member_request.h"
#include "../entity/member.h"

#include "../repository/member_repository_command.h"
#include "../repository/member_repository_handler.h"
#include "../repository/member_repository_command_table.h"

#include <stdio.h>

void member_register_service (member_request *member_request_object)
{
    printf("member service: register()\n");
    print_member_request(member_request_object);

    member *member_object = to_member(member_request_object);
    print_member(member_object);

    member_repository_table[MEMBER_SAVE_REPOSITORY](member_object);

    free_member(member_object);
}

void member_login_service (member_request *member_request_object)
{
    printf("member service: login()\n");
}

void member_list_service (member_request *member_request_object)
{
    printf("member service: list()\n");
}