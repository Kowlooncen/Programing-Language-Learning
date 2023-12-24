#include<stdio.h>
int f(int n,int m)
{
	if(n==1) return 0;
	if(n>=m*m) {
		if(n%m==0) {return 0;
		}
		else{
			return f(n,m+1);
		}
	}
	else{
		return 1;
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	if(f(a,2)) printf("YES");
	else printf("NO");
}
