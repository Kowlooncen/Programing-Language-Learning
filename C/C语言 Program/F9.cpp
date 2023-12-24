#include<stdio.h>
void f(int a[])
{
	int b[10]={0};
	int j=0;
	for(int i=0;i<=9;i++)
	{
		if(a[i]<0)
		{
			b[j]=a[i];
			j++;
		}
	}
	int max=b[0];
	for(int i=0;i<=j-1;i++)
	{
		if(max<b[i])
		{
			max=b[i];
		}
	}
	for(int i=0;i<=9;i++)
	{
		if(max==a[i])
		{
			int c=a[i];
			a[i]=a[9];
			a[9]=c;
		}
	}
	for(int i=0;i<=9;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int a[10];
	for(int i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	f(a);
}
