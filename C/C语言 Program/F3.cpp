#include<stdio.h>
void f(int x[],int a)
{
	
	for(int i=0;i<=a-1;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			if(x[i]>x[j])
			{
				int c=x[i];
				x[i]=x[j];
				x[j]=c;
			}
		}
	}
	int b[1000]={0};
	for(int i=0;i<=a-1;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			if(x[i]==x[j])
			{
				b[i]++;
				x[j]=0;
			}
		}
	}
	for(int i=0;i<=a;i++)
	{
		if(x[i]>0)
		{
			printf("%d %d\n",x[i],b[i]+1);
		}
	}
}
int main()
{
	unsigned long long int a;
	int x[1000];
	scanf("%llu",&a);
	int i=0;
	while(a!=0)
	{
		x[i]=a%10;
		a=a/10;
		i++;
	}
	f(&x[0],i-1);
}
