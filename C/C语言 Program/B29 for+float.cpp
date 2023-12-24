#include<stdio.h>
int main()
{
	float x,i,sum;
	scanf("%f",&x);
	for(i=1;i<x;i=i+0.1)
	sum=i*i+sum;
	printf("%.1f",sum);
}
