#include<stdio.h>
int main()
{
	int a,b;
	long int sum;
	scanf("%d %d",&a,&b);
	for(int i=a;i<=b;i++)
	{
		sum=sum+i*i;
	}
	printf("%ld",sum);
}
