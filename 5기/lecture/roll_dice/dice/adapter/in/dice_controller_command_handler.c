#include "dice_controller_command_handler.h"

#include "../../application/services/roll_dice_service_command.h"
#include "../../application/services/roll_dice_service_command_handler.h"
#include "../../application/services/roll_dice_service_command_table.h"

#include <stdio.h>

void roll_dice (void)
{
    printf("dice controller(input adapter) - roll_dice()\n");

    roll_dice_service_command_table[ROLL_DICE_SERVICE_EXECUTE]();
}
