#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
 	char s[1001];
 gets(s);
	 int q[26]={0};
 int l=strlen(s);
	 for(int a=0;a<=l-1;a++)
 	{
  			q[s[a]-'a']++;//��ÿһ����ĸ���ֵĴ�����ʾ��������ĸת�������� 
	 }
 int c;
 	for(int a=0;a<26;a++)
 {
  if(q[a]>0)
  {
  	 if(q[a]%2==1)//���������� 
   {
 	   c=a;
 	   break;//ֻҪ�ҵ��ˣ���ô����˳�����ĸΪ�����ľͲ����� 
   }
              
  }
 }
 for(int a=0;a<26;a++)
 {
  if(q[a]>1)
  {
  		 if(q[a]%2==0)//����ż���Σ��������� 
   {
    for(int b=0;b<q[a]/2;b++)
    {
   	  printf("%c",a+'a');
    }
   }
   else//��Ȼ�������� 
   {
    for(int b=0;b<(q[a]-1)/2;b++)
    {
     printf("%c",a+'a');
    }
   }
  }
 }
 printf("%c",c+'a');//�м����� 
 for(int a=25;a>=0;a--)
 {
  if(q[a]>1)
  {
   if(q[a]%2==0)
   {
    for(int b=0;b<q[a]/2;b++)
    {
     printf("%c",a+'a');
    }
   }
   else
   {
    for(int b=0;b<(q[a]-1)/2;b++)
    {
     printf("%c",a+'a');
    }
   }
  }
 }
 return 0;
}
