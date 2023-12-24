#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int max=0,min=9;
	int a;
	if(x==0) min=0;
	while(x!=0)
	{
		a=x%10;
		if(a>=max) max=a;
		if(a<=min) min=a;
		x=x/10;
	}
	printf("%d",max-min);
}
