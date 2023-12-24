#include<stdio.h>
#include<string.h>
int main()
{
	char s[1001];
	int count=0;
	gets(s);
	int len=strlen(s);
	for(int i=1;i<=len-1;i++)
	{
		if(s[i]==' '&&s[i-1]=='a')
		{
			count++;
		}
	}
	if(s[len-1]=='a') count++;
	printf("%d",count);
}
