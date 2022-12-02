#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 구조체의 가장 중요한 개념 ?
// 1. 자료형을 새로 정의한다 -> 커스텀
// 2. 재활용 측면으로 사용
// 3. 행위의 일관성 측면의 클래스 설계 -> SRP 규칙
//    특정 동작을 수행함에 있어 일관성을 가지게 만들어라!

// 구조체를 구성할 때는 이런 개념(SRP)을 가지고 설계를 하면 좋다!

// 아래와 같이 구조체는 데이터타입을 만드는 작업
typedef struct _member
{
    char *name;
    int age;
} member;

#define MEMBER_ALLOC_FAIL       false
#define MEMBER_ALLOC_SUCCESS    true

bool init_member(member *account, char *name, int age)
{
    // 사실은 malloc이 fail이 발생할 수도 있음
    int name_length = strlen(name);
    char *tmp = (char *)malloc(sizeof(char) * (name_length + 1));

    if (tmp == NULL)
    {
        return MEMBER_ALLOC_FAIL;
    }
    
    account->name = tmp;
    strncpy(account->name, name, name_length);
    account->age = age;

    return MEMBER_ALLOC_SUCCESS;
}

void print_member(member account)
{
    printf("이름: %s\n", account.name);
    printf("나이: %d\n", account.age);
}

// 과제
void free_member(member account)
{
    free(account.name);
}

int main(void)
{
    int value;

    // 1. 변수 선언과 동일하게 구조체도
    //    구조체 타입을 작성한다.
    // 2. 변수 작성과 동일하게 구조체 변수 이름을 작성한다.
    struct _member account;

    // tip: typedef를 이용했으므로 아래와 같이 사용해도 무방하다.
    // struct _member를 member로 축약해서 사용하겠음을 의미함.
    member my_account = { };

    // 초기화하는 방법이 여러가지가 있는데, 보통은 아래와 같은 식으로 한다.
    if (init_member(&my_account, "gogo", 19) == MEMBER_ALLOC_FAIL)
    {
        printf("member 구조체 할당 실패!\n");
        exit(-1);
    }

    print_member(my_account);

    free_member(my_account);
    return 0;
}