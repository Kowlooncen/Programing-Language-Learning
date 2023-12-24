#include<stdio.h>
int main()
{
	int a,b=0,x;
	int c[10]={0}; //赋值，初始化数组 
	do{
		scanf("%d",&x);
	}while(x<=0);
	while(x!=0)
	{
		a=x%10;
		while(b<10)//和每一个数比较 
		{
			if(a==b)
			{
				c[a]++;//改变数组的值 
			}
			b++;
		}
		x=x/10;
		b=0;//初始化 
	}
	for(int i=0;i<10;i++)
	{
		if(c[i]>1)//输出重复的数 
		{
			printf("%d ",i );//只是输出这个数字而不是数组的值 
		}
	}
	return 0;
}
