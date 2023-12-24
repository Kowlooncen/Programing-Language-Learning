#include<stdio.h>

int main()
{
	char c;
	scanf("%c",&c);
	do
	{
		if(c>='A'&&c<='Z')
		printf("%c",c-'A'+'a');//大写转小写，巧妙求值 
		else printf("%c",c);
		scanf("%c",&c);
	}while(c!='.');
	return 0;

}
