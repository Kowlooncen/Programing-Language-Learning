#include<stdio.h>
//int sum=0;
int f(int x,int sum)
{
	if(x==1) {sum=sum+1;return sum;
	}
	else {sum=sum+x;return f(x-1,sum);
	}
}

int main()
{
	int x;
	scanf("%d",&x);
	printf("%d",f(x,0));
}
