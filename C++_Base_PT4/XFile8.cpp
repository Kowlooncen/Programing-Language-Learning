#include "pt4.h"
#include<fstream>  
#include<string>
  
using namespace std;

void Solve()
{
    Task("XFile8");
    
	string f1, f2;
	
	pt >> f1 >> f2;
	
	ifstream infile(f1, ios::binary);
	
	ofstream outfile(f2, ios::binary); 
	
	double x;
	
	infile.seekg(0, ios::end);
	
	double len = infile.tellg();
	
	double size = sizeof(x);
	
	double k = len/size;
	
	infile.seekg(0, ios::beg);

	infile.read((char *)&x, size);
	outfile.write((char *)&x, size);
	
	infile.clear();
	infile.seekg((k-1) * size);
	
	infile.read((char *)&x, size);
	outfile.write((char *)&x, size);

	outfile.close();
	 
    infile.close();

}
