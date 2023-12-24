#include<stdio.h>
int sum=0;
int f(int x)
{
	if(x/10==0) {
	sum=sum+x%10;
	return sum;}
	else{
		sum=sum+x%10;
		return f(x/10);
	}
}
int main()
{
	int x;
	scanf("%d",&x);
	printf("%d",f(x));
}
