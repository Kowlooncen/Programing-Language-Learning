#include "pt4.h"
using namespace std;

class Context
{
    // Add the constructor, required fields and methods
};

class AbstractExpression
{
public:
    virtual string InterpretA(Context* cont) = 0;
    virtual string InterpretB(Context* cont) = 0;
};

// Implement the TermStr, NontermConcat, NontermIf
//   and NontermLoop descendant classes

void Solve()
{
    Task("OOP3Behav17");

}
