#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rand_len_alloc(void)
{
	return rand()%129+128;
}

char *char_memory_alloc(int len)
{
	return (char *)malloc(sizeof(char)*len+1);
}

void rand_ascii_alloc(char *arr, int len)
{
	int i;

	for(i=0;i<len;i++)
	{
		if(rand()%2)
		{
			arr[i]=rand()%26+65;
		}
		else
		{
			arr[i]=rand()%26+97;
		}
	}
	arr[i]='\0';
}

int check_string(char *arr, char chk)
{
	int i;
	int cnt=0;

	for(i=0;arr[i];i++)
	{
		if(arr[i]==chk)
		{
			cnt++;
		}
	}
	return cnt;
}

int main(void)
{
	char *rand_ascii_arr = NULL;
	int rand_len;
	int cnt;

	char chk_char='a';
	srand(time(NULL));
	rand_len = rand_len_alloc();
	rand_ascii_arr = char_memory_alloc(rand_len);

	rand_ascii_alloc(rand_ascii_arr, rand_len);

	printf("%s\n", rand_ascii_arr);
	cnt = check_string(rand_ascii_arr, chk_char);
	printf("현재 문장에 %c는 %d개 있다.\n", chk_char, cnt);

	return 0;

}
