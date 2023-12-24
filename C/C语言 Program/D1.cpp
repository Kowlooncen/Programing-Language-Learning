#include<stdio.h>
void f(int i,int n)
{
	if(i==n) printf("%d",n);
	else{
		printf("%d ",i);
		return f(i+1,n)
	;}
}
int main()
{
	int x;
	scanf("%d",&x);
	f(1,x);
	return 0;
}
