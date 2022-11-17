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

#define PERSON_NUMBER   5
#define PERSON      (PERSON_NUMBER + 1)

#define GRADE_A     6
#define GRADE_B     5
#define GRADE_C     4
#define GRADE_D     3
#define GRADE_E     2
#define GRADE_F     1

#define GRADE_MIN   1
#define GRADE_MAX   6

#define RATE_OF_INCREASE_PERCENT     RATE_OF_INCREASE / 100
#define RATE_OF_INCREASE    10

#define RATE_RISE_ANNUAL_INCOME_A       (GRADE_A * RATE_OF_INCREASE_PERCENT) 
#define RATE_RISE_ANNUAL_INCOME_B       (GRADE_B * RATE_OF_INCREASE_PERCENT)
#define RATE_RISE_ANNUAL_INCOME_C       (GRADE_C * RATE_OF_INCREASE_PERCENT)
#define RATE_RISE_ANNUAL_INCOME_D       (GRADE_D * RATE_OF_INCREASE_PERCENT)
#define RATE_RISE_ANNUAL_INCOME_E       (GRADE_E * RATE_OF_INCREASE_PERCENT)
#define RATE_RISE_ANNUAL_INCOME_F       (GRADE_F * RATE_OF_INCREASE_PERCENT)


typedef struct _Person person;
struct _Person
{
    char* name;
    int annual_income;
    int grade;
};

person* init_person()
{
    person *data = NULL;
    char *name[5] = {"김둘리", "김또치", "마이콜", "고길동", "도우너"};
    int i, j = 0;

    data = (person*)malloc(sizeof(person*) * PERSON);

    printf("in\n");

    for(i; i < PERSON; i++)
    {
        printf("for name malloc in %d\n", i);
        data[i].name = (char *)malloc(sizeof(char *) * 10);
    }


    //data[0].name = "김둘리";
    data[0].name = name[0];
    //data[1].name = "김또치";
    data[1].name = name[1];
    //data[2].name = "마이콜";
    data[2].name = name[2];
    //data[3].name = "고길동";
    data[3].name = name[3];
    //data[4].name = "도우너";
    data[4].name = name[4];

    printf("%s\n",data[0].name);
    printf("%s\n",data[1].name);
    printf("%s\n",data[2].name);
    printf("%s\n",data[3].name);
    printf("%s\n",data[4].name);

    printf("\n\n");


    for(j; j < PERSON; j++)
    {
        printf("j = %d\n", j);
        data[j].annual_income = 3500;
        printf("j : %d\n", j);
        //printf("%s\n", data[j].name);
        printf("%d\n", data[j].annual_income);
    }
    


    return data;
}

person* random_grade_generate(int min, int max, person **data)
{
    int i = 0;
    for(i; i < PERSON; i++ )
    {
        (*data[i]).grade = rand() % (max -min + 1) + 1;        
    }
    printf("%d\n",(*data[0]).grade);
    printf("%d\n",(*data[1]).grade);
    printf("%d\n",(*data[2]).grade);
    printf("%d\n",(*data[3]).grade);
    printf("%d\n",(*data[4]).grade);


    return (*data);
}
person* person_grade_assessment(person **data)
{
    int i = 0;

    for(i; i < PERSON; i++)
    {
        switch(data[i]->grade)
        {
            case GRADE_A:
                (*data)[i].annual_income *=  RATE_RISE_ANNUAL_INCOME_A;
            break;

            case GRADE_B:
                (*data)[i].annual_income *=  RATE_RISE_ANNUAL_INCOME_A;
            break;

            case GRADE_C:
                (*data)[i].annual_income *=  RATE_RISE_ANNUAL_INCOME_A;
            break;

            case GRADE_D:
                (*data)[i].annual_income *=  RATE_RISE_ANNUAL_INCOME_A;
            break;

            case GRADE_E:
                (*data)[i].annual_income *=  RATE_RISE_ANNUAL_INCOME_A;
            break;

            case GRADE_F:
                (*data)[i].annual_income *=  RATE_RISE_ANNUAL_INCOME_A;
            break;

            // default;

        }

    }    
    return (*data);
}

void print_annual_income(person **data, person **new_data)
{

}
int main (void)
{
    srand(time(NULL));
    person *data;
    person *new_data;
    data = malloc(sizeof(person * ) * PERSON);
    
    new_data = malloc(sizeof(person * ) * PERSON);
    data = init_person();
    data = random_grade_generate(GRADE_MIN, GRADE_MAX, &data);
    
    new_data = person_grade_assessment(&data);
    print_annual_income(&data, &new_data);;
    //printf("data[0].grad : %d\n", data[0].grade);
    /*
    printf("%s\n",data[0].name);
    printf("%s\n",data[1].name);
    printf("%s\n",data[2].name);
    printf("%s\n",data[3].name);
    printf("%s\n",data[4].name);
    */
    return 0;
}