#include<stdio.h>
void f(int x)
{
	if(x/10==0) printf("%d ",x%10);
	else{
		f(x/10);
		printf("%d ",x%10);
	} 
}
int main()
{
	int x;
	scanf("%d",&x);
	f(x);
}
