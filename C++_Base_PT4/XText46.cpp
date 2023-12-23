#include "pt4.h"
#include <fstream>
#include <iomanip> 

using namespace std;

void Solve()
{
    Task("XText46");
    
    string name1, name2;
    
    pt >> name1 >> name2;
    
    fstream f1, f2;
    
    f1.open(name1);
    
    f2.open(name2, ios::out | ios::binary);
    
    while(f1.peek()!=-1)
    {
    	string s;
    	f1 >> s;
    	
    	if(s.find(".")!=s.npos && s.find(".00")==s.npos)
    	{
    		char ch[8];
    		strcpy(ch, s.c_str());
    	//	double db = atof(ch);   
    	//	Show(db);
    		double x = atof(ch);
    		f2.write((char *)&x, sizeof(x));
		}
	}
	f1.close();
	f2.close();

}

