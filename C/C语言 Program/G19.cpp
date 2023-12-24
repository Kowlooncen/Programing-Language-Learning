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
  			q[s[a]-'a']++;//把每一个字母出现的次数表示出来，字母转换成数字 
	 }
 int c;
 	for(int a=0;a<26;a++)
 {
  if(q[a]>0)
  {
  	 if(q[a]%2==1)//出现奇数次 
   {
 	   c=a;
 	   break;//只要找到了，那么后面顺序的字母为奇数的就不管了 
   }
              
  }
 }
 for(int a=0;a<26;a++)
 {
  if(q[a]>1)
  {
  		 if(q[a]%2==0)//出现偶数次，放在两侧 
   {
    for(int b=0;b<q[a]/2;b++)
    {
   	  printf("%c",a+'a');
    }
   }
   else//依然是奇数次 
   {
    for(int b=0;b<(q[a]-1)/2;b++)
    {
     printf("%c",a+'a');
    }
   }
  }
 }
 printf("%c",c+'a');//中间数字 
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
