#include "pt4.h"
using namespace std;

#include <algorithm>
#include <iterator>
#include <string>

void Solve()
{
    Task("STL4Str11");
    string s;
    pt >> s;

	int i = 0;
	int l = s.length(); 
    for (int nIndex = 0; nIndex < l; ++nIndex)
    {
        if ((nIndex+1) % 3 == 0)
        {
        	s.erase(nIndex - i, 1);
        	i++;
		}
            
        Show(nIndex);
    }
    Show(s);
    
    pt << s; 
}
