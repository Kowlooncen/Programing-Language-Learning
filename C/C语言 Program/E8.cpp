#include<stdio.h>
int main()
{
	int a[12],c;
	for(int i=0;i<=11;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<=11;i=i+4)
	{
		for(int j=i+3;j>=i;j--)
		{
			printf("%d ",a[j]);
		}
	}
//	for(int i=8;i<=11;i++)
//	{
//		printf("%d ",a[i]);
//	}
//	for(int i=0;i<8;i++)
//	{
//		printf("%d ",a[i]);
//	}

}
