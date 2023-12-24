#include<stdio.h>
#include<math.h>//绝对值函数库 
int main()
{
	int n=1,z=1,c=1,x=1,y=1,pro=1,s=1; 
	float sum=0,std=1;//赋值，循环的进入 
	while(fabs(std)>0.001)//精度确认 
	{
		sum=sum+std;
		c=x+y;
		x=y;
		y=c;//变量的替换 
		while(s<=n)
		{
			pro=pro*3;
			s++;
		}
		std=1.0*2*n*z/(c*pro);//int转float 
		z=-z;//符号改变 
		n++;
	}
	printf("%.3f",sum);
}
