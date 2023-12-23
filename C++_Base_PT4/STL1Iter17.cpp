#include "pt4.h"
#include<fstream>
#include<algorithm>

using namespace std;

typedef ptin_iterator<char> ptin;

int func(char c)
{
	return 2 * c;
}

void Solve()
{
    Task("STL1Iter17");
	
	string name;
	
	pt >> name;
	Show(ptin(0), ptin());
	int k;
	ofstream os(name);
	transform(ptin(0), ptin(), ostream_iterator<int>(os," "), [](char c){return (int)(2*c);});
		
	os.close();
}

