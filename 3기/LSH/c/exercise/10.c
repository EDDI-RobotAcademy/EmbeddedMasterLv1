#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* 물류센터에 짐이 들어온다.
이 물류 센터 3000평 정도의 면적을 가지고 있다.
여기에 각 물건을 박스화하여 배치한다.
박스의 크기는 28평정도이며 박스간의 이격 간격은 4평이다.
물류를 배치하는 가장 효율적인 방법을 프로그래밍하여 구현하시오. */

float calc_line(int area)
{
	return sqrt(area);
}

int get_num(float total_line, float sub_line)
{
	return total_line / sub_line;
}

int main(void)
{
	// 먼저 정육면체의 길이를 구하도록 한다.
	float row, col, box_row, box_col;
	int num;

	row = col = calc_line(3000);
	box_row = box_col = calc_line(32);

	num = get_num(row, box_row);

	printf("row = col = %f\n", row);
	printf("box_row = box_col = %f\n", box_row);
	printf("3000평에 배치된 박스는 모두 %d개다.\n", num * num);

	return 0;
}
