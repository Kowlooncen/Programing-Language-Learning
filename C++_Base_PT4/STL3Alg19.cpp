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
    Task("STL3Alg19");
    int n;
    pt >> n;
    deque<int> D(ptin(0), ptin());
	int x = n + 1;
	generate_n(front_inserter(D), n, [&x]{
	    	x--;
	    	return x;
		}
	);
	
	int y = n + 1;
	generate_n(back_inserter(D), n, [&y]{
	    	y--;
	    	return y;
		}
	);
	 
    Show(D.begin(), D.end(), "D: ");
    copy(D.begin(), D.end(), ptout());
}
