#include<stdio.h>
int main()
{
	int a[10],c;
	for(int i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	c=a[9];
//	for(int i=0;i<9;i++)
//	{
//		a[i+1]=a[i];
//	}
	printf("%d ",c);
	for(int i=0;i<=8;i++)
	{
		printf("%d ",a[i]);
	}
}
