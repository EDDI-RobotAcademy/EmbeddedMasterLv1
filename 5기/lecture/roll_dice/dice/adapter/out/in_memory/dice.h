#ifndef __DICE_H__
#define __DICE_H__

typedef struct _dice dice;

struct _dice
{
    int number;
};

extern dice fixed_dice_object;

#define DICE_MIN_NUMBER         1
#define DICE_MAX_NUMBER         6

#endif