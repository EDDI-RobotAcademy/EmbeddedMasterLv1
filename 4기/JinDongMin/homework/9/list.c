// 동적 할당을 사용하지 않음
#include <stdio.h>

enum {
    INT,
    DOUBLE,
    STRING
};

typedef struct _linked_list_item linked_list_item;
struct _linked_list_item
{
    void *element;  // 값
    int identifier; // 식별자
    linked_list_item *link; // 다음 list_item의 주소
};

void print_element(linked_list_item item)
{
    void *element = item.element;
    int identifier = item.identifier;

    switch (identifier)
    {
    case INT:
        printf("%d", *(int *)element);
        break;
    
    case DOUBLE:
        printf("%f", *(double *)element);
        break;
    
    case STRING:
        printf("%s", (char *)element);
        break;
    }
}

// 배열이 아닌 link로 계속 접근해서 출력하는 함수
void print_list(linked_list_item *list_ptr)
{
    linked_list_item item = *list_ptr;

    printf("[");

    while (1)
    {
        print_element(item);

        // 다음 item이 없으면 탈출
        if (item.link == NULL)
        {
            break;
        }

        // 다음 item이 있으면 next_item 갱신
        item = *(item.link);

        printf(", ");
    }

    printf("]");
}

// 연결 리스트가 되도록 연결하는 함수
void link_pointer_of_each_item(linked_list_item items[], int item_len)
{
    // item_len이 1일 경우 for문의 초기식조차 실행되지 않으므로 여기서 초기화
    int i = 0;

    // n개의 아이템 중에서 n-1번만 연결시키면 연결 리스트 완성!
    for (; i < item_len - 1; i++)
    {
        items[i].link = &(items[i + 1]);
    }
    items[i].link = NULL;
}

int main(void)
{
    int a;
    double b;

    // 첫 번째 리스트
    a = 5;
    b = 3.7;
    linked_list_item list1[] = {
        { &a, INT },
        { "안녕", STRING },
        { "LIG넥스원 초봉 4,700만원으로 가고싶다", STRING },
        { &b, DOUBLE }
    };
    int list_len = sizeof(list1) / sizeof(linked_list_item);

    link_pointer_of_each_item(list1, list_len);
    
    print_list(list1);
    printf("\n");

    // 두 번째 리스트
    a = 100;
    b = 15.33;
    linked_list_item list2[] = {
        { "Apple", STRING },
        { &a, INT },
        { &b, DOUBLE }
    };
    list_len = sizeof(list2) / sizeof(linked_list_item);

    link_pointer_of_each_item(list2, list_len);

    print_list(list2);
    printf("\n");

    return 0;
}