#include "pt4.h"
using namespace std;

class Flyweight
{
public:
    virtual char Show(bool state) = 0;
};

class ConcreteFlyweight: public Flyweight
{
public:
	char Show(bool state)
	{
		if(state == true) return 'A';
		else return 'a';
	}
};

class UnsharedConcreteFlyweight: public Flyweight
{
public:
	UnsharedConcreteFlyweight(char c)
	{
		inf = c;
	 } 
	char Show(bool state){
		if(state == true) return toupper(inf);
		else return tolower(inf);
	}
	
private:
	char inf;
};

class FlyweightFactory
{
public:
	FlyweightFactory( )
	{ 
		cf = NULL;
		count = 0;
	}
 	
	Flyweight* CreateFlyweight(char inf){
		if(inf != 'A'&& inf != 'a'){
			count ++;
			return new UnsharedConcreteFlyweight(inf);
		}
		else{
			if(cf == NULL){
				cf = new ConcreteFlyweight;
				count ++;
				return cf;
			} 
			else return cf;
		}
	}
	
	int GetCount(){
		return count;
	}

private:
    ConcreteFlyweight* cf;
    int count;
};

class Client{
public:
	Client(){
		f = new FlyweightFactory;
		fw[30] = NULL;
		x = 0;
	}
	
	void MakeFlyweights (string inf)
	{
		for(int i = 0; i < inf.size(); i++)
		{
			fw[i] = f->CreateFlyweight(inf[i]);
		}
		x = inf.size();
	}
	
	string ShowFlyweights(bool state)
	{
		string str;
		for(int i = 0; i < x; i++)
		{
			str = str + fw[i] -> Show(state);
		}
		return str;
	}
	
	int GetFlyweightCount(){
		return f->GetCount();
	}
private:
	FlyweightFactory* f;
	Flyweight* fw[30];
	int x;
};

void Solve()
{
    Task("OOP2Struc11");
    string s;
    Client* cl = new Client;
    for(int i = 0; i < 5; ++i)
	{
		pt >> s;
		cl->MakeFlyweights(s);
		pt << cl->ShowFlyweights(true);
		pt << cl->ShowFlyweights(false);
		pt << cl->GetFlyweightCount();
	} 
}
