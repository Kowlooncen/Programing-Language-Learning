#include<stdio.h>

int main()
{
	int a[10];
	for(int i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	int c,d;
	for(int i=0;i<=3;i++)
	{
		for(int j=i+1;j<=4;j++)
		{
			if(a[i]>=a[j])
		{
			d=a[j];
			a[j]=a[i];
			a[i]=d;
		}
		}
	}
		for(int i=5;i<=8;i++)
	{
		for(int j=i+1;j<=9;j++)
		{
			if(a[i]<=a[j])
		{
			d=a[j];
			a[j]=a[i];
			a[i]=d;
		}
		}
	}
	for(int i=0;i<=9;i++)
	{
		printf("%d ",a[i]);
	}
}
