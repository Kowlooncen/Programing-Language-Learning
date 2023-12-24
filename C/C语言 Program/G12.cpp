#include<stdio.h>
#include<string.h>
int main()
{
	char q[1001];
	gets(q);
	int l=strlen(q);
	int count=0;
	while(q[count]==' ')
	{
		count++;
	}
//	printf("%d",count);
	for(int i=count;i<=l-2;i++)
	{
		if(q[i]==' '&&q[i+1]!=' '){
			printf("\n");
		}
		else{
			printf("%c",q[i]);
		}
	}
	printf("%c",q[l-1]);
}
