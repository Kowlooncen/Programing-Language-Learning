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
	if(a<b)
	a=b;
	if(a<c)
	a=c;
printf("%d",a); 
	return 0;
}
