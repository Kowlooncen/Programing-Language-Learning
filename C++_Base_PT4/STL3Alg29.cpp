#include "pt4.h"
using namespace std;

#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <functional>
typedef ptin_iterator<int> ptin;
typedef ptout_iterator<int> ptout;

int j = 0; 

bool bools(int i)
{
	if(i >= 0)
	{
		j++;
		return false;		
	}
	return true;
}

void Solve()
{
    Task("STL3Alg29");
    vector<int> V(ptin(0), ptin());

	vector<int> V0;
	V0.insert(V0.end(), V.begin(), V.end());
	remove_copy_if(V.begin() + V.size()/2, V.end(), V0.begin(), bools);
	V0.insert(V0.begin() + j, V.begin(), V.begin() + j);
	Show(j);
	
	Show(V0.begin(), V0.end(), "V0': ");
    copy(V0.begin(), V0.end(), ptout());
}
