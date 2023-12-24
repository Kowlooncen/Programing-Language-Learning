#include<stdio.h>
int main()
{
	int x,a,s;
	scanf("%d",&x);
	if(x)
	s=x%10;
		while(s==0)
		{
			x=x/10;
			s=x%10;
			if(x==0)
			{
				printf("%d",0);
				break;
			}
		} 
	while(x!=0)
	{
		a=x%10;
		printf("%d",a);
		x=x/10;
	}	

}
