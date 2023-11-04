#ifndef __COMMAND_H__
#define __COMMAND_H__

enum command
{
    EXIT,
    MEMBER_REGISTER,
    MEMBER_LOGIN,
    END
};

#define COMMAND_CALL_BUFFER_COUNT          (END)
#define COMMAND_CALL_BUFFER                ((END) - 1)

#endif