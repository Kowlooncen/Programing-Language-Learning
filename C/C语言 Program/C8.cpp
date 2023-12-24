#include<stdio.h>
char big(char c)
{
	if(c>='a'&&c<='z')
	{
		c=c+'A'-'a';
	}
	return c;
}

int main()
{
	int k=1;
	char c;
	do{
		scanf("%c",&c);	
		c=big(c);
		if(c=='.') k=0;
		if(k==1) printf("%c",c);
	}while(c!='.');
	
}
