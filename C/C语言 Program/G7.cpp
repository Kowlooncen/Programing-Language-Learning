#include<stdio.h>
#include<string.h>
int main()
{
	char a[1001];
	gets(a);
	int l=strlen(a);
	int m=0,n=0;
	for(int i=0;i<=l;i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
			m++;
		}
		if(a[i]>='a'&&a[i]<='z')
		{
			n++;
		}
	}
	printf("%d %d",n,m);
}
