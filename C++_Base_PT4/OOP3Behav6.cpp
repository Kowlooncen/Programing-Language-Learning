#include "pt4.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class AbstractComparable
{
public:
    virtual int CompareTo(AbstractComparable* other) = 0;
    static int IndexMax(AbstractComparable** comp, int N);
    static int LastIndexMax(AbstractComparable** comp, int N);
    static int IndexMin(AbstractComparable** comp, int N);
    static int LastIndexMin(AbstractComparable** comp, int N);
    // РЕАЛИЗУЙТЕ СТАТИЧЕСКИЕ МЕТОДЫ IndexMax,
    //   LastIndexMax, IndexMin И LastIndexMin
};

int AbstractComparable::IndexMax(AbstractComparable** comp, int N){

	int max = 0;
	
	for(int i = 0; i < N; i++)
	{
		if((comp[max]->CompareTo(comp[i])) < 0) max = i;
	}
	return max;
}

int AbstractComparable::LastIndexMax(AbstractComparable** comp, int N) {
	int max = 0;
	
	for(int i = 0; i < N; i++)
	{
		if((comp[max]->CompareTo(comp[i])) < 0) max = i;
		if((comp[max]->CompareTo(comp[i])) == 0) max = i;
	}
	return max;
}

int AbstractComparable::IndexMin(AbstractComparable** comp, int N) {
	int min = 0;
	
	for(int i = 0; i < N; i++)
	{
		if((comp[min]->CompareTo(comp[i])) > 0) min = i;
	}
	return min;
}

int AbstractComparable::LastIndexMin(AbstractComparable** comp, int N) {
	int min = 0;
	
	for(int i = 0; i < N; i++)
	{
		if((comp[min]->CompareTo(comp[i])) > 0) min = i;
		if((comp[min]->CompareTo(comp[i])) == 0) min = i;
	}
	return min;
}

bool isDegital(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str.at(i) == '-' && str.size() > 1)  // 有可能出现负数
            continue;
        if (str.at(i) > '9' || str.at(i) < '0')
            return false;
    }
    return true;
}

class NumberComparable : public AbstractComparable 
{
public:
    NumberComparable(string data) {
        if (isDegital(data))
            key = atoi(data.c_str());
        else key = 0;
    }
    int CompareTo(AbstractComparable* other) {
        NumberComparable* pother = dynamic_cast<NumberComparable*>(other);
        if (this->key < pother->key) return -1;
        if (this->key == pother->key) return 0;
        if (this->key > pother->key) return 1;
    }
private:
    int key;
};

class LengthComparable : public AbstractComparable 
{
public:
    LengthComparable(string data) {
        key = data.length();
    }
    int CompareTo(AbstractComparable* other) {
        LengthComparable* pother = dynamic_cast<LengthComparable*>(other);
        if (this->key < pother->key) return -1;
        if (this->key == pother->key) return 0;
        if (this->key > pother->key) return 1;
    }
private:
    int key;
};

class TextComparable : public AbstractComparable 
{
public:
    TextComparable(string data) {
        key = data;
    }
    int CompareTo(AbstractComparable* other) {
        TextComparable* pother = dynamic_cast<TextComparable*>(other);
        if (this->key < pother->key) return -1;
        if (this->key == pother->key) return 0;
        if (this->key > pother->key) return 1;
    }
private:
    string key;
};

void Solve()
{
    Task("OOP3Behav6");
    int N, K;//N是每一行元素个数，K是有多少行
    pt >> N >> K;
    string str1, str2;
   
    for (int i = 0; i < K; i++)
    {
    	AbstractComparable* comp[9];//需要包含N个元素，用来处理每一行
        pt >> str1;
        for (int j = 0; j < N ; j++)
        {
            pt >> str2;
            if (str1 == "N")
            {
                comp[j] = new NumberComparable(str2);
            }
            if (str1 == "L")
            {
                comp[j] = new LengthComparable(str2);
            }
            if (str1 == "T")
            {
                comp[j] = new TextComparable(str2);
            }
        }
        int x = AbstractComparable::IndexMax(comp, N);
        int y = AbstractComparable::LastIndexMax(comp, N);
        int m = AbstractComparable::IndexMin(comp, N);
        int n = AbstractComparable::LastIndexMin(comp, N);
        //int x = AbstractComparable::IndexMax(comp);
        Show(x);Show(y);Show(m);Show(n);Show('\n');
        pt << x << y << m << n;
    }
}
