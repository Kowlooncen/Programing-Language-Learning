#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int i,j;
	int n=0;
	for(i=0;i<=x/8;i++)
	{
		for(int j=0;j<=x/6;j++)
		{
			if(8*i+6*j==x)
			{
				n++;
			}
		}
	}
	if(x==0) n=0;
	printf("%d",n);
}
