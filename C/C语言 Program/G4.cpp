#include<stdio.h>
int main()
{
	char q[202];
	scanf("%201[^\n]s",q);
	int count=0;
	while(q[count]!='\0')
	{
		count++;
	}
	int k=0;
	while(q[k]!=' ')
	{
		k++;
	}
	int a[26]={0};
	for(int i=0;i<=k-1;i++)
	{
		a[q[i]-'a']++;
	}
	int b[26]={0};
	for(int i=k+1;i<=count-1;i++)
	{
		b[q[i]-'a']++;
	}
	for(int j=0;j<=25;j++)
	{
		if(a[j]==1&&b[j]==1)
		{
			printf("%c ",'a'+j);
		}
	}
 } 
