#include<stdio.h>
void f(int x)
{
	if(x/2==0) printf("YES");
	else {
		if(x%2==0){
			f(x/2);
		}
		else{
			printf("NO");
		}
	} 
	 
}
int main()
{
	int x;
	scanf("%d",&x);
	f(x);
 } 
