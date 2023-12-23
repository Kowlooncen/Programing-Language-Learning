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
    Task("STL3Alg21");
    int k;
    pt >> k;
    list<int> L1(ptin(0), ptin());
    list<int> L2(ptin(0), ptin());

	auto start1 = L1.begin();
	auto end_iter1 = L1.end();	
	auto mid_iter1 = L1.begin();
	advance(mid_iter1, L1.size() - k);
	rotate(start1, mid_iter1, end_iter1);
	
	auto start2 = L2.begin();
	auto end_iter2 = L2.end();
	auto mid_iter2 = L2.begin();
	advance(mid_iter2, k);
	rotate(start2, mid_iter2, end_iter2);
    Show(L1.begin(), L1.end(), "L1: ");
    Show(L2.begin(), L2.end(), "L2: ");
    copy(L1.begin(), L1.end(), ptout());
    copy(L2.begin(), L2.end(), ptout());
}
