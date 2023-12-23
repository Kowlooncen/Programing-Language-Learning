#include "pt4.h"
using namespace std;

void Solve()
{
    Task("XString62");
    
    string str;
	
	pt >> str;
	
	for(int i = 0; i <= str.size(); i++)
	{
		if( (str[i]>='a'&&str[i]<'z') || (str[i]>='A'&&str[i]<'Z'))
		{
			str[i] = str[i] + 1;
		}
		else if(str[i] == 'z' )
		{
			str[i] = 'a';
		}
		else if(str[i] == 'Z')
		{
			str[i] = 'A';
		}
	}
	
	pt << str;

}
