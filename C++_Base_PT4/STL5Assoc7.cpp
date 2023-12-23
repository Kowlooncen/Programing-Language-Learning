#include "pt4.h"
using namespace std;

#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <algorithm>

typedef ptin_iterator<int> ptin;
typedef ptout_iterator<int> ptout;
void Solve()
{
    Task("STL5Assoc7");
    vector<int> V1(ptin(0), ptin());
    vector<int> V2(ptin(0), ptin());
	multiset<int,greater<int>> x;
	multiset<int> s1(V1.begin(), V1.end());
	multiset<int> s2(V2.begin(), V2.end());
	
	set_symmetric_difference (s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(x,x.begin()));
	
	Show(s1.begin(), s1.end());
	Show(s2.begin(), s2.end());
	copy(x.begin(), x.end(), ptout());
}
