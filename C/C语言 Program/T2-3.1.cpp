#include<stdio.h>
#include<math.h>
void g(int space,int line,char c)
{
	for(int i=1;i<=space;i++)
		printf(" ");
	for(int i=1;i<=line;i++)
		printf("%c",c);
	printf("\n");	
}
void f(int x)
{
	int space,line;
	for(int i=1;i<=x;i++)
	{
		space=abs((x+1)/2-i);
		line=x-2*space;
		if(i%2==1) g(space,line,'+');
		if(i%2==0) g(space,line,'-');
	}
}
int main()
{
	int x;
	scanf("%d",&x);
	f(x);

}
