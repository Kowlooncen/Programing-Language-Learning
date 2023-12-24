#include<stdio.h>
int main()
{
	int a[10];
	for(int i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	int b[10]={0};
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
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
	return 0;
}

