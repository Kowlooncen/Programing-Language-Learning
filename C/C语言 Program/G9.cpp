#include<stdio.h>
#include<string.h>
int main(void)
{
    char s[1001];
   int i, j, n, k;
    gets(s);
    for (n = 0; s[n] != '\0'; n++)
;
	int count=0;
	while(s[count]==0)
	{
		count++;
	 } 
	  for (i = count; i < n ; i++)
    {
        for (j =  i + 1; j < n ; j++)
            if (s[j] == s[i])
                s[j]=' ';
    }

 for(int a=0;s[a]!='\0';a++)
 {
  if(s[a]!=' ')
  {
   printf("%c",s[a]);
  }
 }
 return 0;
} 
