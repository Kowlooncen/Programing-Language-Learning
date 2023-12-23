#include "pt4.h"
#include <string> 
using namespace std;

class TextView
{
    // НЕ ИЗМЕНЯЙТЕ РЕАЛИЗАЦИЮ ДАННОГО КЛАССА
    int x = 0, y = 0;
    int width = 1, height = 1;
public:
    void GetOrigin(int& x, int& y);
    void SetOrigin(int x, int y);
    void GetSize(int& width, int& height);
    void SetSize(int width, int height);
};

void TextView::GetOrigin(int& x, int& y)
{
    x = this->x;
    y = this->y;
}
void TextView::SetOrigin(int x, int y)
{
    this->x = x;
    this->y = y;
}
void TextView::GetSize(int& width, int& height)
{
    width = this->width;
    height = this->height;
}
void TextView::SetSize(int width, int height)
{
    this->width = width;
    this->height = height;
}

class Shape
{
public:
    virtual string GetInfo() = 0;
    virtual void MoveBy(int a, int b) = 0;
};

class TextShape: public Shape
{
	char tview;
	string str;
	int x1, x2, y1, y2;
public:
	TextShape(char tview, int x1, int y1, int x2, int y2)//矩形左上角和右下角 
	{
		this -> x1 = x1;
		this -> y1 = y1;
		this -> x2 = x2;
		this -> y2 = y2;
	}
    string GetInfo(){
    	str = str + "T"+"("+to_string(x1) + "," + to_string(y1) + ")" + "(" + to_string(x2) + "," + to_string(y2) + ")" + '\0'; 
		return str;
	}
    void MoveBy(int a, int b){
    	x1 = x1 + a;
    	y1 = y1 + b;
    	x2 = x2 + a;
    	y2 = y2 + b;
	}
};

// РЕАЛИЗУЙТЕ КЛАССЫ-ПОТОМКИ RectShape И TextShape

class RectShape: public Shape{
private:
	string str;
	int x1, x2, y1, y2;
public:	
	RectShape(int x1, int y1, int x2, int y2)//矩形左上角和右下角 
	{
		this -> x1 = x1;
		this -> y1 = y1;
		this -> x2 = x2;
		this -> y2 = y2;
	}
	string GetInfo()
	{
		str = str + "R"+"("+to_string(x1) + "," + to_string(y1) + ")" + "(" + to_string(x2) + "," + to_string(y2) + ")" + '\0'; 
		return str.c_str();
	}
    void MoveBy(int a, int b)
    {
    	x1 = x1 + a;
    	y1 = y1 + b;
    	x2 = x2 + a;
    	y2 = y2 + b;
	}
};

void Solve()
{
    Task("OOP2Struc3");
	int N;
	char c;
	int x1 ,x2, y1, y2, A, B;
	pt >> N;
	Shape *arr[N];
	for(int i = 0; i < N; i++)
	{
		pt >> c;
		pt >> x1;
		pt >> y1;
		pt >> x2;
		pt >> y2;
		if(c == 'T')
			arr[i] = new TextShape('T', x1, y1, x2, y2);
		else 
			arr[i] = new RectShape(x1, y1, x2, y2);
	}
	
	pt >> A >> B;
	for(int i = 0; i < N; i++)
	{
		arr[i]->MoveBy(A,B);
		Show((arr[i])->GetInfo());
		pt << arr[i]->GetInfo();
	}
	
}
