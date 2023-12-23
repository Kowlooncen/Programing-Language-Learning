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
    Task("STL5Assoc19");
    vector<int> V(ptin(0), ptin());

	map<int, vector<int>> M;
	
	for(auto x:V)
	{
		M[abs(x%10)].push_back(x);
	}
	for (auto p : M)
 	{
		pt << p.first;
		copy(p.second.begin(), p.second.end(), ptout_iterator<int>());
 	}
}
