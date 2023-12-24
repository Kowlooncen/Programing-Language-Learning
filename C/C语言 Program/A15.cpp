#include<stdio.h>
int main()
{
	int X1,Y1,X2,Y2;
	float K,B; 
	scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
	K=(1.*Y1-1.*Y2)/(1.*X1-1.*X2);
	B=Y1-K*X1;
	printf("%.2f %.2f",K,B);
}
