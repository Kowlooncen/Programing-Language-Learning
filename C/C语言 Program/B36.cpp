#include<stdio.h>
int main()
{
//	int x;
//	scanf("%d",&x);
//	if(x==1) printf("%d",31);
//	if(x==2) printf("%d",29);
//	if(x>=3&&x<=7&&x%2==1) printf("%d",31);
//	if(x>=3&&x<=7&&x%2==0) printf("%d",30);
//	if(x>=8&&x<=12&&x%2==0) printf("%d",31);
//	if(x>=8&&x<=12&&x%2==1) printf("%d",30);
//	if(x<1||x>12) printf("%d",-1);
int x,s;
scanf("%d",&x);
switch(x){

case 1:case 3:case 5:case 7:case 8:case 12:case 10:
s=31; break;//case后面加冒号，例子不加括号。等式和break加分号 
case 4:case 6:case 9:case 11:
s=30; break;
case 2:s=29;break; 
default:s=-1;break;
}
printf("%d",s);
}
