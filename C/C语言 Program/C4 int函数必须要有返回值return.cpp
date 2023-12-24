#include<stdio.h>
int f(int x)
{
	int s;
	if(x>=-2&&x<2) s=x*x;
	if(x>=2) s=x*x+4*x+5;
	if(x<-2) s=4;
	return s; 
}
int main()
{
	int x;
	int s=0,a;
	do{
		scanf("%d",&x);
		a=f(x);
		if(s<a)
		{
			s=a;
		}
	}while(x!=0);
	printf("%d",s);
} 
