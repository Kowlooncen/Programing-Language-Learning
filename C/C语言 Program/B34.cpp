#include<stdio.h>
int main()
{
	long long int n,s=1;
	do{
		scanf("%lld",&n);
	}while(n>13);
	
	for(int i=n;i>=1;i--)
	{
		s=s*i;
	}
	printf("%lld",s);
}

