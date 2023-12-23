#include "pt4.h"
#include <string>
#include <algorithm>

using namespace std;

class AbstractButton
{
public:
    virtual string GetControl() = 0;
};
// §²§¦§¡§­§ª§©§µ§«§´§¦ §¬§­§¡§³§³§½-§±§°§´§°§®§¬§ª Button1 §ª Button2
class Button1 :public AbstractButton
{
    string s;
public:
    Button1(string text) {
        transform(text.begin(), text.end(), text.begin(), ::toupper);
        this->s = "[" + text + "]";
    }
    string GetControl() {
        return s;
    }
};

class Button2 :public AbstractButton
{
    string s;
public:
    Button2(string text) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        this->s = "<" + text + ">";
    }
    string GetControl() {
        return s;
    }
};

class AbstractLabel
{
public:
    virtual string GetControl() = 0;
};
// §²§¦§¡§­§ª§©§µ§«§´§¦ §¬§­§¡§³§³§½-§±§°§´§°§®§¬§ª Label1 §ª Label2
class Label1 :public AbstractLabel
{
    string s;
public:
    Label1(string text) {
        transform(text.begin(), text.end(), text.begin(), ::toupper);
        this->s = "=" + text + "=";
    }
    string GetControl() {
        return s;
    }
};

class Label2 :public AbstractLabel
{
    string s;
public:
    Label2(string text) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        this->s = "\"" + text + "\"";
    }
    string GetControl() {
        return s;
    }
};

class ControlFactory
{
public:
    virtual AbstractButton* CreateButton(string text) = 0;
    virtual AbstractLabel* CreateLabel(string text) = 0;
};
// §²§¦§¡§­§ª§©§µ§«§´§¦ §¬§­§¡§³§³§½-§±§°§´§°§®§¬§ª Factory1 §ª Factory2
class Factory1 :public ControlFactory
{
    AbstractButton* CreateButton(string text) {
        return new Button1(text);
    }
        
    AbstractLabel* CreateLabel(string text){
        return new Label1(text);
    }
};

class Factory2 :public ControlFactory
{
    AbstractButton* CreateButton(string text) {
        return new Button2(text);
    }

    AbstractLabel* CreateLabel(string text) {
        return new Label2(text);
    }
};

class Client
{
    // §¥§°§¢§¡§£§¾§´§¦ §¯§¦§°§¢§·§°§¥§ª§®§½§¦ §±§°§­§Á
    string str;
    ControlFactory* p;

public:
    Client(ControlFactory* f);
    void AddButton(string text);
    void AddLabel(string text);
    string GetControls();
};

Client::Client(ControlFactory* f)
{
    p = f;
}
void Client::AddButton(string text)
{
    // §²§¦§¡§­§ª§©§µ§«§´§¦ §®§¦§´§°§¥
    if(str=="")
        str = str + p->CreateButton(text)->GetControl();
    else str = str + " " + p->CreateButton(text)->GetControl();
}
void Client::AddLabel(string text)
{
    // §²§¦§¡§­§ª§©§µ§«§´§¦ §®§¦§´§°§¥
    if (str == "")
        str = str + p->CreateLabel(text)->GetControl();
    else str = str + " " + p->CreateLabel(text)->GetControl();
}
string Client::GetControls()
{
    return str;
}

void Solve()
{
    Task("OOP1Creat5");
    int N = 0;
    vector<string> v;
    pt >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        pt >> s;
        v.push_back(s);
    }
    Show(v.begin(), v.end());
    Client c1(new Factory1);
    for (int i = 0; i < N; i++)
    {
        if (v[i][0] == 'L') {
            c1.AddLabel(v[i].substr(2));
        }
        else {
            c1.AddButton(v[i].substr(2));
        }
    }
    ShowLine(c1.GetControls());
    pt << c1.GetControls();
    Client c2(new Factory2);
    for (int i = 0; i < N; i++)
    {
        if (v[i][0] == 'L') {
            c2.AddLabel(v[i].substr(2));
        }
        else {
            c2.AddButton(v[i].substr(2));
        }
    }
    ShowLine(c2.GetControls());
    pt << c2.GetControls();
}
