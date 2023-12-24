#include<stdio.h>
void f(int x)
{
	if(x==1) printf("%d",x);
	else{
		printf("%d ",x);
		f(x-1);
	}
 } 
 int main()
 {
 	int x;
 	scanf("%d",&x);
 	f(x);
 }
