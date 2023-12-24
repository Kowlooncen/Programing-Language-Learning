#include<stdio.h>
void f(int x)
{
	if(x/2==0) printf("%d",x%2);
	else{
		f(x/2);
		printf("%d",x%2);
		
	}
}
int main()
{
	int x;
	scanf("%d",&x);
	f(x);
}
