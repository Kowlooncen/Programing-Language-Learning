#include<stdio.h>
int f(void)
{
	char c;
	int s=0;
	scanf("%c",&c);
	while(c!='.')
	{
		if(c=='(') s++;
		if(c==')') s--;
		if(s<0) break;
		scanf("%c",&c);
	}
	return (s==0);
}
int main()
{
	if(f()) printf("YES");
	else printf("NO");
}
