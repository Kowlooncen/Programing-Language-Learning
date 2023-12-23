#include "pt4.h"
#include <typeinfo>

using namespace std;

class Colleague;

class Mediator
{
public:
    virtual void NotifyFrom(Colleague* coll) = 0;//为了使用coll中的m 
};

class Colleague
{
    Mediator* m;
public:
    void SetMediator(Mediator* m);
    void Notify();
};

void Colleague::SetMediator(Mediator* m)
{
    this->m = m;
}
void Colleague::Notify()
{
    m->NotifyFrom(this);
}

class ConcreteColleague1: public Colleague
{
public:
	ConcreteColleague1(){
		data = 1;
	}
	int GetData(){
		return data;
	}
	void SetData(int d)
	{
		data = d;
	}
private:
	 int data;
};

class ConcreteColleague2: public Colleague
{
public:
	ConcreteColleague2(){
		data = "ab";
	}
	string GetData(){
		return data;
	}
	void SetData(string d)
	{
		data = d;
	}
private:
	string data;
};

class ConcreteMediatorA: public Mediator
{
public:
	ConcreteMediatorA(){
		c1 = new ConcreteColleague1;
        c2 = new ConcreteColleague2;
		c1 -> SetMediator(this); 
		c2 -> SetMediator(this); 
	}
	
	Colleague* GetC1(){
		return c1;
	} 
	Colleague* GetC2(){
		return c2;
	} 
	
	void NotifyFrom(Colleague* coll){
		if(coll == c1){
			string str = " " + to_string(c1->GetData());
			c2->SetData(c2->GetData()+str);
		}
		if(coll == c2)
		{
			c1->SetData(c1->GetData()+c2->GetData().size());
			//c1 对象的数字数据字段会增加 c2 对象的数据字符串字段的当前长度
		}
		Show(c1->GetData());
		Show(c2->GetData());
		pt << c1->GetData() << c2->GetData();
	}
private:
	ConcreteColleague1* c1;
	ConcreteColleague2* c2;
};

int count(char c, string s) 
{
    int cnt = 0;
    for (auto e : s) {
        if (e == c)
            cnt++;
    }
    return cnt;
}

class ConcreteMediatorB: public Mediator
{
public:
	ConcreteMediatorB(){
		c1a = new ConcreteColleague1;
        c1b = new ConcreteColleague1;
        c2 = new ConcreteColleague2;
        c1a->SetMediator(this);
        c1b->SetMediator(this);
        c2->SetMediator(this);
	}
	
	Colleague* GetC1a(){
		return c1a;
	} 
	Colleague* GetC1b(){
		return c1b;
	} 
	Colleague* GetC2(){
		return c2;
	} 
	
	void NotifyFrom(Colleague* coll){
		if(coll == c1a) {
			c1b->SetData(c1b->GetData()+c1a->GetData());
			c2->SetData(c2->GetData()+"a");
		}
		if(coll == c1b) {
			c1a->SetData(c1b->GetData()+c1a->GetData());
			c2->SetData(c2->GetData()+"b");
		}
		if(coll == c2){
			c1a->SetData(count('a', c2->GetData()));
			c1b->SetData(count('b', c2->GetData()));
		}
		Show(c1a->GetData());
		Show(c1b->GetData());
		Show(c2->GetData());
		pt << c1a->GetData() << c1b->GetData() << c2->GetData();
	}
private:
	ConcreteColleague1* c1a;
	ConcreteColleague1* c1b;
	ConcreteColleague2* c2;
};

void Solve()
{
    Task("OOP3Behav12");
	ConcreteMediatorA* ma = new ConcreteMediatorA;
    ConcreteMediatorB* mb = new ConcreteMediatorB;
    
    vector<Colleague*> coll;
    coll.push_back(ma->GetC1());
    coll.push_back(ma->GetC2());
    coll.push_back(mb->GetC1a());
    coll.push_back(mb->GetC1b());
    coll.push_back(mb->GetC2());
    int N; 
	pt >> N;
	
    for (int i = 0; i < N; ++i) {
        int n; 
		pt >> n;
        coll[n]->Notify();
    }
}
