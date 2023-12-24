#include<stdio.h>
int sum=0;
int f(void)
{
	char c;
	scanf("%c",&c);
	if(c=='.') return sum;
	else{
		if(c=='a') {
			sum++;
			f();
		}
		else f();
	}
}
int main()
{
	printf("%d",f());
}
