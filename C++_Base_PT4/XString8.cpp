#include "pt4.h"
using namespace std;

//Given an integer N (> 0) and a character C. Print a string of length N, which consists of characters C 

void Solve()
{
    Task("XString8");
	
	int N ;
	char c;
	pt >> N >> c;
	
	string s(N,c);

	pt << s;
}
