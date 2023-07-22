#ifndef __MEMBER_SERVICE_COMMAND_H__
#define __MEMBER_SERVICE_COMMAND_H__

enum member_service_command
{
    MEMBER_REGISTER_SERVICE,
    MEMBER_LOGIN_SERVICE,
    MEMBER_LIST_SERVICE,
    END
};

#define MEMBER_SERVICE_CALL_BUFFER_COUNT          (END)
#define MEMBER_SERVICE_CALL_BUFFER                ((END) - 1)

#endif
