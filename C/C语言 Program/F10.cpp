#include<stdio.h>
int main()
{
	int a[26]={0},s=1;
	char fu,c;
	scanf("%c",&fu);
	while(c!='.')
	{
		scanf("%c",&c);
		if(c==fu){
			s++;
		}
		if(c!=fu){
			printf("%c%d",fu,s);
			s=1;
			fu=c; 
		}
	}
//	do{
//		scanf("%c",&fu);
		
//		if(fu>='a'&&fu<='z')
//		{
//			s=fu-'a';
//			a[s]++;
//		}
//	}while(fu!='.');
//	for (int i=0;i<26;i++)
//	{
//		if(a[i]>0)
//		{
//			printf("%c%d",'a'+i,a[i]);
//		}
//	}
}
