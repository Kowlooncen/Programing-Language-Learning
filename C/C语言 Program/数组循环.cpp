#include<stdio.h>
int main() 
{
	int i,j,t,a[10];
	printf("please enter 10 number\n");
	for(i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=0;j<9;j++)
	{
		for(i=0;i<=9;i++)
		{
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}
	for(i=0;i<=9;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
