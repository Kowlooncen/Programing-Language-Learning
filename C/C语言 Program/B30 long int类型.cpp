#include<stdio.h>
int main()
{
	long long int x=0;
	long long int sum=0;
		scanf("%lld",&x);
	for(int i=x;i>=1;i--)
	{
		sum=i*i+i*i*i+sum;
	}
	printf("%lld\n",sum);
	printf("%d",sizeof(long long int));
 } 
