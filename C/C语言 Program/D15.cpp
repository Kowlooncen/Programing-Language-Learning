#include<stdio.h>
int main()
{
	int x;
	int max;
	scanf("%d",&x);
	max=x;
	while(x!=0)
	{
		if(x>=max) max=x;
		scanf("%d",&x);
	}
	printf("%d",max);
	return 0; 
}
