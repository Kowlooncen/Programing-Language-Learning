#include<stdio.h>
int main()
{
	char a;
	int n=0;
	do{
		scanf("%c",&a);
		if(a<='Z'&&a>='A') n++;
	}while(a!='.');
	printf("%d",n);
}
