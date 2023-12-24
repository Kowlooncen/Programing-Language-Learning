#include<stdio.h>
#include<stdlib.h>
void f(int a[])
{
	int k=1;
	printf("[");
	if(a[0]==1)
	{
		printf("0,");
		
	}
	for(int i=0;i<=98;i++)
	{
		if(a[i]==a[i+1])
		{	
			k++;
		}
		else{
			printf("%d,",k);
			k=1;
		}
	}
	printf("%d]",k);
}
int main()
{
	int a[100];
	for(int i=0;i<=99;i++)
	{
		scanf("%d",&a[i]);
	}
	f(a);
}
