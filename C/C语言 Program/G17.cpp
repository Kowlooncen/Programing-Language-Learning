#include<stdio.h>
#include<string.h>

int main(){
	char q[1001]={0};
	
	gets(q);
	int l=strlen(q);	//知道数组长度
	int count=0;
	for(int i=0;i<=l-1;i++)
	{
		if(q[i]!=' ')
		{
			count++;//计数没有空格的长度 
		}
	 } 
	 
	 int j=0;
	if(count%2==0)//如果长度是偶数 
	{
		for(int i=0;i<=l-1;)
		{
			if(q[i]!=' '&&q[i+1]!=' '){
				int c=q[i];
				q[i]=q[i+1];
				q[i+1]=c;
				i+=2;
			}
			else if(q[i]!=' '&&q[i+1]==' ') {
				j=i+1;
				while(q[j]==' ')
				{
					j++;//j计数中间出现空格的下脚标。 
				}
				int c=q[j];
				q[j]=q[i];
				q[i]=c;
				i=j+1; 
			}
			else {
				i++;
			} 
		 } 
	}
		if(count%2==1)//如果长度是奇数 
	{
		for(int i=0;i<=l-2;)
		{
			if(q[i]!=' '&&q[i+1]!=' '){
				int c=q[i];
				q[i]=q[i+1];
				q[i+1]=c;
				i+=2;
			}
			else if(q[i]!=' '&&q[i+1]==' ') {
				j=i+1;
				while(q[j]==' ')
				{
					j++;//j计数中间出现空格的下脚标。 
				}
				int c=q[j];
				q[j]=q[i];
				q[i]=c;
				i=j+1; 
			}
				else {
				i++;
			} 
		 } 
	}
//	printf("%d\n",count);
//	printf("%c\n",q[l-1]);
	puts(q); 
} 
