#include "pt4.h"
using namespace std;
//����һ���ַ����� �����������Ĵ�д������ĸ������
void Solve()
{
    Task("XString14");
	
	string str;
	int count=0;
	
	pt >> str;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
		{
			count++;
		}
	}
	
	pt << count;
}
