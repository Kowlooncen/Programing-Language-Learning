#include "pt4.h"
using namespace std;

#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <functional>
typedef ptin_iterator<string> ptin;
typedef ptout_iterator<string> ptout;
//把队列里的每个字符串元素，先按长度降序排列，在相同的长度，按字母升序排列A前Z后 

bool len(string s1, string s2)
{
	if(s1.length() > s2.length()) return true;
	else if(s1.length() == s2.length())
	{
		if(s1 <= s2) return true;
	}
	else return false;
}

void Solve()
{
    Task("STL3Alg46");
    deque<string> D(ptin(0), ptin());
	
	sort(D.begin(), D.end(), len);
    Show(D.begin(), D.end(), "D: ");
    copy(D.begin(), D.end(), ptout());
    
}
