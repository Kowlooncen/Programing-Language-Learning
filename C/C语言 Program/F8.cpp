#include<stdio.h>

int main()
{
	int a[1000];
	int x,i=0;;
	do{
		scanf("%d",&x);
		a[i]=x;
		i++;
	}while(x!=0);
	for(int j=0;j<=i-3;j++)
	{
		for(int k=j+1;k<=i-2;k++)
		{
			if(a[j]>a[k])
			{
				int c=a[j];
				a[j]=a[k];
				a[k]=c;
			}
		}
	}
	for(int S=0;S<=i-3;S++)
	{
		if(a[S]!=(a[S+1]-1))
		{
			printf("%d ",a[S]+1);
		}
	}
}
