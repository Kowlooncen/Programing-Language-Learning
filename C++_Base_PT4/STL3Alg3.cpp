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

void Solve()
{
    Task("STL3Alg3");
    list<int> L(ptin(0), ptin());
    
    list<int>::iterator iter1 = find(L.begin(), L.end(), 0);
    
    if(iter1 != L.end()) 
	{
    	L.erase(iter1);
    	list<int>::reverse_iterator iter2 = find(L.rbegin(), L.rend(), 0); 
    	if(iter2 != L.rend()) {
			L.erase((++iter2).base());
		}
	}

    Show(L.begin(), L.end(), "L: ");
    copy(L.begin(), L.end(), ptout());
}
