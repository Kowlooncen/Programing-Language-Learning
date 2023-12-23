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
//ɾ��ǰ�벿�ֵ�ż����������������벿�ֲ��䣬Ȼ����move��erase 

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
���ã�ɾ���ڴ����,�򵥵�˵�������ܹ����ڴ��в���������ɾ����Ԫ�� 
v.erase(remove(v.begin(), v.end(), 'w'), v.end());
v.erase(remove_if(v.begin(), v.end(), IfEqualThree), v.end());
*/




