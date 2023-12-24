#include <stdio.h>
unsigned long long int f(int x)
{
 unsigned long long int a=1 ;
 for (int i=1 ;i<x;i++)
 {
  a=a*2 ;
 }
 return a;
}
int main()
{
 int a;
 scanf("%d",&a);
 printf("%llu",f(a));
 return 0;
}
