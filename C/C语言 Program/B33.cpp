#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int a=1,b=1,c=1;
	printf("%d ",c);
	for(int i=1;i<x;i++)
	{
		printf("%d ",c);
		c=a+b;
		a=b;
		b=c;
	}
}
