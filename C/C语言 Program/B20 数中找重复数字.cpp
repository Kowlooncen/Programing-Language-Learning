#include<stdio.h>
int main()
{
	int a,b=0,x;
	int c[10]={0}; //��ֵ����ʼ������ 
	do{
		scanf("%d",&x);
	}while(x<=0);
	while(x!=0)
	{
		a=x%10;
		while(b<10)//��ÿһ�����Ƚ� 
		{
			if(a==b)
			{
				c[a]++;//�ı������ֵ 
			}
			b++;
		}
		x=x/10;
		b=0;//��ʼ�� 
	}
	for(int i=0;i<10;i++)
	{
		if(c[i]>1)//����ظ����� 
		{
			printf("%d ",i );//ֻ�����������ֶ����������ֵ 
		}
	}
	return 0;
}
