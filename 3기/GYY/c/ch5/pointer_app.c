#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/*
배열 길이를 랜덤으로 할당한다.
배열에 랜덤한 아스키 코드를 배치한다.
이 배열에서 소문자 a가 몇 번 등장했는지 파악하는 코드를 작성해보자!
*/


int rand_len_alloc(void)
{
	return rand()%129+128;
}

char *char_memory_alloc(int len)
{
	//malloc() : heap에 메모리를 할당
	//괄호 내부에 계산된 숫자만큼 메모리 할당
	//malloc은 void *를 리턴하므로 필요에 따라 형변환이 필요하다.
	//void *는 뭐든지 다 저장할 수 있는 특수한 데이터타입
	//저장은 가능하지만 이것으로 뭔가를 할 수 없으므로 
	//필요에 따라 사용 방식에 맞는 형변환이 필요한 것임
	return (char *)malloc(sizeof(char) * len+1);
	//+1 자리에 여기가 끝이다 '\0'을 넣어준다.
}

void rand_ascii_alloc(char *arr, int len)
{
	int i;

	for(i=0;i<len;i++)
	{
		//rand()%2 ? arr[i] = rand()%26+65 : arr[i]%26+97;
		if(rand() % 2)
		{
			arr[i]=rand()%26 + 65;
		}
		else
		{
			arr[i]=rand()%26 + 97;
		}
	}
	arr[i]='\0';// NULL이 들어감
}

int check_string(char *arr, char chk)
{
	int arr_len = strlen(arr);
	// arr 문자열의 길이를 구해옴
	int i;
	int cnt=0;

	for(i=0;i<arr_len;i++)
	{
		if(arr[i] == chk)
		{
			cnt++;
		}
	}
	return cnt;

}

/*
int check_string2(char *arr, char chk)
{
        int arr_len = strlen(arr);
        // arr 문자열의 길이를 구해옴
        int i;
        int cnt=0;
	// '\0'은 NULL -> 이것은 거짓
	// 그러므로 배열의 끝까지 도달 했다면 종료하라는 뜻
        for(i=0;arr[i];i++)
        {
                if(arr[i] == chk)
                {
                        cnt++;
                }
        }
        return cnt;

}

*/
int main(void)
{
	//랜덤 길이
	//1. 랜덤한 길이는 얼마로 설정할지
	//2. 랜덤한 길이의 배열할당(malloc : memory allocation => heap)
	//3. char * 를 활용
	//4. 랜덤 아스키코드 할당
	//5. 'a' 개수 검사	

	char *rand_ascii_arr = NULL;
	int rand_len;
	int cnt;

	char chk_char = 'a';
       	srand(time(NULL));

	rand_len = rand_len_alloc();
	rand_ascii_arr=char_memory_alloc(rand_len);
	
	rand_ascii_alloc(rand_ascii_arr, rand_len);
	// 왜 이렇게 가능한거지 ?
	// %s는 일반적으로 '문자열 출력'으로 알고 있다
	// 사실 %s는 char *로 되어 있는 문자들을 '\0'을 만날때까지 출력한다.
	printf("%s\n", rand_ascii_arr);

	cnt = check_string(rand_ascii_arr, chk_char);
	printf("현재 문장에 %c는 %d개 있다.\n", chk_char, cnt);

	return 0;
}
