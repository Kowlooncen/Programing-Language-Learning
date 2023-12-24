#include<stdio.h>
#include <math.h>
int main()
{
	int n=1,a=1,c=1,pro=1;
	float std=1,sum=0;
	while(fabs(std)>0.001)
	{
		sum=sum+std;
		while(c<=n)
		{
			pro=pro*3;
			c++;
		}
		std=1.0*a*2*n/((2*n+1)*pro);
		a=-a;
		n++;
	}
	printf("%.3f",sum);
 } 
