#include <stdio.h>
#define size 2
unsigned int arr[size][size]={{4,1},{11,3}};

void conv_inv_matrix(void);
void print_matrix(unsigned int arr[][size]);


int main(void)
{
    print_matrix(arr);
    conv_inv_matrix();
    print_matrix(arr);
    return 0;
    printf("%p",arr);
}


void print_matrix(unsigned int arr[][size])
{
	for (int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

void conv_inv_matrix(void)
{
	register unsigned int *r1 asm("r1")=NULL;
	register int r2 asm("r2")=0;
	register int r3 asm("r3")=0;
	register int r4 asm("r4")=0;
	register int r5 asm("r5")=0;
	register int r6 asm("r6")=0;
	register int r7 asm("r7")=0;
	
	r1=&arr[0][0];
	
	asm volatile("ldr r2,[r1]");
	asm volatile("ldr r3,[r1,#0x8]");
	asm volatile("ldr r4,[r1,#0x4]");
	asm volatile("ldr r5,[r1,#0xc]");

	r6=r2*r5-r3*r4;    //   1/det(arr)
	r7=r2;
	r2=r5;
	r5=r7;
	r3=-r3;
	r4=-r4;

    asm volatile("str r2,[r1]");
    asm volatile("str r3,[r1,#0x8]");
    asm volatile("str r4,[r1,#0x4]");
//    asm volatile("str r5,[r1,#0xc]");
}
