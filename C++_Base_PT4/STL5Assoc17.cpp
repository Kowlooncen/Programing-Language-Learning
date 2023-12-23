#include "pt4.h"
using namespace std;

#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <algorithm>

typedef ptin_iterator<string> ptin;

void Solve()
{
    Task("STL5Assoc17");
    vector<string> V(ptin(0), ptin());

	map<char, int> M;
	vector<string>::iterator iter;
	for(iter = V.begin(); iter != V.end(); iter++)
	{
		string str = *iter;
		int len = str.size();
		
		vector<string>::iterator it = iter + 1;
		for(; it != V.end(); it++)
		{
			string s = *it;
			if(s[0] == str[0])
			{
				Show("s:",s);
				Show("str:",str);
				len = len + s.size();
			}
		}
		Show("len:", len);
		Show('\n');
		M.insert(pair<char, int>(str[0], len));
	}
		
	for(auto p:M)
	{
		pt << p.first;
		pt << p.second;
	}
}
