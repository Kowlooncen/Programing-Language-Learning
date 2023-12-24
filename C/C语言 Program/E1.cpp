#include<stdio.h>
int main()
{
	int a[5]={0};
	for(int i=0;i<=4;i++)
	{
		scanf("%d",&a[i]);
	}
	float sum=0;
	for(int i=0;i<=4;i++)
	{
		sum=sum+a[i];
	}
	printf("%.3f",sum/5);
}
