
 #include <stdio.h>
int main()
{
	int x;
	do{
		scanf("%d",&x);
	}while(x%2==0||x<0);
	int i,j,k;
	for(i=1;i<=(x/2+1);i++)
	{
		for(j=1;j<=(x/2+1)-i;j++) printf(" ");
		for(k=1;k<=(2*i-1);k++) 
		{
			if(i%2==1)
			{
				printf("+");
			
			 } 
			if(i%2==0) 
			{
				printf("-");				
			}
			
		}
		printf("\n");
	}
	for(i=1;i<=x/2;i++)
	{
		for(j=1;j<=i;j++) printf(" ");
		for(k=1;k<=x-2*i;k++) 
		{
			if((x/2+1+i)%2==0)
			{
				printf("-");
			 } 
			if((x/2+1+i)%2==1) 
			{
				printf("+");	
			}
			
		}
		printf("\n");
	}
}
