#include<stdio.h>
#define size 4
int main()
{
	short dates[size];
	short *pti;
	short index;
	double bills[size];
	double *ptf;
	pti=dates;
	ptf=bills;
	printf("%23s %15s\n","short","double");
	for(index=0;index<size;index++)
	{
		printf("pointers + %d: %10p %10p\n",index,pti+index,ptf+index);
	}
	return 0;
}
