#include<stdio.h>
int main()
{
	long long int a,b;
	long long int s=1;
	scanf("%lld %lld",&a,&b);
	for(int i=1;i<=b;i++)
	{
		s=s*a;
	}
	printf("%lld",s);
 } 
