#include<stdio.h>
void f(int a[])
{
	
	for(int i=0;i<=19;i++)
	{
		if(a[i]%2==0)
		{
			printf("%d ",a[i]);
		}
	}
		for(int i=0;i<=19;i++)
	{
		if(a[i]%2!=0)
		{
			printf("%d ",a[i]);
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
	return 0;
 } 
