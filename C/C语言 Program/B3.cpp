#include<stdio.h>
int main()
{
	int a,b;
	int sum=0;
	scanf("%d %d",&a,&b);
	if(a<=b)
	{
		while(a<=b)
		{
			sum=a*a+sum;
			
			a++;
		}printf("%d ",sum);
	}
		
	return 0;
}
