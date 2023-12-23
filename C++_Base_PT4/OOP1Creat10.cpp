#include "pt4.h"
using namespace std;

class Builder
{
public:
    virtual void BuildStart(char c) {}
    virtual void BuildFirstChar(char c) {}
    virtual void BuildNextChar(char c) {}
    virtual void BuildFirstSpace() {}
    virtual string GetResult() = 0;
};

class BuilderPascal :public Builder
{
public:
    void BuildStart(char c) {
		product.append(1, tolower(c));
	}
    void BuildFirstChar(char c) {
		product.append(1, toupper(c));
	}
    void BuildNextChar(char c) {
		product.append(1, tolower(c));
	}
    void BuildFirstSpace() {}
    string GetResult(){
		return product;
	}
public:
	string product;
};

class BuilderPyhton :public Builder
{
public:
    void BuildStart(char c) {
		product.append(1, tolower(c));
	}
    void BuildFirstChar(char c) {
		product.append(1, tolower(c));
	}
    void BuildNextChar(char c) {
		product.append(1, tolower(c));
	}
    void BuildFirstSpace() {
		product.append(1, '_') ; 
	}
    string GetResult(){
		return product;
	}
private:
	string product;
};

class BuilderC :public Builder
{
public:
    void BuildStart(char c) {
		product.append(1, tolower(c));
	}
    void BuildFirstChar(char c) {
		product.append(1, tolower(c));
	}
    void BuildNextChar(char c) {
		product.append(1, tolower(c));
	}
    void BuildFirstSpace() {}
    string GetResult(){
		return product;
	}
private:
	string product;
};

class Director
{
    Builder* b;
public:
    Director(Builder* b);
    string GetResult();
    void Construct(string templat);
};

Director::Director(Builder* b)
{
    this->b = b;
}
string Director::GetResult()
{
    return b->GetResult();
}
void Director::Construct(string templat)
{
    b->BuildStart(templat[0]);
	for(int i = 1; i < templat.size(); i++)
	{
		if(templat[i]==' '&&templat[i-1]==' ')
		{
			continue;
		}
		else if(templat[i]==' '&&templat[i-1]!=' ')
		{
			b->BuildFirstSpace();
		}
		else if(templat[i]!=' '&&templat[i-1]==' ')
		{
			b->BuildFirstChar(templat[i]);
		}
		else{
			b->BuildNextChar(templat[i]);
		}
	}
    
    // §©§¡§£§¦§²§º§ª§´§¦ §²§¦§¡§­§ª§©§¡§¸§ª§À §®§¦§´§°§¥§¡
}

void Solve()
{
    Task("OOP1Creat10");
   
    string str[5];
    for (int i = 0; i < 5; i++)
    {
        pt >> str[i];
    }

    for (int i = 0; i < 5; i++)
    {
    	Builder* a = new  BuilderPascal;
    	Builder* b = new  BuilderPyhton;
   		Builder* c = new  BuilderC;
   		Director d1(a), d2(b), d3(c);
        
		d1.Construct(str[i]);
        d2.Construct(str[i]);
        d3.Construct(str[i]);
        pt << d1.GetResult() << d2.GetResult() << d3.GetResult() ;
 		ShowLine(d1.GetResult());
 		ShowLine(d2.GetResult());
 		ShowLine(d3.GetResult());
    }

    
}
