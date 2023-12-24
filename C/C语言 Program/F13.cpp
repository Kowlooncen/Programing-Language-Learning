#include<stdio.h>
void f(int a[],int x,int y)
{
	int n=0;
	if(x>y)
	{
		int c=y;
		y=x;
		x=c;
	}
	for(int i=0;i<=9;i++)
	{
		if(a[i]>=x&&a[i]<=y)
		{
			n++;
		}
	}

	printf("%d",n);
}
int main()
{
	int a[10];
	int c,b;
	scanf("%d%d",&c,&b);
	for(int i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	f(a,c,b);
}
