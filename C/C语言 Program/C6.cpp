#include<stdio.h>
long long int f(int x)
{
	long long int a=1;
	for(int i=1;i<x;i++)
	{
		a=a*2;
	}
	return a;
}
int main()
{
	int x;
	scanf("%d",&x);
	if(x<=63)
	{
		long long int a;
	a=f(x);
	printf("%lld",a);	
	}
	if(x==64)
	{
		int i,j,n=63,len=0,a[100]={0};
 	a[0]=1;
	 for(i=1;i<=n;i++)
	 {
	  for(j=0;j<=len;j++)
	   a[j]*=2;
	  for(j=0;j<=len;j++)
	   if(a[j]>=10)
	   {
	    a[j]%=10;
	    a[j+1]++;
	   }
	  if(a[len+1]>0)len++;
	}
	 for(i=len;i>=0;i--)
	  printf("%d",a[i]);
	}
}
