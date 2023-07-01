#include "how_to_malloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _test_data test_data;
struct _test_data
{
    int age;
    char* name;
    struct _test_data* link;
};

void printf_malloced_data(test_data *pData)
{
    printf("age = %d \n", pData->age);
    printf("name = %s \n", pData->name);
    printf("link = 0x%x \n", pData->link);
}

void how_to_malloc_data(void)
{
    char name[10] = "안녕";
    int name_length = strlen(name);

    printf("동적 할당 테스트\n");

    test_data* malloced_data = (test_data *)malloc(sizeof(test_data));
    malloced_data->age = 10;
    
    malloced_data->name = (char*)malloc(name_length + 1);
    strncpy(malloced_data->name, name, name_length);

    malloced_data->link = NULL;

    printf_malloced_data(malloced_data);

    free(malloced_data);
}