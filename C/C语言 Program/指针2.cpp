#include<stdio.h>
#define size 4
int main()
{
int a=1;
int *b;
char c='c';
char *d=&c;
b=&a;
a=(void*)d-(void*)b;
printf("%d",a);
 } 
