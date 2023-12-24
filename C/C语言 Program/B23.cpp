#include<stdio.h>
int main()
{
	char c;
	int n=0;
   do{
   	scanf("%c",&c);
   	if(c>='0'&&c<='9')
   	{
   		n++;
	   }
   }while(c!='.');
   printf("%d",n);
 } 
