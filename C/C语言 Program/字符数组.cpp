#include<stdio.h>

int main()
{
    char c[ ][9]={
    {'*',' ','*',' ','*',' ','*',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ',' ',' ',' ',' ',' ',' ','*'},
    {'*',' ','*',' ','*',' ','*',' ','*'},
    };
    int i,j;

    for(i=0;i<5;i++)
    {
        for(j=0;j<9;j++)
            printf("%c",c[i][j]);
        printf("\n");
    }

    return 0;
}

//#include<stdio.h>
//#include<string.h> //��ʹ���ַ���������ʱ���ڳ����ļ��Ŀ�ͷ�� #include<string.h>
//int main(){
//   char str[] = "China\nChengdu";
//
//   puts(str);
//   printf("Enter a new string:");
//   gets(str);    //�еı������ᱨ warning����ʾ gets() ��������ȫ��
//                   //����˵��һ�£����warning�Ǳ����������������ģ���Ӱ��ʵ�顣����Ȥ��ͬѧ������Ϊ�κ���ѧ��
//   puts(str);
//
//   return 0;
//}
