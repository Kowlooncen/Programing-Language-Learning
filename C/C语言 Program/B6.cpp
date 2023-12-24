#include<stdio.h>
int main()
{
	int x;
	int a,b;
	scanf("%d",&x);
	int n=0;
	while(x!=0)
	{
		a=x%10;
		x=x/10;
		b=x%10;
		if(a==b)
		{
			n=1;
		}
	}
	if(n==1)
	{
		printf("YES");
	}
	else
	printf("NO");
}
