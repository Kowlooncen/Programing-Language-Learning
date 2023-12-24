#include<stdio.h>
#include<math.h>
void f(int a[])
{
	int max=a[0];
	for(int i=0;i<=9;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	int n=0;
	for(int i=0;i<=9;i++)
	{
		if(abs(a[i])>max)
		{
			n++;
		}
	}	
	printf("%d",n);
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
