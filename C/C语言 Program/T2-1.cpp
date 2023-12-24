#include<stdio.h>
long int f(long int x,long int y,long int z)
{
	long int max;
	if(x>=y) max=x;
	else max=y;
	if(max>=z) max=max;
	else max=z;
	return max;
}
int main()
{
	long int x,y,z;
	scanf("%ld %ld %ld",&x,&y,&z);
	printf("%ld",f(x,y,z));
}
