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
	for(int j=0;j<count-1;j++)
	{
		if(q[j]==q[count-1])
		printf("%d ",j);
	}
}
