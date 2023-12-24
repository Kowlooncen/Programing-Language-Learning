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
//#include<string.h> //在使用字符串处理函数时，在程序文件的开头用 #include<string.h>
//int main(){
//   char str[] = "China\nChengdu";
//
//   puts(str);
//   printf("Enter a new string:");
//   gets(str);    //有的编译器会报 warning，提示 gets() 函数不安全；
//                   //这里说明一下，这个warning是编译器针对这个函数的，不影响实验。感兴趣的同学可以作为课后自学。
//   puts(str);
//
//   return 0;
//}
