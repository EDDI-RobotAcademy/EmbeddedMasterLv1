#include <stdio.h>
#include <stdlib.h>

// typedef 는 실제 C 타입을
// 우리가 원하는 간소화된 타입으로 변경하는 작업을 지원함
typedef struct array_list list;

// 이 부분이 실제 구조체에 해당함
// 구조체란 무엇인가 ?
// 구조체를 사용하는 이유가 무엇인가 ?
// 1) 묶어서 관리하기가 좋다
// 2) 작동 원리를 몰라도 결과만 뽑아쓰기 좋음
// 왜라는 부분의 답변이 되기는 어렵습니다.
// 우리만의 새로운 데이터타입을 만들었다.
// 즉 커스텀 데이터 타입을 마들 수 있다. <<<--- 이 부분이 핵심

// 커스텀이라는 부분을 제외하더라도 
// 가장 중요한 부분은 결론적으로 이 구조체라는 것이 데이터타입이란 것이다.

// 결론 : 구조체는 데이터타입이므로 변수나 배열등을 만들때
// 	  적용하였던 규칙이 그대로 적용될 수 있다는 것을 상기하면 됨

struct array_list
{
	int data;
	struct array_list *link; // struct 타입 변수의 주소값을 저장하는 공간을 의미?
};

void print_list_struct(list target)
{
	// 구조체 내부에 접근할 때는 '.' 연산자를 활용합니다.
	// '.' 연산자는 구조체 내부에 접근하세요!
	// 라는 의미를 가지는 연산자
	printf("target.data = %d\n", target.data);
	printf("target.link = %d\n", target.link);
}

int main(void)
{
	// 1.
	struct array_list test1 = { 3, NULL };
	// 2.	
	list test2 = { 7, NULL };

	print_list_struct(test1);
	print_list_struct(test2);

	return 0;
}
