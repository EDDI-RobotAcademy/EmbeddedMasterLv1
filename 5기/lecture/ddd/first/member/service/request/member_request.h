#ifndef __MEMBER_REQUEST_H__
#define __MEMBER_REQUEST_H__

#include "../../entity/member.h"

typedef struct _member_request member_request;
struct _member_request
{
    char *id;
    char *password;
};

member_request *init_member_request (char *id, char *password);
void print_member_request (member_request *member_request_object);
member *to_member (member_request *member_request_object);
void free_member_request (member_request *member_request_object);

#endif
