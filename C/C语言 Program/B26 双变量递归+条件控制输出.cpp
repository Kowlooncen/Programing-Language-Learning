#include<stdio.h>
int main()
{
	char c,a,b;//类型确定 
	int k=1;//输出判定，限定输出条件 
	scanf("%c",&c);
	while(c!='.')//最后末尾的点必须要消去时就用while不用do-while 
	{
	 a=c;//判定前后两项是否相同的前一项，递归思想 ，两变量 
	 if(k==1)//限定条件 
	 printf("%c",c);
	 k=1; //还原初始值 
	 scanf("%c",&c);
	 b=c;//后一项 
	 if(a==b&&a==' ')//k值转换条件 
	 k=0;
	}
}

