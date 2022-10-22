#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define AREA				30000000
#define BOX_LINE			32
#define HEIGHT				200

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
