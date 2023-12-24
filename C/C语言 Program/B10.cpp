#include<stdio.h>
int main()
{
	int x,a,b,s=1;
	scanf("%d",&x);
	while(x!=0)
	{
		a=x%10;
		x=x/10;
		b=x%10;
		if(a<=b)
		s=0;
	}
	if(s==1)
	{
		printf("YES");
	}
	if(s==0)
	{
		printf("NO");
	}
}
