#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a<=b)
	{
		while(a<=b)
		{
			printf("%d ",a*a);
			a++;
		}
	}
		
	return 0;
}
