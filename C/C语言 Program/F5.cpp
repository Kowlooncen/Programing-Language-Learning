#include<stdio.h>
void f(int a[])
{
 int max=a[0];
 for(int i=0;i<=99;i++)
 {
  if(max<a[i])
  max=a[i];
 }
 printf("%d",max);
}
int main()
{
 int a[100];
 for(int i=0;i<=99;i++)
 {
  scanf("%d",&a[i]);
 }
 f(a);
 return 0;
}
