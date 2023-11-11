#include "user_input.h"

#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <termios.h>

void get_hidden_user_input_with_msg(char *output_msg, char *hidden_user_input)
{
    struct termios oldt, newt;
    int length = 0;
    char ch;

    write(1, output_msg, strlen(output_msg));

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    read(0, hidden_user_input, MAX_USER_INPUT);
    length = strlen(hidden_user_input);
    hidden_user_input[length] = '\0';

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    printf("\n");
}

void get_user_input_with_msg (char *output_msg, char *user_input)
{
    write(1, output_msg, strlen(output_msg));
    read(0, user_input, MAX_USER_INPUT);
}

void get_user_input (char *user_input)
{
    read(0, user_input, MAX_USER_INPUT);
}