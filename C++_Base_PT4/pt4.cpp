//--------------------------------------------------//
//  Programming Taskbook module                     //
//  for Code::Blocks and Dev-C++                    //
//                                                  //
//            Copyright (C) M.E.Abramyan, 2006-2021 //
//--------------------------------------------------//
//  WARNING! Altering the contents of this file     //
//  may cause Programming Taskbook to malfunction.  //
//--------------------------------------------------//

#include <windows.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iterator>
using namespace std;
typedef void (WINAPI *TASK_)(const char*);
typedef void (WINAPI *GETB_)(long*);
typedef void (WINAPI *GETN_)(long*);
typedef void (WINAPI *GETR_)(double*);
typedef void (WINAPI *GETC_)(char*);
typedef void (WINAPI *GETS_)(char*);
typedef void (WINAPI *GETP_)(void**);
typedef void (WINAPI *PUTB_)(long);
typedef void (WINAPI *PUTN_)(long);
typedef void (WINAPI *PUTR_)(double);
typedef void (WINAPI *PUTC_)(char);
typedef void (WINAPI *PUTS_)(const char*);
typedef void (WINAPI *PUTP_)(void*);
typedef void (WINAPI *DISPOSEP_)(void*);
typedef void (WINAPI *STARTPT_)(long);
typedef void (WINAPI *NOPARAM_)(void);
typedef void (WINAPI *CHECKPT_)(char*, long*);
typedef void (WINAPI *RAISEPT_)(const char*,const  char*);
HINSTANCE FLibHandle = 0;
TASK_ task_;
GETB_ getB_;
GETN_ getN_;
GETR_ getR_;
GETC_ getC_;
GETS_ getS_;
GETP_ getP_;
PUTB_ putB_;
PUTN_ putN_;
PUTR_ putR_;
PUTC_ putC_;
PUTS_ putS_;
PUTP_ putP_;
DISPOSEP_ disposeP_;
STARTPT_ startPT_;
NOPARAM_ freePT_;
CHECKPT_ checkPT_;
RAISEPT_ raisePT_;
PUTS_ show_;
NOPARAM_ hidetask_;
GETS_ getExename_;
long InfoT;
char InfoS[255];


struct TNode
{
  int Data;
  TNode* Next;
  TNode* Prev;
  TNode* Left;
  TNode* Right;
  TNode* Parent;
};

void Task(const char* name)
{
  if (FLibHandle) (*task_)(name);
}

void _DeleteNode(void* p)
{
  if (FLibHandle) (*disposeP_)(p);
}

void DeleteNode(TNode* p)
{
  if (FLibHandle) (*disposeP_)(p);
}

void MBox(const char* s)
{
  MessageBox(0,s,"Programming Taskbook 4",MB_ICONERROR);
}

void unloadlibPT()
{
  if (freePT_ != NULL) freePT_();
  if (FLibHandle) FreeLibrary(FLibHandle);
  FLibHandle = 0;
}

void MBox1()
{
  unloadlibPT();
  MessageBox(0,"Wrong or corrupted version of PT4.DLL. You should reinstall Programming Taskbook.",
    "Programming Taskbook 4",MB_ICONERROR);
}

class PTManager
{
  public:
  PTManager();
  ~PTManager();
};

