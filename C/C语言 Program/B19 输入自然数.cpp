#include<stdio.h>
int main()
{
	int a,sum=0,x;
	do{
		
		scanf("%d",&x);	
	}while(x<=0);//do-whileÒýÈë 

	while(x!=0)
	{
		a=x%10;
		sum=sum+a;
		x=x/10;
	}
	if(sum==10)
	{printf("YES");
	}
	else printf("NO");
}
