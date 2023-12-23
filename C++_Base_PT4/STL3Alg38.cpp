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

//�ҳ���������������ֵ��������������õ� partial_sort��greater �� copy 

void Solve()
{
    Task("STL3Alg38");
    vector<int> V(ptin(0), ptin());

	partial_sort(V.begin(), V.begin()+3, V.end(), greater<int>());
    Show(V.begin(), V.end(), "V: ");
    copy(V.begin(), V.begin() + 3, ptout());
}
