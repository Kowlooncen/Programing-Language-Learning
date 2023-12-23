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
//删除前半部分的偶数，留下奇数，后半部分不变，然后用move和erase 

bool ifOuShu(int x)
{
	return (x % 2 == 0);
}

void Solve()
{
    Task("STL3Alg31");
    vector<int> V(ptin(0), ptin());
	
	V.erase(remove_if(V.begin(), V.begin() + V.size()/2, ifOuShu), V.begin()+V.size()/2);
	
    Show(V.begin(), V.end(), "V: ");
    copy(V.begin(), V.end(), ptout());
}

/*
erase
作用：删除内存擦除,简单的说，就是能够从内存中擦除掉你想删除的元素 
v.erase(remove(v.begin(), v.end(), 'w'), v.end());
v.erase(remove_if(v.begin(), v.end(), IfEqualThree), v.end());
*/




