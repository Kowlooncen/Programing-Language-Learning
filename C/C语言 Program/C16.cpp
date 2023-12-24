#include<stdio.h>
int f(int x)
{
	int k=1;
	if(x==1||x==0) k=0;
	if(x==2) k=1;
	if(x>2)
	{
	for(int i=2;i<x;i++)
	{
		if(x%i==0)
		{
			k=0;
			break;
		}
	}	
	}
	if(k==1) return 1;
	if(k==0) return 0;
}
int main()
{
	int x;
	scanf("%d",&x);
	if(f(x)) printf("YES");
	else printf("NO");	
}
