#include<stdio.h>
long long int f(long long int x,long long int y)
{
	return y==1?x:f(x,y-1)*x;
//	if(y==1) return x;
//	else return f(x,y-1)*x;	
}
int main()
{
	long long int x,y;
	scanf("%lld %lld",&x,&y);
	printf("%lld",f(x,y));
	return 0;
}
