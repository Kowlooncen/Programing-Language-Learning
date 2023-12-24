#include<stdio.h>
int main()
{
	int a[10];
	int b[10];
	int c[10];
	int k=0,m=0;
	for(int i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<=9;i++)
	{
		if(a[i]>0)
		printf("%d ",a[i]);
	}
	for(int i=0;i<=9;i++)
	{
		if(a[i]<0)
		printf("%d ",a[i]);
	}
}
