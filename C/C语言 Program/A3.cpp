#include<stdio.h>
int main() 
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int sum,pro;
	sum=a+b+c;
	pro=a*b*c;
	printf("%d+%d+%d=%d\n",a,b,c,sum);
	printf("%d*%d*%d=%d",a,b,c,pro);
	return 0;
}
