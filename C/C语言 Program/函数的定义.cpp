//#include<stdio.h>
//
//int main(){
//    int max(int x,int y);    //���� max ����
//    int a = 10,b = 20;
//    int c;
//    c = max(a,b);                //a, b Ϊʵ�ʲ���������max���������ݵ���a��b��ֵ�� max ������
//    printf("%d",c);
//
//    return 0;
//}
//
//int max(int x,int y){         //int ������Ƿ���ֵ�� int ��
//    int z;
//    z = x>y ? x:y;
//    return (z);                //���� z
//}
#include<stdio.h>
int main()
{
	int a=1,b=2;
	int c;
	int max(int x,int y);
	c=max(a,b);
	printf("%d",c);
}
int max(int x,int y)
{
	int z;
	z=x>y?x:y;
	return(z);
}
