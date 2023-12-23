#include "pt4.h"
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Prototype
{
public:
    virtual Prototype* Clone() = 0;
    virtual void ChangeId(int id) = 0;
    virtual string GetInfo() = 0;
};

class ConcretePrototype1:public Prototype
{
private :
    int id;
    string s;
public:
    ConcretePrototype1(int id, string s) {
        this->id = id;
        this->s = s;
    }

    Prototype* Clone() {
        return new ConcretePrototype1(*this);
    }

    void ChangeId(int id) {
        this->id = id;
    }

    string GetInfo() {
        string res;
        stringstream ss;
        ss << id;
        ss >> res;
        string str = "CP1=" + s + "=" + res;
        return str;
    }
};

class ConcretePrototype2 :public Prototype
{
private:
    int id;
    string s;
public:
    ConcretePrototype2(int id, string s) {
        this->id = id;
        this->s = s;
    }

    Prototype* Clone() {
        return new ConcretePrototype2(*this);
    }

    void ChangeId(int id) {
        this->id = id;
    }

    string GetInfo() {
        string res;
        stringstream ss;
        ss << id;
        ss >> res;
        string str = "CP2=" + s + "=" + res;
        return str;
    }
};

void Solve()
{
    Task("OOP1Creat7");

    string s;
    int N;
    pt >> s;
    pt >> N;
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int x;
        pt >> x;
        v.push_back(x);
    }
    string str1;
    Prototype* a = new ConcretePrototype1(v[0], s);
    str1 = str1 + a->GetInfo();
    for (int i = 1; i < N; i++)
    {
        Prototype* b = a->Clone();
        b->ChangeId(v[i]);
        str1 = str1 + " ";
        str1 = str1 + b->GetInfo();
    }
    pt << str1;
    string str2;
    Prototype* aa = new ConcretePrototype2(v[0], s);
    str2 = str2 + aa->GetInfo();
    for (int i = 1; i < N; i++)
    {
        Prototype* bb = aa->Clone();
        bb->ChangeId(v[i]);
        str2 = str2 + " ";
        str2 = str2 + bb->GetInfo();
    }
    pt << str2;
}


