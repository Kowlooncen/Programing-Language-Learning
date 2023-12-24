#include<stdio.h>
int f(int x)
{
	int a=0,b=0,k=1;
	while(x!=0)
	{
		a=x%10;
		x=x/10;
		b=x%10;
		if(a<=b){
			k=0;
			break;
		}
	}
	if(k==1) return 1;
	if(k==0) return 0;
}
int main()
{
	int x;
	scanf("%d",&x);
	if(f(x)) printf("YES");
	else printf("NO");	
}
