#include<stdio.h>
int main()
{
	int x,a,b,c,d,n;
	//printf("please write number");
	//scanf("%d",&x);
	
	for(int i=1000;i<=9999;i++)
	{
	a=i/1000;
	int h;
	h=i%1000;
	b=h/100;
	h=h%100;
	c=h/10;
	d=h%10;
	int sum,pro;
	sum=a+b+c+d;
	pro=a*b*c*d;
	if(sum==pro)
	{
		printf("%d\n",i);
		n++;
	}
	
}
printf("%d",n); 
	return 0;
}
