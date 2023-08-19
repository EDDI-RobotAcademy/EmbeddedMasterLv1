#ifndef __MEMBER_COMMAND_H__
#define __MEMBER_COMMAND_H__

enum member_command
{
    MEMBER_REGISTER,
    MEMBER_LOGIN,
    MEMBER_LIST,
    MEMBER_END
};

#define MEMBER_CALL_BUFFER_COUNT          (MEMBER_END)
#define MEMBER_CALL_BUFFER                ((MEMBER_END) - 1)

void print_member_command (void);
int input_user_member_command (void);

#endif
