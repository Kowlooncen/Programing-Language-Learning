#include<stdio.h>
#include<math.h>//����ֵ������ 
int main()
{
	int n=1,z=1,c=1,x=1,y=1,pro=1,s=1; 
	float sum=0,std=1;//��ֵ��ѭ���Ľ��� 
	while(fabs(std)>0.001)//����ȷ�� 
	{
		sum=sum+std;
		c=x+y;
		x=y;
		y=c;//�������滻 
		while(s<=n)
		{
			pro=pro*3;
			s++;
		}
		std=1.0*2*n*z/(c*pro);//intתfloat 
		z=-z;//���Ÿı� 
		n++;
	}
	printf("%.3f",sum);
}
