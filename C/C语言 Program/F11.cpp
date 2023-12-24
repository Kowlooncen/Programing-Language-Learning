#include<stdio.h>

int main()
{
	int a[30];
	for(int i=0;i<=29;i++)
	{
		scanf("%d",&a[i]);
	}
	int n=0;
	int min=a[0],max=a[0];
	for(int i=0;i<=29;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
		for(int i=0;i<=29;i++)
	{
		if(min>a[i]){
			min=a[i];
			n=i;
		}
	}
	
	a[n]=max;
	int m=0;
	min=a[0];
		for(int i=0;i<=29;i++)
	{
		if(min>a[i]){
			min=a[i];
			m=i;
		}
	}
	if(n>m)
	{
		int c=n;
		n=m;
		m=c;
	}
	printf("%d %d",n,m);
}
