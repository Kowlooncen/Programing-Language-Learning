#include<stdio.h>
#include<math.h>
double rad(double x)
{
	x=x/180*M_PI;
}
double sin(double x)
{
	double q=0.,Sin=0,p=1.;
	int a=1,i=1,b=1;
	x=rad(x);
	p=x;
	Sin=x;
	do{
		p=p*x*x;
		a=a*(i+1)*(i+2);
		b=-b;
		q=p/a*b;
		i+=2;
		Sin+=q;
		
	}while(fabs(q)>0.001);
return Sin;
}
int main()
{
	double x,a;
	scanf("%lf",&x);
	a=sin(x);
	printf("%.3lf",a);
}
