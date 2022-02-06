#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define	PLAY_NUM	2
#define DICE_NUM	3
#define DEATH		(-4444)



int main(void)
{
	srand(time(NULL));
	game_start();

	return 0;
}
