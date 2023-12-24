#include<stdio.h>
int main()
{
	long long int a[30];
	for(int i=0;i<=29;i++)
	{
		scanf("%lld",&a[i]);
	}
	int k=1;
	for(int i=0;i<=28;i++)
	{
		if(a[i]<=a[i+1])
		{
			k=0;
			break;
		}
	}
	if(k==1) printf("YES");
	if(k==0) printf("NO");
}	
