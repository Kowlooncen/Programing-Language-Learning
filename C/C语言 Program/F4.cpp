#include<stdio.h>
void f(int a[])
{
	char c;
	scanf("%c",&c);
	while(c!='.')
	{
		if(c>='0'&&c<='9')
		{
			a[c-'0']++;
		}
		scanf("%c",&c);
	}
}
int main()
{
	int a[10]={0};
	f(a);
	for(int i=0;i<=9;i++)
	{
		if(a[i]>0)
		printf("%d %d\n",i,a[i]);
	}
}
