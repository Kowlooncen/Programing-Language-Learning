#include<stdio.h>
int main()
{
int n,i;
int num[10] = {0};
scanf("%d", &n);
do
 {
  num[n%10]++;//�������ַ��������ֵ 
     }while((n = n/10) != 0 );//����ÿ���ַ����������������
for(i = 0; i < 10; i++)//�������� 
{
if(num[i] >= 2)
 {
  printf("YES\n");
  break;
 }
}
if(i == 10)
 {
  printf("NO\n");
 }
 for(i = 0;i<10;i++)
 {
  printf("%d ",num[i]);
 }
return 0;
}
