#include<stdio.h>
#include<string.h>
int main()
{
	char a[1001];
	scanf("%s",a);
	int k=1;
	int l=strlen(a);
	for(int i=0;i<=l-1;i++)
	{
			if(a[i]!=a[l-1-i])
			{
				k=0;
				break;
			}
	}
	if(k==1) printf("YES");
	if(k==0) printf("NO");
}
