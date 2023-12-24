#include<stdio.h>

int main()
{
	int sum=0;
	int a[5][5];
	for(int i=0;i<=4;i++)
	{
		for(int j=0;j<=4;j++)
		{
			scanf("%d",&a[i][j]);
			if(i==j)
			{
				sum=sum+a[i][j];	
			}
		}
	}
	printf("%d",sum);
}
