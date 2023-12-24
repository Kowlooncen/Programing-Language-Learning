#include<stdio.h>
int main()
{
	int a[10];
	for(int i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	int b[10]={0};
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
	int k=1;
		for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			if(b[i]<b[j])
			{
				k=0;
				break; 
			}
		}
		if(k==1) {
			printf("%d ",a[i]);
		}
		k=1;
	}
	return 0;
}
