#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	int n=1;
	while(n<=a)
	{
		printf("%d %d %d\n",n,n*n,n*n*n);
		n++;
	}
	return 0;
}
