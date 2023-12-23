#include "pt4.h"
#include <algorithm>
#include <list>

using namespace std;

class Observer;

class Subject
{
public:
    virtual void Attach(Observer* observ) = 0;
    virtual void Detach(Observer* observ) = 0;
    virtual void SetInfo(string info) = 0;
};

class Observer
{
public:
    virtual void OnInfo(Subject* sender, string info) = 0;
};

class ConcreteSubject: public Subject
{
public:
	void Attach(Observer* pObserver) 
	{
		m_ListObserver.push_back(pObserver);
	}         

	void Detach(Observer* pObserver) 
	{
		list<Observer*>::iterator iter;
		iter = find(m_ListObserver.begin(), m_ListObserver.end(), pObserver);
		if (iter != m_ListObserver.end()) 
		{
			m_ListObserver.erase(iter);
		}
	}         

	void SetInfo(string info) 
	{
		list<Observer*>::iterator iter = m_ListObserver.begin();
		for (; iter != m_ListObserver.end();)
		{
			list<Observer*>::iterator l = iter;
			l++;
			(*iter)->OnInfo(this, info);
			iter = l;
		}	
	}    

private:
	list<Observer*>    m_ListObserver;
};

class ConcreteObserver : public Observer
{
public:	
	ConcreteObserver(char detachInfo){
		this->detachInfo = detachInfo;
		this->log = "";
	}

	void OnInfo(Subject* sender, string info)
	{
		this->log = this->log + info;

		int n = log.length() - 1;
		if(log[n] == detachInfo)
		{
			sender->Detach(this);
		}
	}
	
	void Attach(Subject* pSubject) 
	{
		pSubject->Attach(this);
	}         

	void Detach(Subject* pSubject) 
	{
		pSubject->Detach(this);
	}   
	
	string GetLog()
	{
		return log;	
	}	
	
private:
	string log;
	char detachInfo;
};

void Solve()
{
    Task("OOP3Behav2");
	int N;
	int K;
	pt >> N >> K;
	string str;

	ConcreteSubject* subj1 = new ConcreteSubject;
	ConcreteSubject* subj2 = new ConcreteSubject;	
	
	ConcreteObserver* obser[10];
	for (int i = 0; i < N; i++) {
		obser[i] = new ConcreteObserver('a' + i);
		obser[i]->Attach(subj1);
		obser[i]->Attach(subj2);
	}

	for (int i = 0; i < K; i++)
	{
		pt >> str;
		if(str[0]=='1')
			subj1->SetInfo(str);
		if(str[0]=='2') 
			subj2->SetInfo(str);
	}

	for (int i = 0; i < N; i++)
	{
		ShowLine(obser[i]->GetLog()) ;
		pt << obser[i]->GetLog();
	}
}
