#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
 	char s[1001]={0};
	 gets(s);
	 int q[26]={0};
 	int l=strlen(s);
	 for(int a=0;a<=l-1;a++)
 		{
  			q[s[a]-'a']++;//把每一个字母出现的次数表示出来，字母转换成数字 
		 }
		 int k=0;
	for(int i=0;i<=25;i++)
	{
		if(q[i]>0)
		{
			if(q[i]%2==0)
			{
				k=1;
				break;
			}
		}
	 }
	 int count=0;
	 	for(int i=0;i<=25;i++)
	{
		if(q[i]>0)
		{
			if(q[i]%2!=0)
			{
				count++
				;
			}
		}
	 }  
	 if(count!=1) k=0;
	 if(k==1) printf("YES");
	 if(k==0) printf("NO");

}
