#ifndef __DICE_CONTROLLER_COMMAND_H__
#define __DICE_CONTROLLER_COMMAND_H__

enum dice_command
{
    DICE_ROLL,
    DICE_END
};

#define DICE_CALL_BUFFER_COUNT          (DICE_END)
#define DICE_CALL_BUFFER                ((DICE_END) - 1)

void print_dice_command (void);
int input_user_dice_command (void);

#endif