#include<stdio.h>
int main()
{
	int x,a,b,c;
	scanf("%d",&x);	
	a=x/100;
	int h;
	h=x%100;
	b=h/10;
	h=h%10;
	c=h/1;
	int pro;
	pro=a*b*c;
printf("%d",pro); 
	return 0;
}
