#include <stdio.h>

#include "add_on_lib.h"
#include "../receiver/receiver.h"

// F7: Build
// Shift + F5: Run
// Ctrl + F5: Debug

// Ctrl + N: New file
int main (void)
{
    printf("First Test\n");
    iam_add_on();

    recv_command_from_outbound();

    return 0;
}