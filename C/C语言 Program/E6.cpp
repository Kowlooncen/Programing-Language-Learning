#include<stdio.h>
int main()
{
	int a[12];
	float c=0;
	for(int i=0;i<=11;i++)
	{
		scanf("%d",&a[i]);
		c=c+a[i];
	}
	printf("%.2f",c/12);
//	for(int i=8;i<=11;i++)
//	{
//		printf("%d ",a[i]);
//	}
//	for(int i=0;i<8;i++)
//	{
//		printf("%d ",a[i]);
//	}

}
