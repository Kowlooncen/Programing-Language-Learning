#include<stdio.h>
int nod(int a,int b)
{
	int s;
	while(a!=0)
	{
		if(a<b)
		{
			s=a;
			a=b;
			b=s;
		}
		a=a-b;
	}
	return b;
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",nod(a,b));
 } 
