#include<stdio.h>
int main()
{
	int x,s,a=1;
	scanf("%d",&x);
	while(x!=0)
	{
		s=x%10;
		if(x%2==1)
		{
			a=0;
		}
		x=x/10;
	}
	if(a==1)
	printf("YES");
	else
	printf("NO");
	
}
