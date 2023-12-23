#include "pt4.h"
#include <fstream>

using namespace std;

void Solve()
{
    Task("XText11");
    
    string name, line;
    
    pt >> name;
    
    ifstream f1(name);
	
	ofstream f2("tmp.txt") ;
	
	while(f1.peek()!=-1)
	{
		getline(f1,line);
		f2 << line << endl;
		if(line.empty())
		{
			f2 << endl;		
		}
	}
	
	f1.close();
	f2.close();
	remove(name.c_str());
	rename("tmp.txt", name.c_str());

}
