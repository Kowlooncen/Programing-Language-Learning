#include<stdio.h>
#include<math.h>
float trans(float x)
{
	x=x/180*3.1415926;
	return x;
}
float count(float x)
{
	x=trans(x);
	float sum=1;
	float q=1.;
	float pro=1;
	int a=1,b=1,i=1;
	while(fabs(q)>0.001)
	{
		
		for(int j=1;j<=2*i;j++)
		{
			a=a*j;
			pro=pro*x;	
		}
		b=-b;
		q=1.*b*pro/a;
		sum=sum+q;
		i++;
		a=1;
		pro=1;
	}
	return sum;
}

int main()
{
	float n;
	scanf("%f",&n);
	printf("%.3f",count(n));
}
