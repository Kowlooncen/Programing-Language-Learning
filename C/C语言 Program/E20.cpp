#include<stdio.h>
int main()
{
	int a[100];
	long long int x;
	scanf("%lld",&x);
	int i=0;
	while(x!=0)
	{
		a[i]=x%10;
		x=x/10;
		i++;
	}

	for(int j=9;j>=0;j--)
	for(int k=i-1;k>=0;k--)	
	{
		if(a[k]==j) printf("%d",a[k]);
	}
}

