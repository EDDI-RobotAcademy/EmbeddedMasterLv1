#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALLOCATE_SUCCESS    0
#define ALLOCATE_FAIL       -1

// 전력 그리드의 전송 정보를 관리하는 구조체
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

// 공기조화장치의 전송 정보를 관리하는 구조체
typedef struct _air_harmonic_info air_harmonic_info;
struct _air_harmonic_info
{
    int data[0];
};
#define AIR_HARMONIC_DATA_SIZE  4

air_harmonic_info *init_air_harmonic_info(void)
{
    air_harmonic_info *tmp;
    tmp = (air_harmonic_info*)malloc(AIR_HARMONIC_DATA_SIZE);

    if (tmp == NULL)
    {
        printf("air_harmonic_info 구조체 할당 실패\n");
        exit(ALLOCATE_FAIL);
    }

    return tmp;
}

void clear_air_harmonic_info(air_harmonic_info* tmp)
{
    free(tmp);
    tmp = NULL;
}

// 랜덤 값 생성
int custom_random(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void receive_power_grid_data(power_grid_info **info)
{
    (*info)->data[0] = custom_random(1, 5);
}

void receive_air_harmonic_data(air_harmonic_info** info)
{
    (*info)->data[0] = custom_random(2, 4);
}

int main(void)
{
    int i, sum = 0;

    power_grid_info *receive_power_data;
    air_harmonic_info *receive_air_data;

    srand(time(NULL));

    receive_power_data = init_power_grid_info();
    receive_air_data = init_air_harmonic_info();

    for (i = 0; i < 10; i++)
    {
        receive_power_grid_data(&receive_power_data);
        receive_air_harmonic_data(&receive_air_data);

        sum += receive_power_data->data[0] * receive_air_data->data[0];
    }
    
    printf("final sum = %d\n", sum);

    clear_power_grid_info(receive_power_data);
    clear_air_harmonic_info(receive_air_data);
    return 0;
}