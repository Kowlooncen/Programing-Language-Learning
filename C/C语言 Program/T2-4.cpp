#include<stdio.h>
void f(int x)
{
	if(x/3==0) printf("%d",x%3);
	else{
		f(x/3);
		printf("%d",x%3);
	}
}
int main()
{
	int x;
	scanf("%d",&x);
	f(x);
}