PTManager::PTManager()
{
  FLibHandle =::LoadLibrary("pt4.dll");
  if (FLibHandle == 0)
    {
    unloadlibPT();
    MBox("Could not load PT4.DLL. You should reinstall Programming Taskbook.");
    return;
    }
  task_=(TASK_)::GetProcAddress(FLibHandle,"task");
  if (task_ == 0)
    {
      MBox1(); return;
    }

  getB_ =(GETB_)::GetProcAddress(FLibHandle,"getb");
  if (getB_ == 0)
    {
      MBox1(); return;
    }

  getN_ = (GETN_)::GetProcAddress(FLibHandle,"getn");
  if (getN_ == 0)
    {
      MBox1(); return;
    }

  getR_ = (GETR_)::GetProcAddress(FLibHandle,"getr");
  if (getR_ == 0)
    {
      MBox1(); return;
    }

  getC_ = (GETC_)::GetProcAddress(FLibHandle,"getc");
  if (getC_ == 0)
    {
      MBox1(); return;
    }

  getS_ = (GETS_)::GetProcAddress(FLibHandle,"gets");
  if (getS_ == 0)
    {
      MBox1(); return;
    }

  getP_ = (GETP_)::GetProcAddress(FLibHandle,"getp");
  if (getP_ == 0)
    {
      MBox1(); return;
    }

  putB_ = (PUTB_)::GetProcAddress(FLibHandle,"putb");
  if (putB_ == 0)
    {
      MBox1(); return;
    }

  putN_ = (PUTN_)::GetProcAddress(FLibHandle,"putn");
  if (putN_ == 0)
    {
      MBox1(); return;
    }
  putR_ = (PUTR_)::GetProcAddress(FLibHandle,"putr");
  if (putR_ == 0)
    {
      MBox1(); return;
    }

  putC_ = (PUTC_)::GetProcAddress(FLibHandle,"putc");
  if (putC_ == 0)
    {
      MBox1(); return;
    }

  putS_ = (PUTS_)::GetProcAddress(FLibHandle,"puts");
  if (putS_ == 0)
    {
      MBox1(); return;
    }

  putP_ = (PUTP_)::GetProcAddress(FLibHandle,"putp");
  if (putP_ == 0)
    {
      MBox1(); return;
    }

  disposeP_ = (DISPOSEP_)::GetProcAddress(FLibHandle,"disposep");
  if (disposeP_ == 0)
    {
      MBox1(); return;
    }

  startPT_ = (STARTPT_)::GetProcAddress(FLibHandle,"startpt");
  if (startPT_ == 0)
    {
      MBox1(); return;
    }

  freePT_ = (NOPARAM_)::GetProcAddress(FLibHandle,"freept");
  if (freePT_ == 0)
    {
      MBox1(); return;
    }

  checkPT_ = (CHECKPT_)::GetProcAddress(FLibHandle,"checkpt");
  if (checkPT_ == 0)
    {
      MBox1(); return;
    }

  raisePT_ = (RAISEPT_)::GetProcAddress(FLibHandle,"raisept");
  if (raisePT_ == 0)
    {
      MBox1(); return;
    }
  show_ = (PUTS_)::GetProcAddress(FLibHandle,"show");
  hidetask_ = (NOPARAM_)::GetProcAddress(FLibHandle,"hidetask");
  getExename_ = (GETS_)::GetProcAddress(FLibHandle,"getexename");
  startPT_(8 + 16777216);
}

PTManager::~PTManager()
{
if (FLibHandle)
  {
    InfoS[0] = '\0';
    InfoT = 0;
    checkPT_(InfoS, &InfoT);
    if ((InfoT==0) && (strcmp(InfoS,""))!=0)
      MBox(InfoS);
    unloadlibPT();
  }
}

void raisePT(const char* s1, const char* s2)
{
if (FLibHandle)
  (*raisePT_)(s1,s2);
}

class PTIO
{};

void PutB(bool a)
{
if (FLibHandle)
  {
  if (a) (*putB_)(1);
  else   (*putB_)(0);
  }
}

PTIO& operator << (PTIO& p, bool a)
{
PutB(a);
return p;
}

void PutN(int a)
{
if (FLibHandle) (*putN_)(a);
}

PTIO& operator << (PTIO& p, int a)
{
PutN(a);
return p;
}

PTIO& operator << (PTIO& p, long a)
{
PutN((int)a);
return p;
}

PTIO& operator << (PTIO& p, unsigned int a)
{
PutN((int)a);
return p;
}

void PutD(double a)
{
if (FLibHandle) (*putR_)(a);
}

PTIO& operator << (PTIO& p, double a)
{
PutD(a);
return p;
}

void PutC(char a)
{
if (FLibHandle) (*putC_)(a);
}

PTIO& operator << (PTIO& p, char a)
{
PutC(a);
return p;
}

void PutS(const char* a)
{
if (FLibHandle) (*putS_)(a);
}

void PutS(string a)
{
if (FLibHandle) (*putS_)((char*)a.c_str());
}

PTIO& operator << (PTIO& p, const char* a)
{
PutS(a);
return p;
}

PTIO& operator << (PTIO& p, string a)
{
PutS(a);
return p;
}

void PutP(TNode* a)
{
if (FLibHandle) (*putP_)(a);
}

PTIO& operator << (PTIO& p, TNode* a)
{
PutP(a);
return p;
}

