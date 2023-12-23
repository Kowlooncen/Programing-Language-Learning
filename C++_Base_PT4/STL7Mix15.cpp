#include "pt4.h"
using namespace std;

#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
struct Data
{
    int num, year;
    string fam;
    operator string()
    {
        ostringstream os;
        os << "{ num = " << num << ", year = " << year
            << ", fam = " << fam << " }";
        return os.str();
    }
};

istream& operator>>(istream& is, Data& p)
{
    return is >> p.num >> p.year >> p.fam;
}

bool compare(const Data& x1,const Data& x2)
{
	return x1.year > x2.year;
}

void Solve()
{
    Task("STL7Mix15");
    string name1, name2;
    pt >> name1 >> name2;
    ifstream f1(name1.c_str());
    vector<Data> V((istream_iterator<Data>(f1)), istream_iterator<Data>());
    f1.close();
    sort(V.begin(), V.end(), compare);
 //  ShowLine(V.begin(), V.end(), "V: ");
//	int data=*max_element(V.begin(), V.end());
//	 Show(*max_element(V.begin(), V.end()));
    ofstream f2(name2.c_str());
	
	map<int, vector<Data>> M;
	
	for(auto e:V)
	{
		M[e.year].push_back(e);
	}
//	ShowLine(M.begin(), M.end());
	int maxi = 0;
	for(auto x:M)
	{
//		Show(x.second.size());
		if(maxi < x.second.size()) 
			maxi = x.second.size();
	}
	Show(maxi);
	f2 << maxi;

	for(auto x:M)
	{
		if(x.second.size() == maxi) 
		{
			Show(x.first);
			f2 << '\n';
			f2 << x.first;
		}
	}
	
    f2.close();
}
