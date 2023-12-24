#include<stdio.h>
int main()
{
	long int a[10];
	for(int i=0;i<=9;i++)
	{
		scanf("%ld",&a[i]);
	}
	long int n=0;
	for(int i=0;i<=9;i++)
	for(int j=0;j<=9;j++)
		if(a[i]<a[j])
		{
			n=a[i];
			a[i]=a[j];
			a[j]=n;
		}
	long int sum=a[8]+a[9];
	printf("%ld",sum);
	return 0;
}
