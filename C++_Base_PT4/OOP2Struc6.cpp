#include "pt4.h"
#include <typeinfo>
#include <list> 
using namespace std;

class Device
{
public:
    virtual void Add(Device* d) {}
    virtual string GetName() = 0;
    virtual int GetTotalPrice() = 0;
};

class SimpleDevice: public Device
{
public:
	SimpleDevice(string s, int x)
	{
		str = s;
		price = x;
	}
	void Add(Device* d){}
	string GetName(){
		return str;
	}
	int GetTotalPrice(){
		return price;
	}
private: 
	string str;
	int price;
};

class CompoundDevice: public Device
{
public:
	CompoundDevice(string s, int x)
	{
		str = s;
		price = x;
	}
	void Add(Device* d){
	//	if(typeid(* d).name() == "SimpleDevice");
	//		price = price + d->GetTotalPrice();
			ls.push_back(d);
	}

	string GetName(){
		return str;
	}
	int GetTotalPrice(){
		int sum = price;
		for(auto i : ls)
		{
			sum = sum + i->GetTotalPrice();
		}
		return sum;
	}
private: 
	string str;
	int price;
//	Device* s[15];
	list<Device*> ls;
};

void Solve()
{
    Task("OOP2Struc6");
	int N;
	pt >> N;
	int price;
	string name;
	Device* d[15];
	for(int i = 0; i < N; i++)
	{
		pt >> name >> price;
		if(name[0]>='A'&&name[0]<='Z')
		{
			d[i] = new CompoundDevice(name, price);
		}
		else{
			d[i] = new SimpleDevice(name, price);
		}
	}
	int x[15];
	for(int i = 0; i < N; i++)
	{
		pt >> x[i];			
		if(x[i] != -1 )
			d[x[i]]->Add(d[i]);
	}
//	
//	for(int i = 0; i < N; i++)
//	{
//		for(int j = 0; j < N; j++)
//		{
//			if(i == x[j]) 
//				d[i]->Add(d[x[j]]);
//		}
//	}
	
	for(int i = 0; i < N; i++)
	{
		Show(d[i]->GetName()) ;
		Show(d[i]->GetTotalPrice()) ;
		pt << d[i]->GetName() << d[i]->GetTotalPrice();
	}
}




