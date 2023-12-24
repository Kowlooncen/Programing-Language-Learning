#include<stdio.h>

int main()
{
	int a[10],b[10];
	for(int i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i]/10%10;
	}

	for(int i=0;i<=9;i++)
	{
		if(b[i]==0)
		{
			printf("%d ",a[i]);
		 }
		
	}
}
