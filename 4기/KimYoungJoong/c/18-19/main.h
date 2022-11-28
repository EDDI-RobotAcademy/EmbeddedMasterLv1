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

#define EMPLOYEE_NUMBER   5

#define GRADE_A     1
#define GRADE_B     2
#define GRADE_C     3
#define GRADE_D     4
#define GRADE_E     5
#define GRADE_F     6

#define GRADE_MIN   1
#define GRADE_MAX   6




typedef struct _employee    employee;
typedef struct _employee_handler_metod_table    employee_handler_metod_table;
typedef struct _employee_handler employee_handler;

struct _employee
{
    char *name;
    int annual_income;
    int before_income;
    int business_score;
};

struct _employee_handler_metod_table
{
    void( *init_employee)(employee_handler *em_handler);
    void( *random_generator_business_score)(employee_handler *em_handler);
    void( *print_employee_income)(employee_handler *em_handler);
    
};

struct _employee_handler
{
    employee_handler_metod_table *tbl;

    employee *empl_array[0];
};

