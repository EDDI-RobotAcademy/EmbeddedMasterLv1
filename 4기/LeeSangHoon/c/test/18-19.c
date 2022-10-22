#if 0
사원이 5명 있다. (이름은 적당히 작성한다)
5명의 사원의 초봉은 3500이다.
이 회사는 초고도로 발달되어 1000년후의 미래 기술을 가지고 있다고 가정한다.
그래서 코드 의존성, 생산성, 스레드 안정성, 고성능등의 지표를 수치화 할 수 있다고 한다.
해당 사항을 토대로 매번 연봉 계약을 다시 하는 시스템을 가지고 있다고 한다. (잘하면 높여주는 속도가 빠름)
의존성은 낮을수록 좋고, 생산성, 스레드 안정성, 고성능은 높을수록 좋다.

생산성이 높다는 것 = 의존성이 낮고, 스레드 안정성 ?, 고성능 ?
생산성이 낮다는 것 = 의존성이 높고, 스레드 안정성 ?, 고성능 ?

안정성이 높다는 것 = 의존성 ?, 스레드 안정성 높고, 고성능 ?
안정성이 낮다는 것 = 의존성 ?, 스레드 안정성 낮고, 고성능 ?

탁월한 성능 - 의존성 ?, 스레드 안정성 ?, 고성능
노오답 성능 - 의존성 ?, 스레드 안정성 ?, 저성능

생산성, 안정성, 성능 중에 무엇을 더 우선할 것인가 ?
시장 선점, 유지보수, 지속적인 피드백을 고려할 경우 생산성에 높은 가중치 부여

안정성 측면은 결국 유지보수 및 서비스 품질을 결정하므로
이 문제는 고객들의 반응과 직결될 수 있는 또 다른 문제
생산성과 안정성을 비교 했을때 일반 서비스라면
생산성, 사람 목숨이 달렸다면 안정성 비중이 더 크다.
그렇더라도 둘 다 매우 중요한 속성이므로 아주 약간씩 조절을 해주면 된다고 봄.

성능적인 측면은 과거엔 그냥 좋으면 좋은 수준이였지만
대규모 서비스를 한다면 성능 또한 서비스 품질과 직결되는 요소다.
사람 목숨과 직결된 경우에도 이 요소는 매우 중요한 요소가 됩니다.
서비스 업체 < 타임 크리티컬 제품으로 제품 특성별로 꽤 큰 차이를 가집니다.

기준은 어디까지나 제 기준입니다.

      서비스            타임 크리티컬 제품

생산성 계수 = 3.7		생산성 계수 = 3.3
안정성 계수 = 3.3		안정성 계수 = 4.0
성능 계수   = 2.5       성능 계수   = 3.5

좀 더 세부적으로 본다면 업무량과 업무 난이도에 대한
분석도 필요하겠지만 거기까지 고려하지 않겠습니다.
(적당히 랜덤하게 생성)

또한 이 문제는 타임 크리티컬 제품이라 가정

상승된 연봉 = 작년 연봉 + (작년연봉 / 100) * (생산성 계수 + 안정성 계수 + 성능 계수) * (업무량 * 난이도 계수 / 40)
ex) 4634 = 3500 + 35 * 10.8 * 3 <-- 최대값은 3보다 더 큼
    6135 = 4634 + 46.34 * 10.8 * 3

(이게 사실 짬 따라서 또 상승 비율 조정이 필요한데 일단 그냥 고)
#endif

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _workload workload;

struct _workload
{
	float difficulty;
	int amount;
};

typedef struct _employee emp;

struct _employee
{
	char name[32];
	int pay;

	workload *work_quality;
};

#define PRODUCTIVITY			3.3f
#define SAFETY					4.0f
#define PERFORMANCE				3.5f

char name[5][32] = { "이경수", "박지완", "강지훈", "김지환", "조민현" };

emp *init_employee(void)
{
	int i;

	emp *tmp = (emp *)malloc(sizeof(emp) * 5);

	for (i = 0; i < 5; i++)
	{
		strcpy(tmp[i].name, name[i]);
		tmp[i].pay = rand() % 501 + 3000;

		tmp[i].work_quality = (workload *)malloc(sizeof(workload));
		tmp[i].work_quality->difficulty = (rand() % 15 + 1) / 10.0f;
		tmp[i].work_quality->amount = rand() % 91 + 30;
	}

	return tmp;
}

void print_employee(emp *e)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("name = %s, pay = %d\n", e[i].name, e[i].pay);
	}
}

void years_ago(emp *e, int year)
{
	int i, j;

	for (i = 0; i < year; i++)
	{
		printf("%d 년차\n", i + 1);

		for (j = 0; j < 5; j++)
		{
			e[j].work_quality->difficulty = (rand() % 15 + 1) / 10.0f;
			e[j].work_quality->amount = rand() % 91 + 30;
			printf("name = %s, work mount = %d, work_difficulty = %.1f\n",
				e[j].name, e[j].work_quality->amount, e[j].work_quality->difficulty);

			// 작년 연봉 + (작년연봉 / 100) * (생산성 계수 + 안정성 계수 + 성능 계수) * (업무량 * 난이도 계수 / 40)
			e[j].pay = e[j].pay + (e[j].pay / 100.0) * (PRODUCTIVITY + SAFETY + PERFORMANCE) *
											e[j].work_quality->amount * e[j].work_quality->difficulty / 40.0;
		}

		print_employee(e);
	}
}

emp find_max(emp *e)
{
	int i, max_idx, max = 0;

	for (i = 0; i < 5; i++)
	{
		if (max < e[i].pay)
		{
			max = e[i].pay;
			max_idx = i;
		}
	}

	return e[max_idx];
}

int main(void)
{
	emp max;

	srand(time(NULL));

	emp *e = init_employee();

	print_employee(e);

	years_ago(e, 10);

	max = find_max(e);
	printf("10년후 가장 연봉이 높은 사원은 %s, %d\n", max.name, max.pay);

	return 0;
}
