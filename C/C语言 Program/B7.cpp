#include <stdio.h>
int main()
{
int a,x[10],i;
int n=0;
int s=0;
scanf("%d",&a);
int m=a;
	while(m!=0)
	{
		m=m/10;
		n++;
	}
	for(i=0;i<n;i++)
	{
		x[i]=a%10;
		a=a/10;
	}
	int j;
	for(j=0;j<n;j++)
	{
		for(i=j+1;i<n;i++)
		{
			if(x[j]==x[i])
			{
				s=1;
				break;
			}
		}
	}
	if(s==1)
	{
		printf("YES");
	}
	else
	printf("NO");
return 0;
}
