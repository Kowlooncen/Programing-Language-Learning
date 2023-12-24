#include<stdio.h>
int sum(int x)
{
	int s=0;
	for(int i=1;i<=x;i++)
	{
		s=i+s;
	}
	return s;
}
int main()
{
	int x;
	scanf("%d",&x);
	int c;
	c=sum(x);
	printf("%d",c);
}

