#include<stdio.h>
#include<string.h>
int  main()
{
	char q[1001];
	gets(q);
	int l=strlen(q);
	int b[26]={0};//为了按照字母顺序，出现一次就加上一次。 
	for(int i=0;i<=l-1;i++)
	{
		b[q[i]-'a']++;//在数组b【】中有0~25个数，每一个数代表了字母a到该字母的距离，b【】的值代表了该数出现了好多次 
	}
	//开始找到最不常见的字母，也就是b【】的值大于0但最小，字母就是【】中的数加上‘a'
	int n=0;
	int min;
	for(int i=0;i<=25;i++)
	{
		if(b[i]>0)
		{
			 min=b[i];//找到初始min值 
			n=i;//n表示为初始min的下脚标，也就是与 ‘a’相差的数 
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
