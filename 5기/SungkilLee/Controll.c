#include <stdio.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS


long totalday(int y, int m, int d);

int main()
{
    int ty, tm, td , iy, im, id, oy, om, od, idates, odates;

    printf("사회복무요원 명단 : \n");
    printf("1. 이 준석 \n");
    printf("2. 이 성길 \n");
    printf("3. 이 준우 \n");
    printf("해당하는 사람의 숫자를 입력해 주세요 : ");

    int num = getchar();

    switch(num)
    {

        case '1' :
        {
            printf("\n< 다음의 형식으로 입력해 주세요 : 1994 4 7 > \n");
            printf("오늘 날짜를 입력해 주세요. :");
            scanf("%d %d %d", &ty, &tm, &td);

            iy = 2022;
            im = 3;
            id = 10;

            oy = 2023;
            om = 12;
            od = 9;

            idates = totalday(ty,tm,td) - totalday(iy,im,id);
            odates = totalday(oy,om,od) - totalday(ty,tm,td);

            printf("\n #### 군 복무 정보 #### \n");
            printf("이름 : 이 준석 \n");
            printf("생년월일 : 940201 \n");
            printf("핸드폰 번호 : 010-7464-4846\n");
            printf("입대일 : NA \n");
            printf("전역일 : NA \n");
            printf("복무 기간 : %d \n",idates+1);
            printf("\n### 전역까지 %d 일 남았습니다! ### \n",odates-1);


            break;
        }

        case '2' :
        {
            printf("\n< 다음의 형식으로 입력해 주세요 : 1994 4 7 > \n");
            printf("오늘 날짜를 입력해 주세요. :");
            scanf("%d %d %d", &ty, &tm, &td);

            iy = 2022;
            im = 3;
            id = 10;

            oy = 2023;
            om = 12;
            od = 9;

            idates = totalday(ty,tm,td) - totalday(iy,im,id);
            odates = totalday(oy,om,od) - totalday(ty,tm,td);

            printf("\n #### 군 복무 정보 #### \n");
            printf("이름 : 이 성길 \n");
            printf("생년월일 : 940407 \n");
            printf("핸드폰 번호 : 010-5453-3409\n");
            printf("입대일 : 22.03.10 \n");
            printf("전역일 : 23.12.09 \n");
            printf("복무 기간 : %d \n",idates+1);
            printf("\n### 전역까지 %d 일 남았습니다! ### \n",odates-1);


            break;
        }

        case '3' :
        {
            printf("\n< 다음의 형식으로 입력해 주세요 : 1994 4 7 >\n");
            printf("오늘 날짜를 입력해 주세요. :");
            scanf("%d %d %d", &ty, &tm, &td);

            iy = 2022;
            im = 6;
            id = 9;

            oy = 2024;
            om = 3;
            od = 8;

            idates = totalday(ty,tm,td) - totalday(iy,im,id);
            odates = totalday(oy,om,od) - totalday(ty,tm,td);

            printf("\n #### 군 복무 정보 #### \n");
            printf("이름 : 이 준우 \n");
            printf("생년월일 : 000415 \n");
            printf("핸드폰 번호 : 010-9950-6615\n");
            printf("입대일 : 22.06.09 \n");
            printf("전역일 : 24.03.08 \n");
            printf("복무 기간 : %d \n",idates+1);
            printf("\n### 전역까지 %d 일 남았습니다! ### \n",odates-1);

            break;
        }
    }
}

long totalday(int y, int m, int d){

        int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        int i;

        long total = 0L;

 

        total = (y - 1) * 365L + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;

        if (!(y % 4) && y % 100 || !(y % 400))

                 months[1]++;

        for (i = 0; i < m - 1; i++)

                 total += months[i];

        total += d;

 

        return total; //기념일일 경우 +1일 해준다.

}
