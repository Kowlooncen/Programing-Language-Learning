#include <stdio.h>
#include<string.h>
int main()
{
	 char s[1001];
	 gets(s);
	 char q[6]=".html";
	 int l=strlen(s);
	 int i=0; 
	 for(int a=l;a>=0;a--)
 {
  if(s[a]=='.')
  {
   s[a]='\0';
   break;
  }
  if(s[a]=='/')
  {
   break;
  }
 }     
	 strcat(s,q);
	 puts(s);
}  
