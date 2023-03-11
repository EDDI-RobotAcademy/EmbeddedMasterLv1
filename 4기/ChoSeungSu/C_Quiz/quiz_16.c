#include <stdio.h>


void conversion_big_to_small(char *str)
{
    int i ;

    for (i=0; str[i]; i++)
    {
        if (str[i]> 64 && str[i]<92)
        {
            str[i] ^= 0x20;
            // XOR 을 통해 소문자 대문자 토글하는 방법 !!
        }
    }
}




int main(void)
{
    char str[] = "whErE aRe You FRom?";
    printf("origin : %s\n", str);
    conversion_big_to_small(str);
    printf("conversion: %s\n", str);
}