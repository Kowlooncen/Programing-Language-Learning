#include "pt4.h"
using namespace std;
//给定一个字符串。 计算它包含的大写拉丁字母的数量
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
