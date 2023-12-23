#include "pt4.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

void Solve()
{
    Task("STL1Iter7");

	string name1, name2;
	
	pt >> name1 >> name2;
	
	ifstream is(name1);
	ofstream os(name2);
	
	istream_iterator<int> it(is);
	istream_iterator<int> eos;
	
	ostream_iterator<int> ot(os,"\n");
	
	remove_copy(it, eos, ot, 0);
} 
