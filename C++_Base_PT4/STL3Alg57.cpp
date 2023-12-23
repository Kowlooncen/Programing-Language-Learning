#include "pt4.h"
using namespace std;

#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
typedef ptin_iterator<string> ptin;

void Solve()
{
    Task("STL3Alg57");
    vector<string> V(ptin(0), ptin());
	vector<string>::reverse_iterator iter;
	int i = 0;
	vector<char> V1;
	for(iter = V.rbegin(); iter != V.rend(); iter ++)
	{
		string s = *iter;
		V1.push_back(s[0]);
		i++;
	}
	Show(V1.begin(), V1.end());
	string s = accumulate(V1.begin(), V1.end(), (string)"");;
	pt << s;
}
