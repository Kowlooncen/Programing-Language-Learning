#include<stdio.h>
int main()
{
int n,i;
int num[10] = {0};
scanf("%d", &n);
do
 {
  num[n%10]++;//给含该字符的数组加值 
     }while((n = n/10) != 0 );//数的每个字符都提出来进入数组
for(i = 0; i < 10; i++)//调出数组 
{
if(num[i] >= 2)
 {
  printf("YES\n");
  break;
 }
}
if(i == 10)
 {
  printf("NO\n");
 }
 for(i = 0;i<10;i++)
 {
  printf("%d ",num[i]);
 }
return 0;
}
