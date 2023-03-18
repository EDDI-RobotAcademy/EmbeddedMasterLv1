#include <stdio.h>
#include <string.h>

void convert_string_to_lower_case(char str[])
{
    int i;
    int str_len = strlen(str);

    for (i = 0; i < str_len; i++)
    {
        if (('A' <= str[i]) && (str[i] <= 'Z'))
        {
            str[i] ^= 0x20;
        }
    }
}

int main(void)
{
    char str[] = "EMBEDDED_MASTER";
    puts(str);

    convert_string_to_lower_case(str);
    puts(str);

    return 0;
}