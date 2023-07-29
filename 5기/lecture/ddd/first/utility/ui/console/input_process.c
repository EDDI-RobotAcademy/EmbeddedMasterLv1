#include "input_process.h"

#include <unistd.h>
#include <string.h>

void custom_user_input_with_msg (char *msg_to_be_print, char *user_input)
{
    write(1, msg_to_be_print, strlen(msg_to_be_print));
    read(0, user_input, USER_COMMAND_INPUT_MAX);
}

void custom_user_input (char *user_input)
{
    read(0, user_input, USER_COMMAND_INPUT_MAX);
}