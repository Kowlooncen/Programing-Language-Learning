#include "pt4.h"
using namespace std;

#include <algorithm>
#include <iterator>
#include <string>

bool isNum(char ch)
{
	if(ch >= '0'&&ch <= '9')	return true;
	else return false;
 } 

void Solve()
{
    Task("STL4Str26");
	string str;
	pt >> str;
//    Show(str.size());
//    remove_if(str.begin(), str.end(), [](char ch){return isNum(ch);});
//  	Show(str.size());
  	str.erase(remove_if(str.begin(), str.end(), [](char ch){return isNum(ch);}), str.end());
    pt << str;
}
