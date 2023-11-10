#include "dice_in_memory_adapter_command_handler.h"

#include "dice.h"
#include "../../../../utility/random.h"

#include <stdio.h>

void store_dice_number(void)
{
    fixed_dice_object.number = 
        generate_random(DICE_MIN_NUMBER, DICE_MAX_NUMBER);

    printf("dice number: %d\n", fixed_dice_object.number);
}
