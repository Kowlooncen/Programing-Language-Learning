#include<stdio.h>
int main()
{
	int x;
	do{
		scanf("%d",&x);
		if(x%2!=0) printf("%d ",x);//负数的余数是奇数 
	}while(x!=0);
	return 0; 
}

