#include<stdio.h>
int main()
{
	int a[10]={0};
	int sum=0;
	for(int i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<=9;i++)
	{
		if(a[i]>0)
		{
			sum=sum+a[i];
		}
	}
	printf("%d",sum);
}
