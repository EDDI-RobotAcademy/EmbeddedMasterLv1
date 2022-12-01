/*
사원이 5명 있다. (이름은 적당히 작성한다) 

5명의 사원의 초봉은 3500이다. 

이 회사는 초고도로 발달되어 1000년후의 미래 기술을 가지고 있다고 가정한다.

그래서 코드 의존성, 생산성, 스레드 안정성, 고성능등의 지표를 수치화 할 수 있다고 한다.

해당 사항을 토대로 매번 연봉 계약을 다시 하는 시스템을 가지고 있다고 한다. (잘하면 높여주는 속도가 빠름)

의존성은 낮을수록 좋고, 생산성, 스레드 안정성, 고성능은 높을수록 좋다.

​

18. 각각의 의존성, 생산성, 스레드 안정성, 고성능 등의 값은 랜덤으로 배치하고

적정 기준을 세워 연봉 협상을 진행해주도록 한다.

(이 기준은 마음대로 세우세요)

​

19. 연봉 협상이 진행될 때마다 5명의 사원들의 연봉 협상 성과와

이에 대한 통계수치를 기록하도록 구성한다.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "main.h"


void init_employee (employee_handler *em_handler)
{
    employee *empl;
    int i = 0;
    char *name[5] = {"김둘리", "도우너", "김또치", "마이콜", "고길동"};
    int str_len = 0;
    empl = (employee*)malloc(sizeof(employee));
    for(i; i< EMPLOYEE_NUMBER; i++)
    {
        str_len = strlen(name[i]);
        //empl->name = (char*) malloc(sizeof(char) * (str_len + 1));
        
        /*
        //employee선언 사용 에러 없음
        strncpy(empl->name , name[i], str_len);
        empl->annual_income = 3500;
        printf("%s, %d \n",empl->name , empl->annual_income);
        */

        //employee_handler 사용 세그먼트 폴트 에러 발생..?
        
        em_handler->empl_array[i].name = (char*) malloc(sizeof(char) * (str_len + 1));
        strncpy(em_handler->empl_array[i].name , name[i], str_len);
        em_handler->empl_array[i].annual_income = 3500;
        printf("%s, %d \n",em_handler->empl_array[i].name , em_handler->empl_array[i].annual_income);
        

    }
    

}

void random_generator_business_score (employee_handler *em_handler)
{
    
    employee *empl;
    int business_score = 0;
    int i = 0;
    
    empl = (employee*)malloc(sizeof(malloc));
    for(i; i< EMPLOYEE_NUMBER; i++)
    {
        //em_handler->empl_array[i]->business_score = business_score = rand() % (BUSINESS_SCORE_MAX  - BUSINESS_SCORE_MIN + 1) + BUSINESS_SCORE_MIN;
        //printf("em_handler->empl_array[%d]->business_score :%d\n", i, em_handler->empl_array[i]->business_score);

        em_handler->empl_array[i].business_score = rand() % (BUSINESS_SCORE_MAX  - BUSINESS_SCORE_MIN + 1) + BUSINESS_SCORE_MIN;
        //printf("em_handler->empl_array[%d]->business_score :%d\n", i, empl->business_score);
        //em_handler->empl_array[i]->business_score = empl->business_score;
    }
    
}

void evaluation_employee (employee_handler *en_handler)
{
    
    int i = 0;
    static int j = 0;
    for(i; i < EMPLOYEE_NUMBER; i++)
    {
        switch(en_handler->empl_array[i].business_score)//en_handler->empl_array[i]->business_score)
        {
            case BUSINESS_SCORE_A:
                en_handler->empl_array[i].before_income[j] = en_handler->empl_array[i].annual_income;
                en_handler->empl_array[i].annual_income *= INCRESE_PESENT_SCORE_A;
                //en_handler->empl_array[i].before_income[i] = en_handler->empl_array[i].annual_income;
                //en_handler->empl_array[i].annual_income *= INCRESE_PESENT_SCORE_A;
                break;

            case BUSINESS_SCORE_B:
                en_handler->empl_array[i].before_income[j] = en_handler->empl_array[i].annual_income;
;
                en_handler->empl_array[i].annual_income *= INCRESE_PESENT_SCORE_B;
                break;

            case BUSINESS_SCORE_C:
                en_handler->empl_array[i].before_income[j] = en_handler->empl_array[i].annual_income;
                en_handler->empl_array[i].annual_income *= INCRESE_PESENT_SCORE_C;
                break;

            case BUSINESS_SCORE_D:
                en_handler->empl_array[i].before_income[j] = en_handler->empl_array[i].annual_income;
                en_handler->empl_array[i].annual_income *= INCRESE_PESENT_SCORE_D;
                break;

            case BUSINESS_SCORE_E:
                en_handler->empl_array[i].before_income[j] = en_handler->empl_array[i].annual_income;
                en_handler->empl_array[i].annual_income *= INCRESE_PESENT_SCORE_E;
                break;

            case BUSINESS_SCORE_F:
                en_handler->empl_array[i].before_income[j] = en_handler->empl_array[i].annual_income;
                en_handler->empl_array[i].annual_income *= INCRESE_PESENT_SCORE_F;
                break;

            default:

                break;
        }
        
    }
    j++;
    
}


void print_employee_income (employee_handler *em_handler)
{
    int i = 0;
    static int j = 0;
    for(i; i < EMPLOYEE_NUMBER; i++)
    {
        printf("%d년차 %s의 직전연봉은 %d 현재 연봉은 %d입니다.\n", j + 1, em_handler->empl_array[i].name, em_handler->empl_array[i].before_income[j], em_handler->empl_array[i].annual_income);
    }
    printf("\n");
    
    j++;
}



employee_handler *allocate_employee_handler(void)
{
    employee_handler *em_handler;
    employee_handler_metod_table *tbl = NULL;
    int i = 0;

    //empoyee_handler 동적 할당
    em_handler = (employee_handler*)malloc(sizeof(employee_handler) + sizeof(employee) * EMPLOYEE_NUMBER);
    if(em_handler == NULL)
    {
        printf("empoyee_handler 동작할당 실패\n");
        exit(-1);
    }

    //_employee_metod_table table 동적 할당
    tbl = (employee_handler_metod_table*)malloc(sizeof(employee_handler_metod_table));
    tbl->init_employee = init_employee;
    tbl->random_generator_business_score = random_generator_business_score;
    tbl->print_employee_income = print_employee_income;
    tbl->evaluation_employee = evaluation_employee;
    em_handler->tbl = tbl;
    if(tbl ==NULL)
    {
        printf("_employee_metod_table 동작할당 실패\n");
        exit(-1);
    }
    em_handler->empl_array = (employee*)malloc(sizeof(employee) * EMPLOYEE_NUMBER);

    return em_handler;
}
int main (void)
{
    static int num;
    srand(time(NULL));
    employee_handler *em_handler;
    printf("시뮬레이션 할 연차를 입력하세요 (최대 10년)\n");
    scanf("%d",&num);
    
    em_handler = allocate_employee_handler();
    em_handler->tbl->init_employee(em_handler);
    while(num)
    {
        em_handler->tbl->random_generator_business_score(em_handler);
        em_handler->tbl->evaluation_employee(em_handler);
        em_handler->tbl->print_employee_income(em_handler);
        num--;
    }
    return 0;
}