#include <stdio.h>
#include <stdlib.h>

typedef struct _power_grid_info power_grid_info;

#if 0
struct _power_grid_info
{
	float power;
	float battery_cell_voltage[0];
};
#endif

struct _power_grid_info
{
	int data[0];
};

#define POWER_GRID_DATA_SIZE			4

power_grid_info *init_power_grid_info(void)
{
	power_grid_info *tmp;

	tmp = (power_grid_info *)malloc(POWER_GRID_DATA_SIZE);

	return tmp;
}

int main(void)
{
	power_grid_info *receive_power_data;
	printf("sizeof(power_grid_info) = %ld\n", sizeof(power_grid_info));

	receive_power_data = init_power_grid_info();

	return 0;
}