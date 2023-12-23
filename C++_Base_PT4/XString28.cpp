#include "pt4.h"
using namespace std;

void Solve()
{
    Task("XString28");
    
    char c;
	
	pt >> c;
	
	string str;
	
	pt >> str;
	
	int n = 0;
	
	int i = 0;
	
	while(1)
	{
		n = str.find(c,i);
		
		if(n < 0) break;
		
		str=str.replace(n,1,2,c);
		
		i=n+2;
		
	}
	
	pt << str;
	
}
