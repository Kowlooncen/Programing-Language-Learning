#include<stdio.h>
int main()
{
	int a=0,b=0,x;
	scanf("%d",&x);
	while(x!=0)
	{
		a=x%10;
	b=b*10+a;
	x=x/10;
	}
	printf("%d",b);
}
