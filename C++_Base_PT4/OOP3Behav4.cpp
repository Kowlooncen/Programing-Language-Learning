#include "pt4.h"
#include <vector>
#include <algorithm>

using namespace std;

class Validator
{
public:
    virtual string Validate(string s);
};

string Validator::Validate(string s)
{
	return "";
}

// §²§¦§¡§­§ª§©§µ§«§´§¦ §¬§­§¡§³§³§½-§±§°§´§°§®§¬§ª EmptyValidator,
//   NumberValidator §ª RangeValidator

class EmptyValidator: public Validator
{
public:
	EmptyValidator() {}
	string Validate(string s)
	{
		if (s.empty()) return "!Empty text";
		return "";
	}
};

class NumberValidator: public Validator
{
public:
	NumberValidator() {}
	string Validate(string s)
	{
		string str;
		if(s != "")
		{
			string::iterator p1 = find_if(s.begin(), s.end(), [](char c) { return (c != '-') && ((c < '0') || (c > '9')); });
			if (p1 == s.end()) str = "";
			else str = "!'" + s + "': not a number";
		}
		else str = "!'" + s + "': not a number";
		return str;
	}
};

class RangeValidator: public Validator
{
public:
	RangeValidator() {}
	RangeValidator(int a, int b)
	{
		this->my_min = min(a, b);
		this->my_max = max(a, b);
	}
	string Validate(string s)
	{
		string str;
		string::iterator p1 = find_if(s.begin(), s.end(), [](char c) { return (c != '-') && ((c < '0') || (c > '9')); });
		if (p1 == s.end()) 
		{
			int x = atoi(s.c_str());
			if ((x >= my_min) && (x <= my_max)) 
				str = "";
			else 
				str = "!'" + s + "': not in range " + to_string(my_min) + ".." + to_string(my_max);
		}
		else 
			str = "!'" + s + "': not in range " + to_string(my_min) + ".." + to_string(my_max);
		return str;
	}
private:
	int my_min, my_max;
};

// §²§¦§¡§­§ª§©§µ§«§´§¦ §¬§­§¡§³§³§½ TextBox §ª TextForm

class TextBox
{
public:
	TextBox() {}
	~TextBox()
	{
		delete v;
		v = NULL;
	}
	void SetText(string text)
	{
		this->text = text;
	}
	void SetValidator(Validator *v)
	{
		this->v = v;
	}
	string Validate()
	{
		return v->Validate(text);
	}
private:
	string text = "";
	Validator *v = new Validator();
};

class TextForm
{	
public:
	TextForm(int n)
	{
		for (int i = 0; i < n; i++) {
			TextBox* tb = new TextBox();
			V.push_back(tb);
		}
	}

	void SetText(int ind,string text)
	{
		V[ind]->SetText(text);
	}

	void SetValidator (int ind,Validator * v)
	{
		V[ind]->SetValidator(v);
	}

	string Validate()
	{
		for(auto i : V)
		{
			info = info + i->Validate();
		}
		return info;
	}
private:
	vector<TextBox*> V;
	string info = "";
};

void Solve()
{
    Task("OOP3Behav4");
	int N, A, B, K;
	pt >> N >> A >> B;
	pt >> K;

	vector<pair<int, char>> V;
	for (int i = 0; i < K; i++) {
		int ind;
		char val;
		pt >> ind >> val;
		V.emplace_back(make_pair(ind, val));
	}
	
	for (int i = 0; i < 5; i++) 
	{
		TextForm* tf = new TextForm(N);
		for (int j = 0; j < N; j++) {
			string s;
			pt >> s;
			tf->SetText(j, s);
		}
		Validator* v = NULL;
		for (auto e : V) {
			if (e.second == 'E') v = new EmptyValidator();
			if (e.second == 'N') v = new NumberValidator();
			if (e.second == 'R') v = new RangeValidator(A, B);
			tf->SetValidator(e.first, v);
		}
		ShowLine(tf->Validate());
		string str = tf->Validate();
		string info;
		for(int i = 0; i < str.size()/2; i++)
		{
			info = info + str[i];
		}
	//	pt << str; 
	ShowLine(info); 
	ShowLine(info.size()); 
	pt << info;
	}
}
