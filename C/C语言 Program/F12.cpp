#include<stdio.h>
void f(int a[])
{
	int max=a[0],min=a[0];
	for(int i=0;i<=9;i++)
	{
		if(max<a[i]) max=a[i];
		if(min>a[i]) min=a[i];
	}
	for(int i=0;i<=9;i++)
	{
		if(a[i]==max)  {
			a[i]=min;
		}
		else if(a[i]==min){
		    a[i]=max;
		}
	}
	
		for(int i=0;i<=9;i++)
	{
		printf("%d ",a[i]);	}
}
int main()
{
	int a[10];
	for(int i=0;i<=9;i++)
	scanf("%d",&a[i]);
	f(a);
}
