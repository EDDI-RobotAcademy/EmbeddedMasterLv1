#ifndef __MEMBER_SERVICE_HANDLER_H__
#define __MEMBER_SERVICE_HANDLER_H__

#include "request/member_request.h"

void member_register_service (member_request *);
void member_login_service (member_request *);
void member_list_service (member_request *);

#endif
