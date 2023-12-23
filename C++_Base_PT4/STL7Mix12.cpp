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
    int code, year, month, len;
    operator string()
    {
        ostringstream os;
        os << "{ code = " << code << ", year = " << year
            << ", month = " << month << ", len = " << len << " }";
        return os.str();
    }
};

istream& operator>>(istream& is, Data& p)
{
    return is >> p.len >> p.code >> p.month >> p.year;
}

bool comp(pair<int, int> a, pair<int, int> b)
{
	if(a.first == b.first)
	{
		return (a.second < b.second);
	}
	return (a.first > b.first);
}
void Solve()
{
    Task("STL7Mix12");
    int p;
    pt >> p;
    string name1, name2;
    pt >> name1 >> name2;
    ifstream f1(name1.c_str());
    vector<Data> V((istream_iterator<Data>(f1)), istream_iterator<Data>());
    f1.close();

	map<int, vector<Data>> M1;
	
	for(auto x : V)
	{
		M1[x.year].push_back(x);
	}
	ShowLine(M1.begin(), M1.end());
	Show('\n');
	
	vector<pair<int, int>> v;
	for(auto e : M1)
	{
		int a[13] = {0};
		for(auto n : e.second)
		{
			int m = n.month;
			int l = n.len;
			
			a[m] = a[m] + l;
		}
		ShowLine(a+1, a+13);
		int sum = accumulate(a+1,a+13,0); 
		double q = sum*p*0.01;
		Show("q:",q);
		Show('\n');
		int count = 0;
		for(int i = 1; i < 13; i++)
		{
			if(a[i] > q)
				count ++;
		}
		v.push_back(make_pair( count, e.first));
	}
	
	stable_sort(v.begin(), v.end(), comp);
	ShowLine(v.begin(), v.end());
	
    ofstream f2(name2.c_str());
	
	for(auto r : v)
		f2 << r.first << " " << r.second << endl; 
    f2.close();
}
