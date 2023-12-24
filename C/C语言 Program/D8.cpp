#include<stdio.h>
void f(int m,int n)
{
	if(m>=n)
	{
		if(m==n) printf("%d",m);
		else{
			printf("%d ",m);
			f(m-1,n);
		}
	}
	else{
			if(m==n) printf("%d",n);
		else{
			printf("%d ",m);
			f(m+1,n);}
	}
 } 

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	f(m,n);
}
