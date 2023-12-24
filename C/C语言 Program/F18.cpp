#include<stdio.h>

int main()
{
	int sum=0;
	int a[10][10];
	int max;
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			scanf("%d",&a[i][j]);

			if(j==0){
			max=a[i][0];				
			}else{
				if(max<a[i][j])
				{
					max=a[i][j];
				}
			}
		}
		sum=sum+max;
	}
	printf("%d",sum);
}
