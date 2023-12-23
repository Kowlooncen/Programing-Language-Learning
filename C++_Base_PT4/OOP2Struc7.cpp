#include "pt4.h"
#include <vector>

using namespace std;

class Component
{
public:
    virtual string Show() = 0;
};

// §²§¦§¡§­§ª§©§µ§«§´§¦ §¬§­§¡§³§³-§±§°§´§°§®§°§¬ ConcreteComponent
class ConcreteComponent: public  Component
{
public:
	ConcreteComponent(string s)
	{
		text = s;	
	}
	string Show(){
		return text;
	}	
private:
	string text;
};

class Decorator : public Component
{
protected:
    Component* comp;
};

class ConcreteDecoratorA : public Decorator
{
public:
	ConcreteDecoratorA(Component *comp)
	{
		this -> comp = comp;
	}
	string Show(){
		return "="+comp->Show()+"=";
	}
};

class ConcreteDecoratorB : public Decorator
{
public:
	ConcreteDecoratorB(Component *comp)
	{
		this -> comp = comp;
	}
	string Show(){
		return "("+comp->Show()+")";
	}
};

void Solve()
{
    Task("OOP2Struc7");
	int N;
	pt >> N;
	Component *arr[N];
	vector<string> v;
	for(int i = 0; i < N; ++i)
	{
		string S, D;
		pt >> S >> D;
		arr[i] = new ConcreteComponent(S);
		for(int j = 0; j < D.size(); j++)
		{
			if(D[j] == 'A')
			{
				ConcreteDecoratorA a = new ConcreteDecoratorA(arr[i]);	
				arr[i] = new ConcreteComponent(a.Show());
			}
			else{
				ConcreteDecoratorB b(arr[i]);				
				arr[i] = new ConcreteComponent(b.Show());
			}
		}
	}
	for(int i = N - 1; i >= 0; i--)
	{
		Show(arr[i]->Show());
		pt << arr[i]->Show();
	}
}
