#include<stdio.h>
int f(int x)
{
	if(x%2==0) return 1;//Å¼Êı
	if(x%2!=0) return 0;//ÆæÊı 
}

int main()
{
	int pro=1;
	int a[10];
	int oushu=0,jishu=0;
	for(int i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
		if(f(a[i])) {
			oushu++;
		}
		else{
			jishu++;
		}
	}
	if(oushu>jishu)
	{
		for(int i=0;i<=9;i++)
		{
			if(f(a[i])==0){
				int s=a[i];
				while(s!=0){
					if(f(s%10)==0)
					{
						pro=pro*(s%10);
					}
					s=s/10;
				}
				a[i]=pro;
				pro=1;
			}	
		}
	}
	if(jishu>=oushu)
	{
			for(int i=0;i<=9;i++)
		{
			if(f(a[i])){
				while(a[i]!=0){
					if(f(a[i]%10))
					{
						pro=pro*(a[i]%10);
					}
					a[i]=a[i]/10;
				}
				a[i]=pro;
				pro=1;
			}	
		}	
	}
	for(int i=0;i<=9;i++)
	{
		printf("%d ",a[i]);
	}
 } 
