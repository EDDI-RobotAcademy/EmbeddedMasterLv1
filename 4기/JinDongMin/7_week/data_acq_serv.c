#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALLOCATE_SUCCESS    0
#define ALLOCATE_FAIL       -1

typedef struct _power_grid_info power_grid_info;
struct _power_grid_info
{
    int data[0];
};
#define POWER_GRID_DATA_SIZE    4

power_grid_info *init_power_grid_info(void)
{
    power_grid_info *tmp;

    tmp = (power_grid_info*)malloc(POWER_GRID_DATA_SIZE);

    if (tmp == NULL)
    {
        printf("power_grid_info 구조체 할당 실패\n");
        exit(ALLOCATE_FAIL);
    }

    return tmp;
}

void clear_power_grid_info(power_grid_info* tmp)
{
    free(tmp);
    tmp = NULL;
}

int main(void)
{
    return 0;
}