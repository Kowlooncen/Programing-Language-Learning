#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int n=0;
	while(x!=0)
	{
		x=x/10;
		n++;
	}
	if(n==3)
	{
		printf("YES");
	}
	else
	printf("NO");
	return 0;
}
