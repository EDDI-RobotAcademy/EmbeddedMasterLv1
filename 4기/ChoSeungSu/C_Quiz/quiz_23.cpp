#include <stdio.h>
#include <malloc.h>

#define success 1

typedef struct People
{
    char name[10];
    unsigned short int age;
    char number[15];
    char addr[30] ;
    // 거주지는 포인터 변수로 받고 동적할당으로 하면 더 좋을거 같은데 구현을 못하겠슴.
    // 현재 구조체 포인터를 통해 입력하기 때문에 포인터를 사용하려면 이차원 포인터와 동적할당 개념을 같이 사용해야 구현이 가능하지 않을까 짐작.  
} Person;

int AddFriend(Person *p_person)
{
    printf("회원 이름을 입력하세요: \n");
    scanf("%s" , p_person -> name);
    printf("나이를 입력하세요: \n");
    scanf("%hu", &p_person ->age);
    printf("전화번호를 입력하세요: \n");
    scanf("%s" , p_person -> number);
    printf("거주지를 입력하세요 : \n");
    scanf("%s" , p_person->addr);
    return success;
}

void ShowPersonList(Person *p_person)
{
    if (10< p_person->age <20)
    {
        printf("20대\n");
        printf("%s , %d , %s , %s\n" , p_person->name, p_person->age, p_person->number, p_person->addr);
    }

    else if (20<= p_person->age <30)
    {
        printf("20대\n");
        printf("%s , %d , %s , %s\n" , p_person->name, p_person->age, p_person->number, p_person->addr);
    }

    else if (30<= p_person->age <40)
    {
        printf("20대\n");
        printf("%s , %d , %s , %s\n" , p_person->name, p_person->age, p_person->number, p_person->addr);
    }

    else
    { 
        printf("확인할 수 없는 나이입니다\n");
    }
}

int main()
{   
    Person person;
    AddFriend(& person);

    if (success) ShowPersonList(& person); 

    return 0;
}


