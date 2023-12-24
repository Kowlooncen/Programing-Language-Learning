#include<stdio.h>
int f(int n)
{
	if(n==1)
	return 1;//stop
	return f(n-1)*n;//step
}
int main()
{
	int x;
	scanf("%d",&x);
	printf("%d",f(x));
}
