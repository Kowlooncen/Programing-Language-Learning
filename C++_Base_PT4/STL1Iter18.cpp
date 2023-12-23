#include "pt4.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

void Solve()
{
    Task("STL1Iter18");
    
	string name;
	
	int K;
	
	pt >> name >> K;
	
	ofstream os(name);
	
	ostream_iterator<char> ot(os);
	
	fill_n(ot, K, '*');
}
