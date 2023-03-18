#include<stdio.h>
#include<string.h>

int main()
{
    char name[20] = "홍길동";
    char grade = 'B';
    int scoreKOR = 80;
    int scoreMAT = 75;
    int scoreENG = 86;
    int scoreSCI = 92;

    /*scoreKOR = 100;
    scoreMAT = 42;
    scoreENG = 67;
    scoreSCI = 96;
    grade = 'A';
    strcpy(name,"김철수");
*/
    printf("%s의 성적\n",name);
    printf("KOR : %d\n",scoreKOR);
    printf("MAT : %d\n",scoreMAT);
    printf("ENG : %d\n",scoreENG);
    printf("SCI : %d\n",scoreSCI);
    printf("Grade : %d\n",grade);
    
    return 0;
}