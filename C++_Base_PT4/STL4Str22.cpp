#include "pt4.h"
using namespace std;

#include <algorithm>
#include <iterator>
#include <string>

bool isNum(char ch)
{
	if(ch >= '0'&&ch <= '9')
		return true;
	else return false;
}

bool isAlphbet(char ch)
{
	if(ch >= 'A'&&ch <= 'Z')
		return true;
	else return false;
}

void Solve()
{
    Task("STL4Str22");
	
	string s;
	pt >> s;
	
	int mid = s.size()/2;
	
	replace_if(s.begin(), s.begin()+mid, [](char ch){return isNum(ch);}, '*'); 
	replace_if(s.begin()+mid, s.end(), [](char ch){return isAlphbet(ch);}, '_');
	pt << s;
	Show(s);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
