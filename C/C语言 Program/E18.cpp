#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	for(int i=2;i<=9;i++)
	{
		printf("%d ",i);
		printf("%d\n",x/i);
	}
}
