#include "pt4.h"
using namespace std;

//给定一行表示形式为“<digit> ± <digit> ± ... ± <digit>”的算术表达式，其中符号“+”或“-”位于运算符号“±”的位置（例如，“4 + 7?2? 8”）。 打印给定表达式的值（整数）。

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
