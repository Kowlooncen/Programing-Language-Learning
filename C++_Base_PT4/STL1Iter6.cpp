#include "pt4.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef ptin_iterator<char> ptin;

void Solve()
{
    Task("STL1Iter6");
    
	string s;
	pt >> s;
	ofstream os(s);
	
	ostream_iterator<char> it(os," ");
	copy(ptin(0), ptin(), it); 
}
