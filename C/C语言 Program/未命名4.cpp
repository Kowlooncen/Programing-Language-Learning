#include<stdio.h>
void f(int A[],int N)
{
 int i,j=0,d,b,count=0; 
 scanf("%d",&d);
 if(d==1)
     {
      A[j]=0;
      j++;
     }
 count++;
 for(i=1;i<N;i++)
 {
  scanf("%d",&b);
  if(b==d)count++;
     if(b!=d)
     {
      A[j]=count;
      j++;
      count=1;
  }
  d=b;
 }
 A[j]=count;
 printf("[%d,",A[0]);
 int k; 
 for(k=1;k<=j-1;k++) printf("%d,",A[k]);
 printf("%d]",A[j]);
}

int main()
{
 const int N=10;
 int A[N];
 f(A,N);
 return 0;
}
