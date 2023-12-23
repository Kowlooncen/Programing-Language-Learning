#include "pt4.h"

using namespace std;

class State
{
public:
    virtual string GetNextToken() = 0;
};

class Context//操控器，管理状态的改变 
{
private:
	State* currentState;
	string text;
public:
	Context(string str)
	{
		this->text = str;
	}

	char GetCharAt(int index)
	{
		return text[index];
	}

	void SetState(State* newState)//定新状态 
	{
		this->currentState = newState;
	}

	string GetNextToken()
	{
		return currentState->GetNextToken();//查看下一个标识字符 
	}
};

class ConcreteStateNormal : public State
{
public:
	ConcreteStateNormal(Context* ct, int index)
	{
		this->ct = ct;
		this->index = index;
	}

	string GetNextToken();
	
private:
	Context* ct;//包含可解析的字段
	int index;//需要继续解析的字段的位置
};

class ConcreteStateString : public State
{
public:
	ConcreteStateString(Context* ct, int index)
	{
		this->ct = ct;
		this->index = index;
	}
	string GetNextToken();
private:
	Context* ct;
	int index;
};

class ConcreteStateComm : public State
{
public:
	ConcreteStateComm(Context* ct, int index)
	{
		this->ct = ct;
		this->index = index;
	}
	string GetNextToken();
private:
	Context* ct;
	int index;
};

class ConcreteStateFin :public State
{
public:
	ConcreteStateFin() {}
	string GetNextToken()
	{
		return "";
	}
};

string ConcreteStateNormal::GetNextToken() 
{
	string str;
	while (ct->GetCharAt(index) != '.')
	{
		int k = 0;
		switch (ct->GetCharAt(index))
		{
			case '\"': {
				k = 1;
				ct->SetState(new ConcreteStateString(this->ct, index + 1));
				break;
			}
			case '{':{
				k = 1;
				ct->SetState(new ConcreteStateComm(this->ct, index + 1));
				break;
			}
			default:
				break;
		}
		if(k == 0) str = str + ct->GetCharAt(index);
		else break;
		index++;		
	}
	if(ct->GetCharAt(index)=='.' )
		ct->SetState(new ConcreteStateFin());
	return "Normal:" + str;
}

string ConcreteStateString::GetNextToken() 
{
	string str;
	char c;
	while (ct->GetCharAt(index) != '.')
	{
		int k = 0;
		if (ct->GetCharAt(index) == '\"') 
		{
			if(ct->GetCharAt(index+1) != '\"'){
				k = 1;
				ct->SetState(new ConcreteStateNormal(ct, index + 1));
				break;
			}else index++;
		}
		if(k == 0)
			str = str + ct->GetCharAt(index);
		index++;
	}
	if (ct->GetCharAt(index) == '.') 
	{
		ct->SetState(new ConcreteStateFin());
		return "ErrString:" + str;
	}
	return "String:" + str;
}

string ConcreteStateComm::GetNextToken() 
{
	string str;
	while (ct->GetCharAt(index) != '.')
	{
		int k = 0;
		if (ct->GetCharAt(index) == '}') {
			k = 1;
			ct->SetState(new ConcreteStateNormal(ct, index + 1));
			break;
		}
		if(k == 0)
			str = str + ct->GetCharAt(index);
		index++;
	}
	if (ct->GetCharAt(index) == '.') {
			ct->SetState(new ConcreteStateFin());
			return "ErrComm:" + str;
		}
	return "Comm:" + str;
}

void Solve()
{
    Task("OOP3Behav10");

	string str;
	string s;
	pt >> str;
	//str = "3\"{eadf}21\"fas\"";
	Context* ct = new Context(str);
	ct->SetState(new ConcreteStateNormal(ct, 0));//一开始先定一个normal 
	//	Show(ct->GetNextToken());
	
	while((s = ct->GetNextToken()) != "") 
	{
	  // 	Show(ct->GetNextToken());
		ShowLine(s);
		pt << s;
	}
}
