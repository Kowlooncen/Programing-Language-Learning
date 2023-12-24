#include<stdio.h>
int f(int a[])
{
	for(int i=0;i<=98;i++)
	{
		for(int j=i+1;j<=99;j++)
		{
			if(a[i]==a[j])
			{
				return 1;
			}
		}	
		
	}
		return 0;
}
int main()
{
	int a[100];
	for(int i=0;i<=99;i++)
	{
		scanf("%d",&a[i]);
		
	}
	int s=f(a);
	if(s==1) printf("YES");
	if(s==0){
		printf("NO");
	} 
  } 
//#include <stdio.h>
//int LOJ(int num[],int N)
//{
// for(int a=0;a<N;a++)
// {
//  for(int b=a+1;b<N;b++)
//  if(num[a]==num[b])
//  {
//   return 1;
//  }
// }
// return 0;
//
//}
//int main(int argc, char **argv)
//{
// int N =100;
// int num[N];
// for(int a =0;a<N;a++)
// {
//  scanf("%d",&num[a]);
// }
// int a;
// a=LOJ(num,N);
// if(a==1)
// {
//  printf("YES");
// }
// if(a==0)
// {
//  printf("NO");
// } 
// return 0;
//}
