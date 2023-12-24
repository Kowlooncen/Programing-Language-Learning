#include<stdio.h>
int main()
{
	int x;
	do{
		scanf("%d",&x);
	}while(x<=0);
	int sum=0;
	int pro=1;
	int a;
	while(x!=0)
	{
		a=x%10;
		sum=a+sum;
		pro=pro*a;
		x=x/10;
	}
	if(sum==pro)
	{
		printf("YES");
	}
	else printf("NO");
}
