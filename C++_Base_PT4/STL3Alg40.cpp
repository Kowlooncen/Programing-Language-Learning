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
//输出偶数和奇数个数，使用 partitio和distance 

bool cmp(int i) { return (i % 2) == 0; }

class cmp2{
public:
    bool operator()(const int& i) {
        return (i%2 == 0);
    }
};

void Solve()
{
    Task("STL3Alg40");
    list<int> L(ptin(0), ptin());
    list<int>::iterator iter;
	iter = partition(L.begin(), L.end(), cmp2());
	//Show(*iter);
	int d1 = distance(L.begin(), iter) ;
	int d2= distance(iter, L.end()) ;
	pt << d1 << d2;
    //Show(L.begin(), L.end(), "L: ");
    //copy(L.begin(), L.end(), ptout());
}
