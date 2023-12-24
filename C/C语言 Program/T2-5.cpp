#include<stdio.h>
int f(int x,int y)
{
	if(x-y==0) return x;
	else{
		if(x<y) {
			return f(x,y-x);
		}
		else{
			return f(x-y,y);
		}
	}
}

int main()
{
	int x,y;
	scanf("%d %d",&x,&y);
	printf("%d",f(x,y));
}
