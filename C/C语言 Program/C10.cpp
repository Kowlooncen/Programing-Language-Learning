#include <stdio.h>

void print_simple(int a)
{
 for(int i = 2;i<=a;)
 {
  if(a%i==0)
  {
   printf("%d ",i);
   a=a/i;
  }
  else i++;
 } 
}

int main()
{
 int N;
 scanf("%d",&N);
 print_simple(N);
 return 0;
}
