#include<stdio.h>

int main()
{
	int a[10],b[10];
	for(int i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i]%10;
	}
	int c,d;
	for(int i=0;i<=8;i++)
	{
		for(int j=i+1;j<=9;j++)
		{
			if(b[i]>=b[j])
		{
			c=b[j];
			b[j]=b[i];
			b[i]=c;
			d=a[j];
			a[j]=a[i];
			a[i]=d;
		}
		}
	}
	for(int i=0;i<=9;i++)
	{
		printf("%d ",a[i]);
	}
}
