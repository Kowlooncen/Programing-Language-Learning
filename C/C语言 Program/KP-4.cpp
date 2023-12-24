#include<stdio.h>
int main()
{
	int x;
	int a[100]={0};
	scanf("%d",&x);
	int i=-1;
	while(x!=0)
	{	i++;
		a[i]=x%3;
		x=x/3;
	
	}
	for(;i>=0;i--)
	{
		printf("%d",a[i]);
	}
}
