#include "pt4.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef ptin_iterator<double> ptin;
typedef ptout_iterator<double> ptout;

int n = 0;

bool func(double a)
{
	if(n % 2 == 0)
	{
		n++;
		return true;
	}
	else{
		n++;
		return false;
	}
}

void Solve()
{
    Task("STL1Iter14");
    remove_copy_if(ptin(0), ptin(), ptout(), func);

}
