#include<stdio.h>
#include<string.h>

int main(){
    char string[30];
    // ����һ����ά����
    // ch[1]��ch[2]��ch[3] ����һ���ַ����飬�൱�������ַ���
    char ch[3][30];
    int i;
    // ѭ����ȡ���У����ҽ�ÿ�д浽 ch[i] ��
    for(i=0;i<3;i++)
        gets(ch[i]);
    strcpy(string,ch[0]);
    for(i=1;i<3;i++)
        if(strcmp(ch[i],string)<0)
            strcpy(string,ch[i]);
    printf("The result is :\n%s",string);

    return 0;
}
