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

//以函数对象的形式定义一个匹配规则
class comp {
public:
    bool operator()(const int& i, const int& j) {
        return (i > j);
    }
};

void Solve()
{
    Task("STL3Alg9");
    int k; 
    pt >> k;
    vector<int> V(ptin(0), ptin());
    
    vector<int>::iterator iter = search_n(V.begin(), V.end(), k, 0, comp()); 
    
    if (iter != V.end()) {
        int i = 0;
        while(i != k)
        {
        	V.insert(iter + k + i, *(iter + i));
        	i++;	
		}
    }

    Show(V.begin(), V.end(), "V: ");
    copy(V.begin(), V.end(), ptout());
}
