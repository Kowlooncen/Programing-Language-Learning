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
    Task("STL2Seq23");
    list<int>  L(ptin(0), ptin());
    deque<int> D(ptin(0), ptin()); 
	
	L.insert(L.begin(), D.begin(), D.begin()+D.size()/2);
	L.insert(L.end(), D.begin()+D.size()/2, D.end());
	
    Show(L.begin(), L.end(), "L: ");
    //Show(D.begin(), D.end(), "D: ");
    copy(L.begin(), L.end(), ptout());
    //copy(D.begin(), D.end(), ptout());
}
