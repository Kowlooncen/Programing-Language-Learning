#include<stdio.h>
int main()
{
	int x,a;
	int i=0,j=0;
	scanf("%d",&x);
	while(x!=0)
	{
		if(x%2==0)
		{
			i++;
		}
		if(x%2==1)
		{
			j++;
		}
		x=x/10;
	}
	printf("%d %d",i,j);
	
}
