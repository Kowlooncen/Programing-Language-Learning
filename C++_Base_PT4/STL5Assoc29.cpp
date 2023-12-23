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
    Task("STL5Assoc29");
    vector<int> V1(ptin(0), ptin());
    vector<int> V2(ptin(0), ptin());
	
	map<int, vector<int>> M;

	for (auto x : V2)
	{
		M[abs(x % 10)].push_back(x);
	}
//	Show(M.begin(), M.end());	
//	Show('\n');
	vector<pair<int, int>>V;
	
	for (vector<int>::iterator vi = V1.begin(); vi != V1.end(); vi++)
	{
		int key = abs((*vi) % 10);
//		Show(key);

		map<int, vector<int>>::iterator iter = M.find(key);
		if(iter != M.end())
	    {
	    	vector<int>::iterator it = iter->second.begin();
//			Show(*it);
			while(it != iter->second.end()) 
			{
//				Show(*it);
				V.push_back(make_pair(*vi, *it));
				it++;
			}
//			Show('\n');
	    }
	
//		
		
	} 
 	Show(V.size());
 	Show(V.begin(), V.end());
 	pt << V.size();
	copy(V.begin(), V.end(), ptout_iterator<pair<int, int>>());
}

