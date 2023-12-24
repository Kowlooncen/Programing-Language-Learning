#include<stdio.h>
void f(int x)
{
	int n=1,m=0;
	
	while(m<x)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",n);
			m++;
			if(m==x) break;
		}
		n++;
	}
}

int main()
{
	int x;
	scanf("%d",&x);
	f(x);
}
