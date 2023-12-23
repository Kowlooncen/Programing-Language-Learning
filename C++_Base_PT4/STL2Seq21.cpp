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
    Task("STL2Seq21");
    vector<int> V(ptin(0), ptin());

    Show(V.begin(), V.end(), "V: ");
    //copy(V.begin(), V.end(), ptout());
}
