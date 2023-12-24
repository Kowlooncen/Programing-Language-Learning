#include<stdio.h>
int main()
{
	int x,a=1;
	int i=-1;
	while(a!=0)
	{
		scanf("%d",&x);
		a=x;
		if(x%2==0)
		{
			i++;
		}
	}
	printf("%d",i);
	
}
