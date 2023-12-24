#include<stdio.h>
int f(int x,int y)
{
	int a[1000]={0};
	int i=0;
	while(x!=0)
	{
		a[i]=x%y;
		x=x/y;
		i++;
	}
	int sum=0;
	for(int j=i;j>=0;j--)
	{
		
		sum=sum*10+a[j];
	}
	return sum;
}
int main()
{
	int n,p;
	scanf("%d %d",&n,&p);
	printf("%d",f(n,p));
}
