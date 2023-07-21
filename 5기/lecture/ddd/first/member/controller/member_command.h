#ifndef __MEMBER_COMMAND_H__
#define __MEMBER_COMMAND_H__

enum member_command
{
    MEMBER_REGISTER,
    MEMBER_LOGIN,
    MEMBER_LIST,
    END
};

#define MEMBER_CALL_BUFFER_COUNT          (END)
#define MEMBER_CALL_BUFFER                ((END) - 1)

void print_member_command (void);
int input_user_member_command (void);

#endif
