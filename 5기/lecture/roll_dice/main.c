#include "dice/adapter/in/dice_controller_command.h"
#include "dice/adapter/in/dice_controller_command_handler.h"
#include "dice/adapter/in/dice_controller_command_table.h"

#include "utility/random.h"

#include <stdio.h>

int main (void)
{
    config_random_seed();
    dice_controller_table[DICE_ROLL]();

    return 0;
}
