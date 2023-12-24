#include<stdio.h> 
int main()
{
	int x,a;
	scanf("%d %d",&x,&a);
	int pro=1;
	for(int i=1;i<=a;i++)
	{
		pro=pro*x;
	}
	printf("%d",pro);
}
