#include<stdio.h>
void f(int x,int i);
int main()
{
	int x;
	scanf("%d",&x);
	f(x,2);
}
void f(int x,int i)
{
	if(i>x) return;//����void����return����ʲô�����ӾͿ����ˣ�
	if(x%i==0){
		printf("%d ",i);
		f(x/i,i);
	} 
	else{
		f(x,i+1);
	}
}
