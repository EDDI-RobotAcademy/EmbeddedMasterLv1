#ifndef __PRE_ALLOCATED_MEMORY_H__
#define __PRE_ALLOCATED_MEMORY_H__

#include "../../common/utility/override_macro.h"

enum slab_idx
{
    SLAB_32 = 5,
    SLAB_64,
    SLAB_128,
    SLAB_256,
    SLAB_512,
    SLAB_1K,
    SLAB_2K,
    SLAB_4K,
    SLAB_8K,
    SLAB_16K,
    SLAB_32K,
    SLAB_64K,
    SLAB_128K,
    SLAB_256K,
    END
};

#define ARRAY_BIAS                  (5)
#define PREALLOC_COUNT              ((END) - (ARRAY_BIAS))

#define DEFAULT_BASE_MEMORY_SIZE    16

#define MEMORY_SIZE_LIMIT           32

typedef struct _pre_allocated_memory_object
{
    int allocated_max_memory_size;

    void ***allocated_memory;
}
pre_allocated_memory_object;

pre_allocated_memory_object pre_allocated_memory;

#define init_pre_allocated_memory(...)      OVERLOADED_MACRO(init_pre_allocated_memory, __VA_ARGS__)
#define init_pre_allocated_memory0()        init_pre_allocated_memory_0arg()
#define init_pre_allocated_memory1(arg1)    init_pre_allocated_memory_1arg(arg1)

void init_pre_allocated_memory_0arg (void);
void init_pre_allocated_memory_1arg (int);
void alloc_pre_allocated_memory (void);
void set_pre_allocated_max_memory_size (int);
int find_fit_slab_index(int);
void *pre_allocated_memory_alloc(int);

#endif
