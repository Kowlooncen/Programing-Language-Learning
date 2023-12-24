#include <stdio.h>

int main(int argc, char **argv)
{
 int x;
 scanf("%d",&x);
 int a[22][22]={0};
 for(int i=0;i<=x/2;i++){
  for(int j=i;j<=x-2*i;j++)
  {
   a[i][j]=1;
   } 
 } 
 for(int i=x/2+1;i<=x-1;i++)
 {
  for(int j=x-i-1;j<=2*(i+1)-x;j++)
  {
   a[i][j]=1;
  }
 }
 for(int i=0;i<=x-1;i++)
 {
  for(int j=0;j<=x-1;j++)
  {
   printf("%d",a[i][j]);
  }
  printf("\n");
 }

 return 0;
}
