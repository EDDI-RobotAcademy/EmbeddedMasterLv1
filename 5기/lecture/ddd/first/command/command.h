#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <stdbool.h>

enum command
{
    EXIT,
    MEMBER,
    PRODUCT,
    END
};

extern int user_input_command;

#define COMMAND_CALL_BUFFER_COUNT          (END)
#define COMMAND_CALL_BUFFER                ((END) - 1)

bool check_user_input_close (void);
void print_basic_command (void);
int input_user_command (void);

#endif