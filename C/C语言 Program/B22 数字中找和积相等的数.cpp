#include<stdio.h>
int main()
{
	int x;
	do{
		scanf("%d",&x);
	}while(x<=10);
	int a;
	int sum=0;
	int pro=1;//���丳ֵ 
	int i,j;
	for(i=10;i<=x;i++)
	{
		j=i;//����������� 
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
		sum=0;//��ʼ�� 
		pro=1;//��ʼ�� 
	}
	return 0;
}
