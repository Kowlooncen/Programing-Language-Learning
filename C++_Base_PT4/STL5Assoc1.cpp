#include "pt4.h"
using namespace std;

#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <algorithm>

typedef ptin_iterator<int> ptin;

void Solve()
{
    Task("STL5Assoc1");
    vector<int> V(ptin(0), ptin());

	set<int> s1(V.begin(),V.begin()+V.size()/2);
	set<int> s2(V.begin()+V.size()/2, V.end());
	Show(s1.begin(),s1.end());
	Show(s2.begin(),s2.end());
	pt << includes(s1.begin(), s1.end(), s2.begin(), s2.end());
}

