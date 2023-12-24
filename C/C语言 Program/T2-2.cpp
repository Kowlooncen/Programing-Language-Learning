#include<stdio.h>
int sum=0;
int f(int x)
{
	if(x==0) return sum;
	else{
		if(x%10==3) sum++;
		f(x/10);
	}
}
int main()
{
	int x;
	scanf("%d",&x);
	printf("%d",f(x));
}

