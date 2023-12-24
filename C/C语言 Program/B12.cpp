#include<stdio.h>
int main()
{
	int x,a;
	int max=0,min;
	scanf("%d",&x);
	min=x%10;
	while(x!=0)
	{
		a=x%10;
		if(max<a)
		max=a;
		if(min>a)
		min=a;
		x=x/10;
	}
	printf("%d %d",min,max);
	
}
