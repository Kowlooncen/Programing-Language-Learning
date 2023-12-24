#include<stdio.h>

int main()
{
	int a[10];
	for(int i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	int b[10]={0};//赋值只能赋值于0！！！ 
	for(int i=0;i<=8;i++)
	{
		for(int j=i+1;j<=9;j++)
		{
			if(a[i]==a[j])
			{
				b[i]++;
			}
		}
	}
	for(int i=0;i<=9;i++)
	{
		if(b[i]==1)
		{
			printf("%d ",a[i]);
		}	
	}
}
