#include "pt4.h"
#include <fstream>

using namespace std;

void Solve()
{
    Task("XText50");
	
	fstream *f = new fstream[3];
	
	for(int i = 0; i < 3; i ++)
	{
		string s;
		
		pt >> s;
		
		if(i < 1)
			f[i].open(s, ios::in);
		else
			f[i].open(s, ios::out | ios::binary);
	}
		
	while(f[0].peek() != -1)
	{
		string s;
	
		getline(f[0], s);
		ShowLine(s);
		
		string sb1 = s.substr(0, 30);
		ShowLine(sb1);
		int n = sb1.length();		 

		for(int i = 0; i < 80; i++)
		{
			char c = sb1[i];
			f[1].write((char*)&c, sizeof(c));
			Show(c);
		} 
		
//		char c = '\0';
//		Show(c);
//		f[1].write((char*)&c, sizeof(c));
		
		string sb2 = s.substr(30);

		double x = atof(sb2.c_str());
		f[2].write((char*)&x, sizeof(x));
	} 
	
	for (int i = 0; i < 3; ++i)
 		f[i].close();
	delete[] f;
	
}
