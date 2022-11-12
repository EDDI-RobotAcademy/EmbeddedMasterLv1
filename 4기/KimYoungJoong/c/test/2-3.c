#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _info INFO;

struct _info
{
   char* name;
   int age;
   char* address;
   char* hp;
   int index;
};


INFO* write_info()
{
    INFO *data;
    data = (INFO * )malloc(sizeof(INFO)*1);
    data->name = (char *)malloc(sizeof(char)*10);
    //data->age = (int *)malloc(sizeof(int));
    data->address = (char *)malloc(sizeof(char)*20);
    data->hp = (char *)malloc(sizeof(char)*20);
    //printf("write_info in\n");

    printf("이름을 입력하세요 : ");
    scanf("%s", data[0].name);
    printf("나이을 입력하세요 : ");
    scanf("%d", &data[0].age);
    printf("주소을 입력하세요 : ");
    scanf("%s", data[0].address);
    printf("전화번호을 입력하세요 : ");
    scanf("%s", data[0].hp);

    return data;
}
INFO find_info(INFO **data, int command, int cnt)
{
    int i = 0;

    int age = command *10;


    switch(age)
    {
        case 10:
            printf("10대 회원 출력\n");
            for(i; i < cnt; i++)
            {
                if(data[i]->age / age == 1)
                {
                    printf("이름 : %s\n",data[i]->name);
                    printf("나이 : %d\n",data[i]->age);
                    printf("주소 : %s\n",data[i]->address);
                    printf("전화번호 : %s\n",data[i]->hp);
                    printf("\n");
                }
            }
            
        break;

        case 20:
            printf("20대 회원 출력\n");
            for(i; i < cnt; i++)
            {
                if(data[i]->age / age == 2)
                {
                    printf("이름 : %s\n",data[i]->name);
                    printf("나이 : %d\n",data[i]->age);
                    printf("주소 : %s\n",data[i]->address);
                    printf("전화번호 : %s\n",data[i]->hp);
                    printf("\n");
                }
            }
        break;
            
        case 30:
            printf("30대 회원 출력\n");
            for(i; i < cnt; i++)
            {
                if(data[i]->age / age == 3)
                {
                    printf("이름 : %s\n",data[i]->name);
                    printf("나이 : %d\n",data[i]->age);
                    printf("주소 : %s\n",data[i]->address);
                    printf("전화번호 : %s\n",data[i]->hp);
                    printf("\n");
                }
            }
        break;

        case 40:
            printf("모든 회원 출력\n");
            for(i; i < cnt; i++)
            {
                    printf("이름 : %s\n",data[i]->name);
                    printf("나이 : %d\n",data[i]->age);
                    printf("주소 : %s\n",data[i]->address);
                    printf("전화번호 : %s\n",data[i]->hp);
                    printf("\n");
            }
        break;
        
        
        default:
        break;
    }



}
int main (void)
{
   INFO *data;
   INFO *tmp;
   int size = 10;
   data = (INFO*)malloc(sizeof(INFO) * size);
   data = (INFO*)malloc(sizeof(INFO) * 1);
    int command = 0;
    static int cnt = 0;
   while(1)
   {

        printf("총 10명 입력 가능\n");
        printf("10명 중 %d명 입력중\n", cnt);
        printf("메뉴를 입력하세요\n");
        printf("0 : 회원 입력\n");
        printf("1 : 10대 출력\n");
        printf("2 : 20대 출력\n");
        printf("3 : 30대 출력\n");
        printf("4 : 모두 출력\n");
        scanf("%d", &command);
        if(command == 0)
        {
             tmp = write_info();

             data[cnt].name = tmp->name;
             data[cnt].age = tmp->age;
             data[cnt].address = tmp->address;
             data[cnt].hp = tmp->hp;
             cnt++;

             printf("cnt : %d\n", cnt);
             //printf("tmp.name : %s\n",tmp->name);
             //printf("data.name : %s\n",data[0].name);
        }
        else if(command == 1 | 2 | 3 | 4)
        {
            find_info(&data, command, cnt);
        }
        
   }
   return 0;
}
