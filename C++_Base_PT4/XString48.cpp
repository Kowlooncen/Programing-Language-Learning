#include "pt4.h"
using namespace std;

void Solve()
{
    Task("XString48");
    
	string s;
    
    //getline(cin,s);
    
    pt >> s;
    
    char c = s[0];
    
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i] == c)
		{
			s[i] = '.';
		}
		
		if(s[i] == ' ' && s[i+1] != ' ')
		{
			c = s[i+1];
			i++;
		} 
	}
	
	pt << s;
}