void GetB(bool& a)
{
long x0;
if (FLibHandle)
  {
   x0 = 0;
   (*getB_)(&x0);
   a = (x0 == 1);
  }
}

PTIO& operator >> (PTIO& p, bool& a)
{
GetB(a);
return p;
}

void GetN(int& a)
{
long x0;
if (FLibHandle)
  {
   x0 = 0;
   (*getN_)(&x0);
   a = (int)x0;
  }
}

PTIO& operator >> (PTIO& p, int& a)
{
GetN(a);
return p;
}

void GetN(unsigned int& a)
{
long x0;
if (FLibHandle)
  {
   x0 = 0;
   (*getN_)(&x0);
   a = (unsigned int)x0;
  }
}

PTIO& operator >> (PTIO& p, unsigned int& a)
{
GetN(a);
return p;
}

void GetN(short& a)
{
long x0;
if (FLibHandle)
  {
   x0 = 0;
   (*getN_)(&x0);
   a = short(x0);
  }
}

PTIO& operator >> (PTIO& p, short& a)
{
GetN(a);
return p;
}

void GetN(long& a)
{
if (FLibHandle)
  (*getN_)(&a);
}

PTIO& operator >> (PTIO& p, long& a)
{
GetN(a);
return p;
}

void GetD(double& a)
{
if (FLibHandle)
   (*getR_)(&a);
}

PTIO& operator >> (PTIO& p, double& a)
{
GetD(a);
return p;
}

void GetD(float& a)
{
double x0;
if (FLibHandle)
  {
   x0 = 0;
   (*getR_)(&x0);
   a = float(x0);
  }
}

PTIO& operator >> (PTIO& p, float& a)
{
GetD(a);
return p;
}

void GetC(char& a)
{
if (FLibHandle)
  (*getC_)(&a);
}

PTIO& operator >> (PTIO& p, char& a)
{
GetC(a);
return p;
}

void GetS(char* a)
{
if (FLibHandle)
  {
   InfoS[0] = '\0';
   (*getS_)(InfoS);
   strcpy(a, InfoS);
  }
}

void GetS(string& a)
{
if (FLibHandle)
  {
   InfoS[0] = '\0';
   (*getS_)(InfoS);
   a = InfoS;
  }
}


PTIO& operator >> (PTIO& p, char* a)
{
GetS(a);
return p;
}

PTIO& operator >> (PTIO& p, string& a)
{
GetS(a);
return p;
}

void GetP(TNode*& a)
{
void* x0;
if (FLibHandle)
  {
  x0 = NULL;
  (*getP_)(&x0);
  a = (TNode*)x0;
  }
}

PTIO& operator >> (PTIO& p, TNode*& a)
{
GetP(a);
return p;
}

PTManager ptMan;

PTIO pt;

DWORD Filter(DWORD dw)
{
   if (dw==EXCEPTION_ACCESS_VIOLATION) {raisePT("ACCESS_VIOLATION","");}
   if (dw==EXCEPTION_INT_DIVIDE_BY_ZERO) {raisePT("INT_DIVIDE_BY_ZERO","");}
   if (dw==EXCEPTION_ARRAY_BOUNDS_EXCEEDED) {raisePT("ARRAY_BOUNDS_EXCEEDED","");}
   if (dw==EXCEPTION_DATATYPE_MISALIGNMENT) {raisePT("DATATYPE_MISALIGNMENT","");}
   if (dw==EXCEPTION_FLT_DENORMAL_OPERAND) {raisePT("FLT_DENORMAL_OPERAND","");}
   if (dw==EXCEPTION_FLT_DIVIDE_BY_ZERO) {raisePT("FLT_DIVIDE_BY_ZERO","");}
   if (dw==EXCEPTION_FLT_INEXACT_RESULT) {raisePT("FLT_INEXACT_RESULT","");}
   if (dw==EXCEPTION_FLT_INVALID_OPERATION) {raisePT("FLT_INVALID_OPERATION","");}
   if (dw==EXCEPTION_FLT_OVERFLOW) {raisePT("FLT_OVERFLOW","");}
   if (dw==EXCEPTION_FLT_STACK_CHECK) {raisePT("FLT_STACK_CHECK","");}
   if (dw==EXCEPTION_FLT_UNDERFLOW) {raisePT("FLT_UNDERFLOW","");}
   if (dw==EXCEPTION_ILLEGAL_INSTRUCTION) {raisePT("ILLEGAL_INSTRUCTION","");}
   if (dw==EXCEPTION_IN_PAGE_ERROR) {raisePT("IN_PAGE_ERROR","");}
   if (dw==EXCEPTION_INT_OVERFLOW) {raisePT("INT_OVERFLOW","");}
   if (dw==EXCEPTION_INVALID_DISPOSITION) {raisePT("INVALID_DISPOSITION","");}
   if (dw==EXCEPTION_NONCONTINUABLE_EXCEPTION) {raisePT("NONCONTINUABLE_EXCEPTION","");}
   if (dw==EXCEPTION_PRIV_INSTRUCTION) {raisePT("PRIV_INSTRUCTION","");}
   if (dw==EXCEPTION_SINGLE_STEP) {raisePT("SINGLE_STEP","");}
   if (dw==EXCEPTION_STACK_OVERFLOW) {raisePT("STACK_OVERFLOW","");}
   return EXCEPTION_EXECUTE_HANDLER;
}



