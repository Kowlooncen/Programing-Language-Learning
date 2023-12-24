#include<stdio.h>
#include<string.h>

int main(){
	char q[1001]={0};
	
	gets(q);
	int l=strlen(q);	//知道数组长度
	int count=0;
	while(q[count]==' ')
	{
		count++;
	 } 
	 strcpy(q,q+count);
	 int j=0;
		for(int i=0;i<=l-1;)
		{
			if(q[i]!=' '&&q[i+1]==' '){
				j=i+1;
				while(q[j]==' ')
				{
					j++;
				}
				strcpy(q+i+2,q+j);
				i++;
			}
			else {
				i++;
			} 
		 } 
puts(q);
} 
