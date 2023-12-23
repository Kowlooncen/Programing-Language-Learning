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
    Task("STL5Assoc21");
    vector<int> V(ptin(0), ptin());
	
	multimap<int, int> M;
 	for (auto x : V){

 		M.insert(pair<int, int>(abs(x%10), x));
	 }
 		
	for (auto p : M)
 	{
 		pt << p.first;
 		pt << p.second;
 		//copy(p.second.begin(), p.second.end(), ptout_iterator<int>());
 	}
}

