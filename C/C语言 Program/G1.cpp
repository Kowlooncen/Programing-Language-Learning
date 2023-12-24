#include<stdio.h>
int main()
{
	char q[101];
	scanf("%100[^\n]s",q);
	printf("%s, %s, %s ",q, q, q);
	int count=0;
	while(q[count]!='\0')
	{
		count++;
	}
	printf("%d",count);
}
