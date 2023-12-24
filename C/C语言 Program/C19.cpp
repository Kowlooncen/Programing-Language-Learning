#include<stdio.h>
int f(void)
{
	char c;
	int s=0;
	do{
		scanf("%c",&c);
		if(c>='0'&&c<='9') s=c-'0'+s;
		
	}while(c!='.');
	return s;
}
int main()
{
	printf("%d",f());
	
}
