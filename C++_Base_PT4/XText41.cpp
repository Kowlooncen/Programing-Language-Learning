#include "pt4.h"
#include <fstream>
#include <iomanip>
#include"stdlib.h"
using namespace std;

void Solve()
{
    Task("XText41");
    
	fstream *f = new fstream[4];
	
	for(int i = 0;i < 4; ++i)
	{
		string s;
		pt >> s;
		if( i < 3)
			f[i].open(s, ios::binary | ios::in);
		else
			f[i].open(s, ios::out);
	}
    
    while(f[0].peek()!=-1)
    {
    	f[3] << '|';
    	for(int i = 0; i < 3; ++i)
    	{
			int x;
			f[i].read((char *)&x, sizeof(x));
			char str[3];
			itoa(x,str,10);
			Show(str);
			f[3].setf(ios::left);
			f[3].width(20);
			f[3] << str;
			
//			f[3].write((char *)&x, sizeof(x));
		}
//		f[3].width(20);
		f[3] << '|';
		f[3] << endl;
	}
    
	for (int i = 0; i < 4; ++i)
 		f[i].close();
	delete[] f;
}
