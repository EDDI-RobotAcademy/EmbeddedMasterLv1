#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _power_grid_info power_grid_info;

typedef struct _air_harmonic_info air_harmonic_info;

#if 0
struct _power_grid_info
{
	float power;
	float battert_cell_voltage[0];
};
#endif 

#define POWER_GRID_DATA_SIZE	4

struct _power_grid_info
{
	int data[0];
};

#define AIR_HARMONIC_DATA_SIZE	4

struct _air_harmonic_info
{
	int data[0];
};

power_grid_info *init_power_grid_info(void)
{
	power_grid_info *tmp;

	tmp = (power_grid_info *)malloc(POWER_GRID_DATA_SIZE);
	
	return tmp;
}

air_harmonic_info * init_air_harmonic_info(void)
{
	air_harmonic_info *tmp;

	tmp = (air_harmonic_info *)malloc(AIR_HARMONIC_DATA_SIZE);

	return tmp;
}

int custom_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void receive_power_grid_data(power_grid_info **info)
{
	(*info)->data[0] = custom_random(1, 5);
}



int main(void)
{
	power_grid_info * receive_power_data;
	air_harmonic_info * receive_air_data;

	srand(time(NULL));

	printf("sizeof(power_grid_info) = %ld\n", sizeof(power_grid_info));
	printf("sizeof(air_harmonic_info) = %ld\n", sizeof(air_harmonic_info)); 
	
	

	receive_power_data = init_power_grid_info();
	receive_air_data = init_air_harmonic_info();
	
	receive_power_grid_data(&receive_power_data);
	printf("power data = %d\n", receive_power_data->data[0]);	


	return 0;
}
