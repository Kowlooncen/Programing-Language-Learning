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
    Task("STL2Seq25");
    list<int>  L1(ptin(0), ptin());
    list<int>  L2(ptin(0), ptin());
	
	list<int>::iterator iter; 
	
	iter = L2.begin();
    
    for(int i = 0; 2 * i < L2.size(); i++)
    {
    	iter++;
	}
    
    L2.splice(iter, L1);

    Show(L2.begin(), L2.end(), "L: ");
    copy(L2.begin(), L2.end(), ptout());
}
