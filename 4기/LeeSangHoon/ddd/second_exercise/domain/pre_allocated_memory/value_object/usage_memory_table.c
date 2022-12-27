#include <stdio.h>
#include <stdlib.h>

#include "usage_memory_table.h"

void init_usage_memory_table (void)
{
    int i, j;

    for (i = 0; i < PREALLOC_COUNT; i++)
    {
        for (j = 0; j < MEMORY_SIZE_LIMIT; j++)
        {
            usage_memory[i].usage_idx[j] = (usage_memory_idx *)malloc(sizeof(usage_memory_idx));
            usage_memory[i].usage_idx[j]->idx = j;
            usage_memory[i].usage_idx[j]->state = NOT_YET;

            if (j > 0)
            {
                usage_memory[i].usage_idx[j - 1]->next = usage_memory[i].usage_idx[j];
            }
        }
    }
}

void print_usage_memory_table (void)
{
    int i, j;

    for (i = 0; i < PREALLOC_COUNT; i++)
    {
        for (j = 0; j < MEMORY_SIZE_LIMIT; j++)
        {
            printf("idx = %d, ", usage_memory[i].usage_idx[j]->idx);

            if (usage_memory[i].usage_idx[j]->next != NULL)
            {
                printf("next = %d\n", usage_memory[i].usage_idx[j]->next->idx);
            }
            else
            {
                printf("next = NULL\n");
            }
        }
    }
}

void set_usage_memory_table(int memory_idx, int will_be_set_idx)
{
    usage_memory_idx current_set_idx = *usage_memory[memory_idx].usage_idx[will_be_set_idx];
    current_set_idx.state = USAGE;
}