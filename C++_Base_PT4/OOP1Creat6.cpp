#include "pt4.h"
#include <vector>
using namespace std;

typedef ptin_iterator<pair<int, int>> ptin;
/*
�� C++ ��ʵ�� Singleton �ࣨ�����Ƶ��ࣩʱ, ������Ҫ����˽�й��캯����
Ҳ��������������������䲻�����ⲿ����ɾ�������Ӧ���ڷ��ص�
Instance �����Ľ�����Ӷ��ƻ���̬uniqueInstance ���󣩡����⣬����һ����յ�
��������ʹ���޷����ƶ�����˴���������һ��ʵ������
*/

class BaseClass
{
    int data = 0;
public:
    void IncData(int increment);
    int GetData();
};

void BaseClass::IncData(int increment)//
{
    data += increment;
}
int BaseClass::GetData()
{
    return data;
}

class Singleton : public BaseClass
{
    static Singleton* uniqueInstance;
    Singleton() {}
    ~Singleton() {}
public:
    static Singleton* Instance() {
        if (uniqueInstance == NULL)
            uniqueInstance = new Singleton;
        return uniqueInstance;
    }// ������������������ �������������������� ������������ Singleton
    static int InstanceCount() {
        if (uniqueInstance == NULL)
            return 0;
        else return 1;
    }
};

Singleton* Singleton::uniqueInstance = nullptr;

class Doubleton : public BaseClass
{
    static Doubleton* instances[];
    Doubleton() {}
    ~Doubleton() {}
public:
    static Doubleton* Instance1() {
        if (instances[0] == NULL)
            instances[0] = new Doubleton;
        return instances[0];
    }
    static Doubleton* Instance2() {
        if (instances[1] == NULL)
            instances[1] = new Doubleton;
        return instances[1];
    }
    static int InstanceCount() {
        int count = 0;
        for (int i = 0; i < 2; ++i)
        {
            if (instances[i] != NULL)
                count++;
        }
        return count;
    }
    // ������������������ �������������������� ������������ Doubleton
};

Doubleton* Doubleton::instances[2];

class Tenton : public BaseClass
{
    static Tenton* instances[];
    Tenton() {}
    ~Tenton() {}
public:
    static Tenton* Instance(int x) {
        if (x < 0 || x > 9)
            return NULL;
        else {
            if (instances[x] == NULL)
                instances[x] = new Tenton;
            return instances[x];
        }
    }
    static int InstanceCount() {
        int count = 0;
        for (int i = 0; i < 10; ++i)
        {
            if (instances[i] != NULL)
                count++;
        }
        return count;
    }
    // ������������������ �������������������� ������������ Tenton
};

Tenton* Tenton::instances[10];

void test() {
    pt << Singleton::InstanceCount() << Doubleton::InstanceCount() << Tenton::InstanceCount();
}

void Solve()
{
    Task("OOP1Creat6");

    int N;
    
    pt >> N;

    string str[10];

    vector<string> v1;

    for (int i = 0; i < N; i++)
    {
        pt >> str[i];
        v1.push_back(str[i]);
    }

    int K;

    pt >> K;

    vector<pair<int, int>> v2;

    for (int i = 0; i < K; i++)
    {
        int x, y;
        pt >> x;
        pt >> y;
        v2.push_back(make_pair(x, y));
    }

    ShowLine(v1.begin(), v1.end());
    ShowLine(v2.begin(), v2.end());
   
    BaseClass** b = new BaseClass*[N];

    for (int i = 0; i < N; i++)
    {
        switch (v1[i][0])
        {
        case 'S':
        {
            b[i] = Singleton::Instance();
            break;
        }
        case 'D':
        {
            if (v1[i][1] == '1')
                b[i] = Doubleton::Instance1();
            else b[i] = Doubleton::Instance2();
            break;
        }
        case 'T':
        {
            b[i] = Tenton::Instance(v1[i][1] - '0');
            break;
        }
        default:
            break;
        }
    }
    test();
    for (int i = 0; i < K; i++)
    {
        (*b[v2[i].first]).IncData(v2[i].second);
    }
    for (int i = 0; i < N; i++)
    {
        pt << (*b[i]).GetData();
    }
}

