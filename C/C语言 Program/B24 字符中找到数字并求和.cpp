#include<stdio.h>
int main()
{
	char c;
	int sum=0;
   do{
   	scanf("%c",&c);
   	if(c>='0'&&c<='9')
   	{
   		sum=sum+c-'0';//�ַ�ת�����֣�������� 
	   }
   }while(c!='.');
   printf("%d",sum);
 } 
