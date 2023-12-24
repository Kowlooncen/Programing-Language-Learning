#include<stdio.h>
int main()
{
	int a[10],c;
	for(int i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<2;i++)
	{
		c=a[i];
		a[i]=a[4-i];
		a[4-i]=c;
		
	}
		for(int i=5;i<7;i++)
	{
		c=a[i];
		a[i]=a[14-i];
		a[14-i]=c;
		
	}
	for(int i=0;i<=9;i++)
	{
		printf("%d ",a[i]);
	}
}
