#include<stdio.h>
void f(void)
{
	int x;
	char c;
	
	do{
		scanf("%c",&c);
		if(c>='0'&&c<='9')
		x++;
	}while(c!='.');
	printf("%d",x);
}
int main()
{
	f();
}
