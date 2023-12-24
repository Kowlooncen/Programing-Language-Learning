#include<stdio.h>
int main()
{
	int x;
	char c;
	scanf("%c%d",&c,&x);
	int s=c-'A'+1,sum=s+x;
	if(sum%2==0 ) printf("BLACK");
	else printf("WHITE");
}
