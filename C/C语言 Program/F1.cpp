#include<stdio.h>
void f(int a[])
{
	for(int i=0;i<=18;i++)
	{
		for(int j=i+1;j<=19;j++)
		{
			if(a[i]>a[j])
			{
				int c=a[i];
				a[i]=a[j];
				a[j]=c;
			}
		}
	}
}
int main()
{
	int a[20];
	for(int i=0;i<=19;i++)	
	{
		scanf("%d",&a[i]);
	}
	f(&a[0]);
	for(int i=0;i<=19;i++)
	{
		printf("%d ",a[i]);
	}
}
