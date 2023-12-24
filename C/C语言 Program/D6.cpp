#include<stdio.h>
void f(void)
{
	char c;
	scanf("%c",&c);
	if(c=='.') printf("");
	else{
		f();
		printf("%c",c);
	}
	
}
int main()
{
	f();
}
