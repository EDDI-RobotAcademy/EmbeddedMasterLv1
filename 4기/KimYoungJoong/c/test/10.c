/*
10. 물류센터에 짐이 들어온다. 

이 물류 센터 3000m^2 정도의 면적을 가지고 있고 재고를 적층할 수 있는 높이는 최대 2m로 제한된다. 

여기에 각 물건을 박스화하여 배치하는 상황을 가정한다.

박스는 정육면체 형태이며 한 변의 길이는 31.8cm에 해당한다.

물류를 배치하는 가장 효율적인 방법을 프로그래밍하여 구현하시오. 
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define AREA                            30000000
#define BOX_LINE                        32
#define HEIGHT                          200

float calc_line(double area)
{
        return pow(area, 2);
}

int get_num(float total_line, float sub_line)
{
        return total_line / sub_line;
}

int main(void)
{
        float row, col;
        int num, stacking_num;

        row = col = calc_line(AREA);

        num = get_num(row, BOX_LINE);
        stacking_num = get_num(HEIGHT, BOX_LINE);

        printf("row = col = %f\n", row);
        printf("num = %d\n", num);
        printf("stacking num = %d\n", stacking_num);
        printf("3000평에 배치된 박스는 모두 %d개다.\n", num * num * stacking_num);

        return 0;
}
