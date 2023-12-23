#include "pt4.h"
#include <fstream>

using namespace std;

void Solve()
{
    Task("XFile41");
    
	string s1;

	pt >> s1;
	
	string s2 = "XFile41.tmp";

	ifstream f1(s1, ios::binary);
	ofstream f2(s2, ios::binary);
	
	f1.seekg(0, ios::end);
	int len = f1.tellg();
 	int size = sizeof(int);
 	int k = len / size;
 	
	f1.seekg(0,ios::beg);
	
	int y = 0;
	
	for (int i = 1; i <= k; ++i)
	{
//		f1.seekg(f1.tellg());
		int x;
		f1.read((char *)&x, size);
		f1.seekg(size * i);		
  		if(x > 0) {
 			f2.write((char*)&y,size);
 			f2.write((char*)&y,size);
 			f2.write((char*)&y,size);
		}
 		else{
 				f2.write((char *)&x, size);
		 }
	}
	
	f2.close();
	f1.close();
	
	remove(s1.c_str());
	rename(s2.c_str(), s1.c_str());
}
