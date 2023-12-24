#include<stdio.h>
int main()
{
	int x,a,i=0;
	scanf("%d",&x);
	while(x!=0)
	{
		a=x%10;
		if(a==9)
		{
			i++;
		}
		x=x/10;
	}
	if(i==1)
	printf("YES");
	else
	printf("NO");
}
