#include<stdio.h>
int f(int x)
{
	int sum=0,pro=1;
	int a;
	while(x!=0)
	{
		a=x%10;
		sum=sum+a;
		pro=pro*a;
		x=x/10;
	}
	if(sum==pro) return 1;
	else return 0;
}
int main()
{
	int x;
	scanf("%d",&x);
	if(f(x)) printf("YES");
	else printf("NO");
}
