#include<stdio.h>
int main()
{
	int a, b;
	scanf("%d %d",&a,&b);
	if(a>b)
	{
		int m;
		m=b;
		b=a;
		a=m;
	}
	for(int i=a;i<=b;i++)
	{
		printf("%d ",i*i*i);
	}
}
