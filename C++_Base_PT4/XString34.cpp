#include "pt4.h"
using namespace std;

//Given strings S and S0. Remove the last substring from string S,
//coinciding with S0. If there are no matching substrings, then output string S unchanged 

void Solve()
{
    Task("XString34");
    
    string s, s0;
    
    pt >> s >> s0;
    
    int pos = s.rfind(s0);
    
    if ( pos != -1 )
    {
    	s.erase(pos, s0.length());
    	pt << s;
	}
	else 
		pt<<s;
}
