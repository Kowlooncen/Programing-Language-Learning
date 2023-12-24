#include<stdio.h>
int main()
{
	int x,i,j;
	char q[27]={0};//这个是初始化 
	scanf("%d",&x);
	for(i=0,j=0;i<x;i=i+2,j++)
	{
		q[i]='A'+j;
		q[i+1]='2'+i%8;
	}
	printf("%s",q);
}
