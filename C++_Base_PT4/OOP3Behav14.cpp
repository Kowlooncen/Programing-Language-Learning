#include "pt4.h"
#include <typeinfo> 

using namespace std;

class Request
{
public:
    virtual string ToStr() = 0;
};

// Implement the RequestA and RequestB descendant classes

class RequestA : public Request
{
private:
    int param;
public:
    RequestA(int param) :param(param) {}
    int GetParam()
    {
        return param;
    }
    string ToStr()
    {
        return "A:" + to_string(param);
    }

};

class RequestB : public Request
{
private:
    string param;
public:
    RequestB(string param) :param(param) {}
    string GetParam()
    {
        return param;
    }
    string ToStr()
    {
        return "B:" + param;
    }
};

class Handler
{
    Handler* successor;
public:
    Handler(Handler* successor) : successor(successor) {}
    virtual void HandleRequest(Request* req);
    ~Handler();
};

void Handler::HandleRequest(Request* req)
{
    // Implement the method
    if (successor != NULL)
    {
        successor->HandleRequest(req);
    }
    else
    {
    	ShowLine("Request " + req->ToStr() + " not processed");
        pt << "Request " + req->ToStr() + " not processed";
    }
}

Handler::~Handler()
{
    // Implement the destructor
}

// Implement the HandlerA and HandlerB descendant classes

class HandlerA :public Handler
{
public:
	HandlerA(Handler* successor, int id, int param1, int param2) :Handler(successor), id(id), param1(param1), param2(param2) {}
	
	void HandleRequest(Request* req)
	{
		if (typeid(*req).name() == typeid(RequestA).name())
		{
			RequestA* A_req = dynamic_cast<RequestA*>(req);
            if (A_req->GetParam() <= param2 && A_req->GetParam() >= param1)
            {
                pt << "Request " + A_req->ToStr() + " processed by handler " + to_string(id);
            }
            else {
                Handler::HandleRequest(req);
            }
        }
        else {
            Handler::HandleRequest(req);
        }
	}
	
private:
    int id;
    int param1;
    int param2;
};

class HandlerB :public Handler
{
public:
	HandlerB(Handler* successor, int id, string param1, string param2) :Handler(successor), id(id), param1(param1), param2(param2) {}
	void HandleRequest(Request* req){
		if (typeid(*req).name() == typeid(RequestB).name())
		{
			RequestB* B_req = dynamic_cast<RequestB*>(req);
            if (B_req->GetParam() <= param2 && B_req->GetParam() >= param1)
            {
            	ShowLine("Request " + B_req->ToStr() + " processed by handler " + to_string(id));
                pt << "Request " + B_req->ToStr() + " processed by handler " + to_string(id);
            }
            else {
                Handler::HandleRequest(req);
            }
		}else {
            Handler::HandleRequest(req);
        }
	}
	 
private:
	int id;
    string param1;
    string param2;
};

class Client
{
    Handler* h;
public:
    Client(Handler* h) : h(h) {Show("create");}
    void SendRequest(Request* req);
    ~Client();
};

void Client::SendRequest(Request* req)
{
	Show("OK");
    h->HandleRequest(req);
}
Client::~Client()
{
    // Implement the destructor
}

void Solve()
{
    Task("OOP3Behav14");
	
	int N;
	pt >> N;
	
	Handler* h(NULL);
	Handler* hd[10];
	
	for(int i = 0; i < N; i++)
	{
		char c;
		pt >> c;
		if(c == 'A'){
			int p1, p2;
            pt >> p1 >> p2;
            if (i == 0)
                hd[i] = new HandlerA(h, i, p1, p2);
            else
                hd[i] = new HandlerA(hd[i - 1], i, p1, p2);
		}
		if(c == 'B'){
			string p1, p2;
            pt >> p1 >> p2;
            if (i == 0)
                hd[i] = new HandlerB(h, i, p1, p2);
            else
                hd[i] = new HandlerB(hd[i - 1], i, p1, p2);
		}
	}
	
	Client* cli = new Client(hd[N-1]);
	int K;
	pt >> K;
	for(int i = 0; i < K; i++)
	{
		Request* req;
		char c;
		pt >> c;
		if(c == 'A'){
			int p;
            pt >> p;
            ShowLine(p);
            req = new RequestA(p);
            cli->SendRequest(req);
            delete req;
		}
		if(c == 'B'){
			string p;
            pt >> p;
            ShowLine(p);
            req = new RequestB(p);
            cli->SendRequest(req);
            delete req;
        }
	}
}
