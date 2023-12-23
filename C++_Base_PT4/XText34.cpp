#include "pt4.h"

#include <fstream>
#include <iomanip>

using namespace std;

void Solve()
{
    Task("XText34");
    
    string name1; 
    
    string name2 = "34tmp.txt";
    
    pt >> name1;
    
    string s;
    
    char buf[100];
    
    ifstream f1(name1);
    ofstream f2(name2);
    
    while(f1.peek() != -1)
    {
    	f1.getline(buf, 52, '\n');
    //	f2 << resetiosflags(ios::right) << buf <<endl;
    	Show(buf);
		if(buf[0]=='\0')
    	{
    		f2 << buf << endl;
    		continue;
		}
		f2 << setiosflags(ios::right);
		f2 << setw(50) << buf << endl;
	}
	f1.close();
	f2.close();
	
	remove(name1.c_str());
	rename(name2.c_str(),name1.c_str());
	
}
