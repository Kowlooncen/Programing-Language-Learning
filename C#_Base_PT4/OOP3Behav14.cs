// File: "OOP3Behav14"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
////
namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class Request
        {
            public abstract string ToStr();
        }
///
        // Implement the RequestA and RequestB descendant classes

        public class RequestA : Request 
        {
            int param;
            public RequestA(int param)
            {
                this.param = param;
            }
            public int GetParam()
            {
                return param;
            }
            public override string ToStr(){
                return "A:" + Convert.ToString(param); 
            }
        } 

        public class RequestB : Request
        {
            string param;
            public RequestB(string param)
            {
                this.param = param;
            }
            public string GetParam()
            {
                return param;
            }
            public override string ToStr(){
                return "B:" + Convert.ToString(param); 
            }
        } 

        public class Handler
        {
            protected Handler successor;
            public Handler(){}

            public Handler(Handler successor)
            {
                this.successor = successor;
            }
            public virtual void HandleRequest(Request req)
            {
                if(successor != null)
                {
                    successor.HandleRequest(req);
                }else{
                    Put("Request " + req.ToStr() + " not processed");
                }
            }
        }

        // Implement the HandlerA and HandlerB descendant classes
        public class HandlerA : Handler{
            int id;
            int param1;
            int param2;

            public HandlerA(Handler s, int id,int param1, int param2) : base(s)
            {
                successor = s;
                this.id = id;
                this.param1 = param1;
                this.param2 = param2;
            }
            public override void HandleRequest(Request req)
            {
                //base.HandleRequest(req);
                if(req.GetType().Name == "RequestA"){
                    RequestA A_req = req as RequestA;
                    if(A_req.GetParam() <= param2 && A_req.GetParam() >= param1)
                    {
                        Put("Request " + A_req.ToStr() + " processed by handler " + Convert.ToString(id));
                    }else{
                        base.HandleRequest(req);
                    }
                }else{
                    base.HandleRequest(req);
                }
            }
        }

        public class HandlerB : Handler{
            int id;
            string param1;
            string param2;

            public HandlerB(Handler s, int id,string param1, string param2) : base(s)
            {
                successor = s;
                this.id = id;
                this.param1 = param1;
                this.param2 = param2;
            }
            public override void HandleRequest(Request req)
            {
                //base.HandleRequest(req);
                if(req.GetType().Name == "RequestB"){
                    RequestB B_req = req as RequestB;
                    if(string.Compare(B_req.GetParam(), param2) <=0 && string.Compare(B_req.GetParam(), param1)>=0)
                    {
                        Put("Request " + B_req.ToStr() + " processed by handler " + Convert.ToString(id));
                    }else{
                        base.HandleRequest(req);
                    }
                }else{
                    base.HandleRequest(req);
                }
            }
        }

        public class Client
        {
            Handler h;
            public Client(Handler h)
            {
                this.h = h;
            }
            public void SendRequest(Request req)
            {
                h.HandleRequest(req);
            }
        }

        public static void Solve()
        {
            Task("OOP3Behav14");
            // Request a = new RequestA(3);
            // Show(a.GetType().Name);
            int N = GetInt();

            Handler h = null;
            Handler[] hd = new Handler [10];

            for(int i = 0; i < N; i++)
            {
                char c = GetChar();
                if(c == 'A'){
                    int p1 = GetInt(), p2 = GetInt();
                    if(i == 0)
                    {
                        hd[i] = new HandlerA(h, i, p1, p2);
                    }
                    else{
                        hd[i] = new HandlerA(hd[i-1], i, p1, p2);
                    }
                }
                if(c == 'B'){
                    string p1 = GetString(), p2 = GetString();
                    if(i == 0)
                    {
                        hd[i] = new HandlerB(h, i, p1, p2);
                    }
                    else{
                        hd[i] = new HandlerB(hd[i-1], i, p1, p2);
                    }
                }
            }
            Client cli = new Client(hd[N-1]);
            int K = GetInt();

            for(int i = 0; i < K; i++)
            {
                Request req = null;
                char ch = GetChar();
                if(ch == 'A'){
                    int p = GetInt();
                    req = new RequestA(p);
                    cli.SendRequest(req);
                }
                if(ch == 'B')
                {
                    string p = GetString();
                    req = new RequestB(p);
                    cli.SendRequest(req);
                }
            }
        }
    }
}
