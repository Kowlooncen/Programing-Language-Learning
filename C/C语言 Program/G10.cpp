#include<stdio.h>
#include<string.h>
int main()
{
  char a[1001];
  int i;
  int j;
  int m=0,n=0;//��m����¼���ʽ����±꣬��n����¼����ʵĳ���
  int b[1000]={0};
  gets(a);

  for(i=0,j=0;a[i]!='\0';i++){
       if(a[i]!=' '&&i==0){ //˵��һ�����ʿ�ʼ
             j=1;
             }
       else if(a[i-1]==' '&&a[i]!=' '&&i>0){ //˵��һ�����ʿ�ʼ
             j=1;

            }
        if((a[i]!=' '&&a[i+1]==' ')||(a[i]!=' '&&a[i+1]=='\0')){ //˵��һ�����ʽ���

            if(n<j) {
                 n = j;

               }
           b[i] = n;
  //         printf("%d %d\n",i,b[i]);
            }
   j++;
    }
  for(i=0;i<=1000;i++){
     // printf("----b[%d]:%d\n",i,b[i]);
      if(b[i]==n){
           m = i;
           break;
     }
}
 for(i=m-n+1;i<=m;i++){
      printf("%c",a[i]);
      }
}

