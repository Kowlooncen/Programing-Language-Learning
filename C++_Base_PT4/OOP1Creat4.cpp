#include "pt4.h"
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

class AbstractProductA
{
public:
	virtual void A() = 0;
	virtual string GetInfo() = 0;
};

// Implement the ProductA1 and ProductA2 descendant classes
class ProductA1 :public AbstractProductA
{
	string info;
	int n;
public:
	ProductA1(string info)
	{
		this->n = atoi(info.c_str());
	}
	void A()
	{
		n = n * 2;
		this->info = to_string(n);
	}
	string GetInfo()
	{
		return info;
	}
};

class ProductA2 :public AbstractProductA
{
	string info;
public:
	ProductA2(string info)
	{
		this->info = info;
	}
	void A()
	{
		info = info + info;
	}
	string GetInfo()
	{
		return info;
	}
};

class AbstractProductB
{
public:
	virtual void B(AbstractProductA* objA) = 0;
	virtual string GetInfo() = 0;
};

// Implement the ProductB1 and ProductB2 descendant classes
class ProductB1 :public AbstractProductB
{
	string info;
	int n;
public:
	ProductB1(string info)
	{
		this->n = atoi(info.c_str());
	}
	void B(AbstractProductA* objA)
	{
		string s = objA->GetInfo();
		n = n + atoi(s.c_str());
	}
	string GetInfo()
	{
		this->info = to_string(n);
		return info;
	}
};

class ProductB2 :public AbstractProductB
{
	string info;
public:
	ProductB2(string info)
	{
		this->info = info;
	}
	void B(AbstractProductA* objA)
	{
		string s = objA->GetInfo();
		info = info + s;
	}
	string GetInfo()
	{
		return info;
	}
};

class AbstractFactory
{
public:
	virtual AbstractProductA* CreateProductA(int info) = 0;
	virtual AbstractProductB* CreateProductB(int info) = 0;
};

// Implement the ConcreteFactory1
//   and ConcreteFactory2 descendant classes

class ConcreteFactory1 :public AbstractFactory
{
public:
	ConcreteFactory1() {
	}
	~ConcreteFactory1() {
	}
	AbstractProductA* CreateProductA(int info)
	{
		string s = to_string(info);
		AbstractProductA* product = new ProductA1(s);
		return product;
	}
	AbstractProductB* CreateProductB(int info)
	{
		string s = to_string(info);
		AbstractProductB* product = new ProductB1(s);
		return product;
	}
};

class ConcreteFactory2 :public AbstractFactory
{
public:
	ConcreteFactory2() {
	}
	~ConcreteFactory2() {
	}
	AbstractProductA* CreateProductA(int info)
	{
		string s = to_string(info);
		AbstractProductA* product = new ProductA2(s);
		return product;
	}
	AbstractProductB* CreateProductB(int info)
	{
		string s = to_string(info);
		AbstractProductB* product = new ProductB2(s);
		return product;
	}
};

void Solve()
{
	Task("OOP1Creat4");
	int Na, Nb, Nf;
	string s;
	pt >> Nf >> Na >> Nb >> s;
	AbstractFactory* f = NULL;
	if (Nf == 1) f = new ConcreteFactory1();
	if (Nf == 2) f = new ConcreteFactory2();
	AbstractProductA* pa = f->CreateProductA(Na);
	AbstractProductB* pb = f->CreateProductB(Nb);
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'A') {
			pa->A();
		}
		if (s[i] == 'B') {
			pb->B(pa);
		}
	}
	string s1, s2;
	s1 = pa->GetInfo();
	s2 = pb->GetInfo();
	Show(s1);
	Show(s2);
	pt << s1;
	pt << s2;
}
