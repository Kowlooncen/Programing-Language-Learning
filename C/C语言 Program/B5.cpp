#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int sum=0;
	while(x!=0)
	{
		sum=x%10+sum;
		x=x/10;
	}
	printf("%d",sum);
}
