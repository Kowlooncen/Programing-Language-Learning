#include<stdio.h>
int middle(int a,int b)
{
	int c;
	c=(a+b)/2;
	return c;
}
int main()
{
	int x,y;
	scanf("%d %d",&x,&y);
	int r;
	r=middle(x,y);
	printf("%d",r);
}
