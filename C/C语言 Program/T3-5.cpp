#include<stdio.h>
#include<string.h>
int  main()
{
	char q[1001];
	gets(q);
	int l=strlen(q);
	int b[26]={0};//Ϊ�˰�����ĸ˳�򣬳���һ�ξͼ���һ�Ρ� 
	for(int i=0;i<=l-1;i++)
	{
		b[q[i]-'a']++;//������b��������0~25������ÿһ������������ĸa������ĸ�ľ��룬b������ֵ�����˸��������˺ö�� 
	}
	//��ʼ�ҵ����������ĸ��Ҳ����b������ֵ����0����С����ĸ���ǡ����е������ϡ�a'
	int n=0;
	int min;
	for(int i=0;i<=25;i++)
	{
		if(b[i]>0)
		{
			 min=b[i];//�ҵ���ʼminֵ 
			n=i;//n��ʾΪ��ʼmin���½ű꣬Ҳ������ ��a�������� 
			break;
		}
	 } 
	 	for(int i=0;i<=25;i++)
	{
		if(b[i]>0)
		{
			if(min>b[i])
			{
				min=b[i];
				n=i;
			}
		}
	 } 
	 printf("%c %d",'a'+n,min);
}
