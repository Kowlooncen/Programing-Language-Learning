#include "pt4.h"
using namespace std;

//����һ�б�ʾ��ʽΪ��<digit> �� <digit> �� ... �� <digit>�����������ʽ�����з��š�+����-��λ��������š�������λ�ã����磬��4 + 7?2? 8������ ��ӡ�������ʽ��ֵ����������

void Solve()
{
    Task("XString23");
	
	string str;
	
	int sum = 0;
	pt >> str;
	
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i]=='-')
		{
			sum = sum - (str[i+1] - '0');
			i++;
		}
		else{
			if(str[i]>='0'&&str[i]<='9')
			{
				sum = sum + (str[i]-'0');
			}
		}
	}
	
	pt << sum;
}
