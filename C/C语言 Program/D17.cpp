#include<stdio.h>
int f(int x,int y)
{
	if(x==0) return y+1;
	else if(x>0&&y==0) f(x-1,1);
	else f(x-1,f(x,y-1));
}
int main()
{
	int x,y;
	scanf("%d %d",&x,&y);
	printf("%d",f(x,y));
}
