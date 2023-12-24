//#include<stdio.h>
//
//int main(){
//    int max(int x,int y);    //声明 max 函数
//    int a = 10,b = 20;
//    int c;
//    c = max(a,b);                //a, b 为实际参数；调用max函数，传递的是a，b的值给 max 函数。
//    printf("%d",c);
//
//    return 0;
//}
//
//int max(int x,int y){         //int 代表的是返回值是 int 型
//    int z;
//    z = x>y ? x:y;
//    return (z);                //返回 z
//}
#include<stdio.h>
int main()
{
	int a=1,b=2;
	int c;
	int max(int x,int y);
	c=max(a,b);
	printf("%d",c);
}
int max(int x,int y)
{
	int z;
	z=x>y?x:y;
	return(z);
}
