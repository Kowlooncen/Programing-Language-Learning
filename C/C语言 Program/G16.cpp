#include <string.h>
#include <stdio.h>
#define N 1001 

char *strrpc(char *str,char *oldstr,char *newstr){
    char bstr[strlen(str)];//ת��������
    memset(bstr,0,sizeof(bstr));
 
    for(int i = 0;i < strlen(str);i++){
        if(!strncmp(str+i,oldstr,strlen(oldstr))){//����Ŀ���ַ���
            strcat(bstr,newstr);
            i += strlen(oldstr) - 1;
        }else{
        	strncat(bstr,str + i,1);//����һ�ֽڽ�������
	    }
    }
 
    strcpy(str,bstr);
    return str;
} 

int main()
{
	char q[1001]={0};
	 gets(q);
	 strrpc(q,"Ling","Cao");
	 puts(q);
}
