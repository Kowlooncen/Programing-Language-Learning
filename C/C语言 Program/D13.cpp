#include<stdio.h>
void f(int x,int i);
int main()
{
	int x;
	scanf("%d",&x);
	f(x,2);
}
void f(int x,int i)
{
	if(i>x) return;//对于void函数return后面什么都不加就可以了；
	if(x%i==0){
		printf("%d ",i);
		f(x/i,i);
	} 
	else{
		f(x,i+1);
	}
}
