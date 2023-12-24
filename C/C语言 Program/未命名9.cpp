#include<stdio.h>
void f(int n)
{
	if(n==1) printf("1 ");
	else{
		f(n-1);
		printf("%d ",n);	}
}
int main()
{
	int x;
	scanf("%d",&x);
	f(x);
	return 0;
}