streamsize d = 2;

void Show(const char* s)
{
  if (FLibHandle)
  {
    if (! show_)
      MBox("The Show function is not available in this version of PT4.");
    else
      (*show_)(s);
  }
}

void Show(char c)
{
  ostringstream os;
  os << c;
  Show(os.str().c_str());
}

void ShowLine(char c)
{
  Show(c); Show("\n");
}

void Show(string s)
{
  Show(s.c_str());
}

void Show(const char* s, int a, int w = 0)
{
  ostringstream os;
  os << s << setw(w) << a;
  Show(os.str().c_str());
}

void Show(string s, int a, int w = 0)
{
  Show(s.c_str(), a, w);
}

void Show(const char* s, double a, int w = 0)
{
  ostringstream os;
  os << s << setw(w);
  if (d > 0)
    os << fixed << setprecision(d);
  else
  {
    os << scientific;
    if (d)
          os << setprecision(-d);
  }
  os << a;
  Show(os.str().c_str());
}

void Show(string s, double a, int w = 0)
{
  Show(s.c_str(), a, w);
}

void Show(int a, int w = 0)
{
  Show("", a, w);
}

void Show(double a, int w = 0)
{
  Show("", a, w);
}

void ShowLine()
{
  Show("\n");
}

void ShowLine(const char* s)
{
  Show(s); Show("\n");
}

void ShowLine(string s)
{
  Show(s.c_str()); Show("\n");
}

void ShowLine(const char* s, int a, int w = 0)
{
  Show(s, a, w); Show("\n");
}

void ShowLine(string s, int a, int w = 0)
{
  Show(s.c_str(), a, w); Show("\n");
}

void ShowLine(const char* s, double a, int w = 0)
{
  Show(s, a, w); Show("\n");
}

void ShowLine(string s, double a, int w = 0)
{
  Show(s.c_str(), a, w); Show("\n");
}

void ShowLine(int a, int w = 0)
{
  Show("", a, w); Show("\n");
}

void ShowLine(double a, int w = 0)
{
  Show("", a, w); Show("\n");
}

void Show(unsigned int a, int w = 0)
{
    Show("", (int)a, w);
}
void Show(const char* s, unsigned int a, int w = 0)
{
    Show(s, (int)a, w);
}
void Show(string s, unsigned int a, int w = 0)
{
    Show(s, (int)a, w);
}
void ShowLine(unsigned int a, int w = 0)
{
    Show("", (int)a, w); Show("\n");
}
void ShowLine(const char* s, unsigned int a, int w = 0)
{
    Show(s, (int)a, w); Show("\n");
}
void ShowLine(string s, unsigned int a, int w = 0)
{
    Show(s, (int)a, w); Show("\n");
}


void HideTask()
{
  if (FLibHandle)
  {
    if (! hidetask_)
      MBox("The HideTask function is not available in this version of PT4.");
    else
      (*hidetask_)();
  }
}

void SetPrecision(int n)
{
  d = n;
}

char _getExename_[255];

char* GetExename()
{
  if (getExename_ == 0)
    _getExename_[0] = '\0';
  else
    getExename_(_getExename_);
  return _getExename_;
}
