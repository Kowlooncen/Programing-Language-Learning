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
    Task("STL2Seq2");
    list<int> L(ptin(0), ptin());
    
//   list<int>::iter;
//    vector<int> V(ptin(0), ptin());
	
//	Show(L.begin(), L.end(), "L: ");

	copy(L.begin(), L.end(), ptout());
	copy(L.rbegin(), L.rend(), ptout());
}
