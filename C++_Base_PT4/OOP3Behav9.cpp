#include "pt4.h"
#include <vector> 
#include <algorithm>

using namespace std;

class OperationA
{
public:
    static void ActionA();
    static void UndoActionA();
};

void OperationA::ActionA()
{
    pt << "+A";
}
void OperationA::UndoActionA()
{
    pt << "-A";
}

class OperationB
{
public:
    static void ActionB();
    static void UndoActionB();
};

void OperationB::ActionB()
{
    pt << "+B";
}
void OperationB::UndoActionB()
{
    pt << "-B";
}

class OperationC
{
public: 
    static void ActionC();
    static void UndoActionC();
};

void OperationC::ActionC()
{
    pt << "+C";
}
void OperationC::UndoActionC()
{
    pt << "-C";
}

class Command
{
public:
    virtual void Execute() = 0;
    virtual void Unexecute() = 0;
};

// §²§¦§¡§­§ª§©§µ§«§´§¦ §¬§­§¡§³§³§½-§±§°§´§°§®§¬§ª CommandA,
//   CommandB, CommandC §ª MacroCommand

class CommandA :public Command
{
public:
	CommandA() {}

	~CommandA()
	{
		delete A;
		A = NULL;
	}

	void Execute()
	{
		A->ActionA();
	}

	void Unexecute()
	{
		A->UndoActionA();
	}
	
private:
	OperationA* A = new OperationA();
};

class CommandB :public Command
{
public:
	CommandB() {}
	
	~CommandB()
	{
		delete B;
		B = NULL;
	}
	
	void Execute()
	{
		B->ActionB();
	}
	
	void Unexecute()
	{
		B->UndoActionB();
	}
	
private:
	OperationB* B = new OperationB();
};

class CommandC :public Command
{
public:
	CommandC() {}

	~CommandC()
	{
		delete C;
		C = NULL;
	}

	void Execute()
	{
		C->ActionC();
	}

	void Unexecute()
	{
		C->UndoActionC();
	}

private:
	OperationC* C = new OperationC();
};

class MacroCommand :public Command
{
public:
	MacroCommand(vector<Command*> V)
	{
		this->V = V;
	}

	void Execute()
	{
		for (auto e = V.begin(); e != V.end(); e++) 
		{
			(*e)->Execute();
		}
	}

	void Unexecute()
	{
		for (int i = V.size() - 1; i >= 0; i--) 
			V[i]->Unexecute();
	}

private:
	vector<Command*> V;
};

class Menu
{
    // §¥§°§¢§¡§£§¾§´§¦ §¯§¦§°§¢§·§°§¥§ª§®§½§¦ §±§°§­§Á
public:
    Menu(Command* cmd1, Command* cmd2);
    void Invoke(int cmdIndex);
    void Undo(int count);
    void Redo(int count);
private:
	vector<Command*> availCmds;
	vector<Command*> lastCmds;
	int undoIndex = -1;
};

Menu::Menu(Command* cmd1, Command* cmd2)
{
    // §²§¦§¡§­§ª§©§µ§«§´§¦ §¬§°§¯§³§´§²§µ§¬§´§°§²
    availCmds.push_back(cmd1);
	availCmds.push_back(cmd2);
	
	vector<Command*> V;
	V.push_back(cmd1);
	V.push_back(cmd2);
	
	Command* cmd3 = new MacroCommand(V);
	availCmds.push_back(cmd3);
}

void Menu::Invoke(int cmdIndex)
{
    // §²§¦§¡§­§ª§©§µ§«§´§¦ §®§¦§´§°§¥
    Command* cmd = availCmds[cmdIndex];
	cmd->Execute();
	
	int n = lastCmds.size();
	undoIndex++;
	
	if (n > undoIndex) 
	{
		lastCmds.erase(lastCmds.begin() + undoIndex, lastCmds.end());
	}
	lastCmds.push_back(cmd);
}

void Menu::Undo(int count)
{
    // §²§¦§¡§­§ª§©§µ§«§´§¦ §®§¦§´§°§¥
    for (int i = 0; (i < count) && (undoIndex >= 0); i++) 
	{
		lastCmds[undoIndex]->Unexecute();
		undoIndex--;
	}
}
void Menu::Redo(int count)
{
    // §²§¦§¡§­§ª§©§µ§«§´§¦ §®§¦§´§°§¥
    for (int i = 0; (i < count) && (undoIndex + 1 < lastCmds.size()); i++) 
	{
		undoIndex++;
		lastCmds[undoIndex]->Execute();
	}
}

Command* f(char c)
{
	if (c == 'A') return new CommandA();
	if (c == 'B') return new CommandB();
	if (c == 'C') return new CommandC();
}

void Solve()
{
    Task("OOP3Behav9");
	char c1, c2;
	pt >> c1 >> c2;
	Command* C1 = f(c1);
	Command* C2 = f(c2);

	Menu* M = new Menu(C1, C2);
	int N;
	pt >> N;
//	vector<pair<char, int>> V;
	for (int i = 0; i < N; i++) 
	{
		string str;
		pt >> str;
		if (str[0] == 'I') M->Invoke(str[1] - '0');
		if (str[0] == 'U') M->Undo(str[1] - '0');
		if (str[0] == 'R') M->Redo(str[1] - '0');
	}
}
