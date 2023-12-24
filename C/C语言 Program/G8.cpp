#include<stdio.h>
int main()
{
	char q[1001];
	scanf("%1000[^\n]s",q);
	int a[1000]={0};
	int i=0;
	int j=0;
	while(q[i]!='\0')
	{
		if(q[i+1]<='9'&&q[i+1]>='0')
		{
			if(q[i]<='9'&&q[i]>='0')
			{	
				a[j]=a[j]*10+(q[i]-'0');
			}
		}
		else{
			if(q[i]<='9'&&q[i]>='0')
			{	
				a[j]=a[j]*10+(q[i]-'0');
				j++;
			}	
		}
		i++;
	}
	for(int k=0;k<=j-2;k++)
	{
		for(int q=k+1;q<=j-1;q++)
		{
			if(a[k]>a[q])
			{
				int c=a[k];
				a[k]=a[q];
				a[q]=c;
			}
		}
	}
	for(int k=0;k<=j-1;k++)
	{
		printf("%d ",a[k]);
	}
}
