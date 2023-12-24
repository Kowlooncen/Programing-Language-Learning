#include<stdio.h>
int main()
{
	int x;
	do{
		scanf("%d",&x);
	}while(x<=0);	
	int s=1;
	if(x>2)
	{
		for(int i=2;i<x;i++)
	{
		if(x%i==0)
		{
			s=0;
			break;
		}
	}	
	}
	if(x==1) s=0;
	if(x==2) s=1;

	if(s==1) printf("YES");
	if(s==0) printf("NO");
}
