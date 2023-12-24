#include<stdio.h>
int main()
{
	char q[1001];
	scanf("%1000[^\n]s",q);
	int count=0;
	while(q[count]!='\0')
	{
		count++;
	}
//	printf("%d\n",count);
	for(int i=0;i<=count-1;i++)
	{
		if(q[i]=='a') q[i]='b';
		else if(q[i]=='b') q[i]='a';
		else if(q[i]=='A') q[i]='B';
		else if(q[i]=='B') q[i]='A';
	}
	for(int i=0;i<=count-1;i++)
	{
		printf("%c",q[i]);
	}
}
