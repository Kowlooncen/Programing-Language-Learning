#include<stdio.h>
int main()
{
	int n=0,a=0,b=0,c=0;
	scanf("%d",&n);
	while(a<=9)
	{
		b=n;
		c=0;
		while(b>0)
		{
			if(b%10==a)
			c++;
			b/=10;
		}
		if(c>=2)
		{
			printf("YES");
			return 0;
		}
		a++;
	}
	printf("NO");
	return 0;
}
