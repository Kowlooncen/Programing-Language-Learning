#include<stdio.h>

int main()
{
	char c;
	scanf("%c",&c);
	do
	{
		if(c>='A'&&c<='Z')
		printf("%c",c-'A'+'a');//��дתСд��������ֵ 
		else printf("%c",c);
		scanf("%c",&c);
	}while(c!='.');
	return 0;

}
