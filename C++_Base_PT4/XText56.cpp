#include "pt4.h"
#include <fstream>
using namespace std;

void Solve()
{
    Task("XText56");
	string s1, s2;
	
	pt >> s1 >> s2;
	
	fstream f1, f2;
	
	f1.open(s1, ios::in);
	
	f2.open(s2, ios::binary | ios::out);
	
	int i = 0;
	
	char ch[100];
	
	while(f1.peek() != -1)
	{
		char x;
		f1 >> x;
//		ShowLine(x);
		int k = 0;
		for(int j = 0; j < i; j ++)
		{
			if(x == ch[j])
			{
				k = 1;
				break;
			}
		}
		if(k == 0)
		{
			ch[i] = x;
//			ShowLine(ch[i]);
			i++;
		}
	}
	
	for(int m = 0; m < i; m++)
	{
		for(int n = m + 1; n < i; n++)
		{
			if(ch[m] < ch[n])
			{
				char r;
				r = ch[m];
				ch[m] = ch[n];
				ch[n] = r;
			}
		}
	}
	
	for(int k = 0; k < i; k++)
	{
		char c = ch[k];
		Show(c);
		f2.write((char *)&c, sizeof(c)); 
	}
	char c = ' ';
	Show(c);
	f2.write((char *)&c, sizeof(c)); 

	f1.close();
	f2.close();
}


