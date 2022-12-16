#include <stdio.h>
#include "domain/pre_allocated_memory/entity/pre_allocated_memory.h"
#include "domain/pre_allocated_memory/value_object/free_memory_table.h"
#include "domain/pre_allocated_memory/value_object/usage_memory_table.h"

int main(void)
{
    int i;
    int *number_array;
    double *double_array;

    init_free_memory_table();
    init_usage_memory_table();
    init_pre_allocated_memory(30);

    number_array = pre_allocated_memory_alloc(20);
    double_array = pre_allocated_memory_alloc(24);

    for (int i = 0; i < 5; i++)
    {
        number_array[i] = (i + 1) * 10;
        double_array[i] = (i + 0.37) * 0.12;
        printf("number_array[%d] = %d, double_array[%d] = %lf\n", i, number_array[i], i, double_array[i]);
    }

    return 0;
}
