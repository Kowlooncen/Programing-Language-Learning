#include "pt4.h"
using namespace std;

#include <iterator>
#include <vector>
#include <deque>
#include <list>

typedef ptin_iterator<int> ptin;
typedef ptout_iterator<int> ptout;

void Solve()
{
    Task("STL2Seq11");
    vector<int> V(ptin(0), ptin());
    list<int>   L(ptin(0), ptin());
    
    list<int>::iterator iter = L.begin();
    
    for(int i = 0; i < 5; i++)
    {
    	iter++;
	}
    
    L.insert(iter, V.rend()-5, V.rend());

    Show(L.begin(), L.end(), "L: ");
    copy(L.begin(), L.end(), ptout());
}
