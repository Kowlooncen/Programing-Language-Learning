#include<stdio.h>
#include<ctype.h>
int main()
{
	char c;
	int n=0;
	do{
		scanf("%c",&c);
		if(isdigit(c))
		n++;
	}while(c!='.');
	printf("%d",n);
	
}
