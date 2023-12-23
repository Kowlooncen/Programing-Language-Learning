#include "pt4.h"
#include <fstream>
using namespace std;

void Solve()
{
    Task("XFile52");
    
    string s0;
    
    pt >> s0;
    
    fstream g;
	g.open(s0, ios::binary | ios::out);
    
    int N;
    
    pt >> N;
	
	fstream *f = new fstream[N];
	
	for (int i = 0; i < N; ++i)
	{
		string s;
 		pt >> s;

 		f[i].open(s, ios::binary | ios::in);
	}
	
	g.write((char *)&N, sizeof(N));
	
	for(int i = 0; i < N; ++i)
	{
		f[i].seekg(0, ios::end);
		int len = f[i].tellg();
		int k = len/sizeof(int);
		g.write((char *)&k, sizeof(k));
		f[i].seekg(0, ios::beg);
	}

	for (int i = 0; i < N; ++i)
	{
		while (f[i].peek() != -1)
 		{
 			int x;
 			f[i].read((char *)&x, sizeof(x));
 			g.write((char *)&x, sizeof(x));
		}
 	}

	g.close();
	for (int i = 0; i < N; ++i)
 		f[i].close();
	delete[] f;
}
