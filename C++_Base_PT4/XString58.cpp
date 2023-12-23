#include "pt4.h"
using namespace std;

void Solve()
{
    Task("XString58");
    
    string path; 
    
    pt >> path;
	
	int l = path.length();
  
  	int i;
  
    int k = l - 1;
    
  	for(i = l - 1; i >=0; i--)
	{
		if(path[i] == '.') k = i;
   		if(path[i] == '\\') break;
    }
    
    pt << path.substr(i+1, k-i-1);

}
