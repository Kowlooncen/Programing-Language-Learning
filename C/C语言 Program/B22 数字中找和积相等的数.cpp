#include<stdio.h>
int main()
{
	int x;
	do{
		scanf("%d",&x);
	}while(x<=10);
	int a;
	int sum=0;
	int pro=1;//经典赋值 
	int i,j;
	for(i=10;i<=x;i++)
	{
		j=i;//巧妙引入变量 
		while(j!=0)
		{
			a=j%10;
			sum=sum+a;
			pro=pro*a;
			j=j/10;
		}
		if(sum==pro)
		{
			printf("%d ",i);
		}
		sum=0;//初始化 
		pro=1;//初始化 
	}
	return 0;
}
