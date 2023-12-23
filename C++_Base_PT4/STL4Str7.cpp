#include "pt4.h"
using namespace std;

#include <algorithm>
#include <iterator>
#include <string>

void Solve()
{
    Task("STL4Str7");
	string s;
	pt >> s; 
	string::iterator it = s.begin();
	int i = 0, j = 0;
	int n = s.size();
	Show(i);
	Show(n);
	while(i < n)
	{
		s.insert(s.begin()+j, '*');
		j = j + 2;
		i++;
	}
	Show(s);
	pt << s;
}
