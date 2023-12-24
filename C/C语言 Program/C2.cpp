#include<stdio.h>
int power(int n,int p)
{
	long long int a=1;
	for(int i=1;i<=p;i++)
	a=a*n;
	return a;
}
int main()
{
	long int x,y;
	long long int s;
	scanf("%ld %ld",&x,&y);
	s=power(x,y);
	printf("%lld",s);
	
}
