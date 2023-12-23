#include "pt4.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

bool equal_6(string s)
{
    return s.size()==6;
}

void Solve()
{
    Task("STL1Iter3");
	string s;
	
	pt >> s;
	
	ifstream  is(s);
	
	istream_iterator<string> it(is);
	istream_iterator<string> eos;
	
	int result1 = count_if(it, eos, equal_6);
    
	pt << result1;
}

