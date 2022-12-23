#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;

    char str[20] = "EMBEDDEDMASTER";
    int len = strlen(str);
    
    for (i = 0; i < len; i++)
    {
        str[i] ^= 0x20;
    }

    printf("str: %s\n", str);
    
    return 0;
}