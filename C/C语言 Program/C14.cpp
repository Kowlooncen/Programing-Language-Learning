#include<stdio.h>
int f(int x)
{
	int sum=0;
	while(x!=0)
	{
		sum=sum+x%10;
		x=x/10;
	}
	if(sum%2==0)
	{
		return 1;
	}
	else return 0;
}
int main()
{
	int x;
	scanf("%d",&x);
	if(f(x)) printf("YES");
	else printf("NO");
}
