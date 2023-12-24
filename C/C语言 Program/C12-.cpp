#include<stdio.h>
#include<math.h>
double rad(double x)
{
	x=x/180*M_PI;
	return  x; 
}
double sin(double x)
{
	x=rad(x);
	double sum=0,a=1,q=1,b=1;
	int i=1,s=1;
	while(fabs(q)>0.001)
	{
		for(int j=1;j<=(2*i-1);j++)
		{
			a=a*x;
			b=b*j;
		}
		q=a/b*s;
		sum=q+sum;
		s=-s;
		i++;
		a=1.0;
		b=1.0;
	}
	return sum;
}

int main()
{
	double x,a;
	scanf("%lf",&x);
	a=sin(x);
	printf("%.3f",a);
}
