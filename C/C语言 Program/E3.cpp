#include<stdio.h>
int main()
{
	long int a[10]={0};
	long int min,max;
	for(int i=0;i<=9;i++)
	{
		scanf("%ld",&a[i]);
	}
	min=a[0];
	max=a[0];
	int m=0,n=0;
	for(int i=0;i<=9;i++)
	{
		if(a[i]<min){
			min=a[i];
			m=i;
		} 
		if(a[i]>max){
			max=a[i];
			n=i;
		} 
	}
	printf("%d %ld %d %ld",n+1,max,m+1,min);
}
