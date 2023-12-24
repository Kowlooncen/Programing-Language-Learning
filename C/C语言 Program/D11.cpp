#include<stdio.h>
int sum=0;
void f(int x)
{
	if(x/2==0) {
		if(x%2==1) {
sum++; printf("%d",sum);}
		else{
			printf("%d",sum);;
		}
	}
	else{
		
			if(x%2==1) {
sum++; }  f(x/2);
	}
}

int main()
{
	int x;
	scanf("%d",&x);
	f(x)

;}
