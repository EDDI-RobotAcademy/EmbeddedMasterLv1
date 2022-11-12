/*8. 이 세상에는 많은 종류의 수열이 존재합니다.

   피보나치 수열이 있고, 등차 수열, 등비 수열 등등 여러가지가 있습니다.

   또한 등차, 등비의 경우엔 소수점을 취급할 수도 있습니다.

   (복소수 시스템까지 도입하면 난이도가 너무 높아지니 복소수는 제외하겠습니다)

   어떤 상황에서든 원하는 크기의 원하는 공비나 공차,

   특정 시스템을 기반으로한 수열을 생성할 수 있는 Series Generator를 만들어봅시다!

공비수열 (등차수열)
https://zetawiki.com/wiki/%EB%93%B1%EB%B9%84%EC%88%98%EC%97%B4
공차수열
https://zetawiki.com/wiki/%EB%93%B1%EB%B9%84%EC%88%98%EC%97%B4
피보나치수열
https://zetawiki.com/wiki/%ED%94%BC%EB%B3%B4%EB%82%98%EC%B9%98_%EC%88%98

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define COMMON_DIFFERENCE    1
#define COMMON_RATIO         2
#define FIBONACCI_SEQUENCE   3

void common_ratio_generation()//공차 수열
{
    float start;
    int finish, r;
    int i = 0;
    float* result;

    printf("시작 숫자를 입력해주세요\n");
    scanf("%f",&start);
    printf("항 수를 입력해주세요\n");
    scanf("%d",&finish);
        printf("등비를 입력해주세요\n");
    scanf("%d",&r);
    result = malloc(sizeof(float*)*finish);
    for(i; i<finish; i++)
    {
        start *= r;
        result[i] = start;


        printf("%d번째항은 %0.2f\n",(i + 1) , result[i]);
    }
}

void common_difference_generation()//공비 수열
{
    float start;
    int finish, d;
    int i = 0;
    float* result;

    printf("시작 숫자를 입력해주세요\n");
    scanf("%f",&start);
    printf("항 수를 입력해주세요\n");
    scanf("%d",&finish);
    printf("등차를 입력해주세요\n");
    scanf("%d",&d);
    result = malloc(sizeof(float*)*finish);
    for(i; i<finish; i++)
    {
        result[i] = start;
        start -= d;
        
        printf("%d번째항은 %0.2f\n",(i + 1) , result[i]);
    }

}
void fibonacci_sequence_generation()//피보나치 수열
{
    int start, finish, number;
    int *result;
    int i = 0;
    start = 1;

    result = malloc(sizeof(int*)*number);
    
    printf("만들 수를 입력해주세요\n");
    scanf("%d",&number);    
    for(i; i< number; i++)
    {
        if(i == 0)
        {
            result[i] = start;
        }

        else if(i == 1)
        {
            result[i] = result[i - 1];
        }

        else
        {
            result[i] = result[i - 1] + result[i - 2];
        }

        printf("%d번째 항은 %d\n",(i + 1), result[i]);
    }
}

void recv_command_from_pc(int command)
{
    switch(command)
    {
        case COMMON_DIFFERENCE:
            printf("common_difference_generation\n");
            common_difference_generation();
        break;

        case COMMON_RATIO:
             printf("common_ratio_generation\n");
            common_ratio_generation();
        break;

        case FIBONACCI_SEQUENCE:
            printf("fibonacci_sequence_generation\n");
            fibonacci_sequence_generation();
        break;
        
        default:
        break;
    }
}

int main (void)
{
    int command;
    while(1)
    {
        printf("Series Generator\n");
        printf("Select Menu\n");
        printf("1 : common_difference_generation\n");
        printf("2 : common_ratio_generation\n");
        printf("3 : fibonacci_sequence_generation\n");
        scanf("%d", &command);
        recv_command_from_pc(command);
        printf("\n");
    }


    return 0;
}