#include<stdio.h>
int main() 
{
	int p,t,i,x,number[5];
	for(i=0;i<5;i++)
	{
	scanf("%d",&x);		
	number[i]=x;
	}
	p=number[4];
	t=number[4];
	for(i=4;i>=0;i--)
	{
		if(number[i]>p)
		p=number[i];
	
	}
		for(i=4;i>=0;i--)
	{
		if(number[i]<t)
		t=number[i];
	
	}
	printf("%d\n",p+t);
	return 0;
	
}
