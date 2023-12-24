#include<stdio.h>
double fac(int n)
{
	double s=1.;
	for(int i=1;i<=n;i++)
	{
		s=i*s;
	}
	return s;
}
int main()
{
	int n;
	scanf("%d",&n);
	double p;
	p=fac(n);
	printf("%.20e",p);	
}
