#include <stdio.h>

#include "select_function.h"
#include "../receiver/receiver.h"

// F7: Build
// Shift + F5: Run
// Ctrl + F5: Debug

// Ctrl + N: New file

int main (void)
{
    printf("Turn on the camera\n");
    select_function();

    recv_command_from_outbound();

    return 0;
}