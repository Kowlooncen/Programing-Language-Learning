#include<stdio.h>
int main() 
{
	int p,i,x,number[5];
	for(i=0;i<5;i++)
	{
	scanf("%d",&x);		
	number[i]=x;
	}
	p=number[4];
	for(i=4;i>=0;i--)
	{
		if(number[i]<p)
		p=number[i];
	
	}
	printf("%d\n",p);
	return 0;
	
}
