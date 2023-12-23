// File: "OOP3Behav10"
using PT4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PT4Tasks
{
    public class MyTask : PT
    {
        public abstract class State
        {
            public abstract string GetNextToken();
        }

    public class ConcreteStateNormal : State
    {
        Context ct;
        int index;
        public ConcreteStateNormal(Context ct, int index)
        {
            this.ct = ct;
            this.index = index;
        }
        public override string GetNextToken(){
            State s = null;
            string str = "";
            while(ct.GetCharAt(index) != '.')
            {
                int k = 0;
                switch(ct.GetCharAt(index))
                {
                    case '\"':{
                        k = 1;
                       s = new ConcreteStateString(this.ct, index + 1);
                        break;   
                    }
                    case '{':{
                        k = 1;
                        s = new ConcreteStateComm(this.ct, index + 1);
                        break; 
                    }             
                    default:
                        break;
                }
                if(k == 0) str = str + ct.GetCharAt(index);
                else break;
                index ++;
            }
            if(ct.GetCharAt(index) == '.')
                s = new ConcreteStateFin();
            ct.SetState(s);
            return "Normal:" + str;
        }
    }

    public class ConcreteStateString : State
    {
        Context ct;
        int index;
        public ConcreteStateString(Context ct, int index)
        {
            this.ct = ct;
            this.index = index;
        }
        public override string GetNextToken()
        {
            //State s = null;
            string str = "";

            while(ct.GetCharAt(index) != '.')
            {
                int k = 0;
                if(ct.GetCharAt(index) == '\"')
                {
                    if(ct.GetCharAt(index + 1) != '\"')
                    {
                        k = 1;
                        ct.SetState(new ConcreteStateNormal(ct, index + 1));
                        break;
                    }else index ++;
                }
                if(k == 0) 
                    str = str + ct.GetCharAt(index);
                index ++;
            }

            if(ct.GetCharAt(index) == '.'){
                ct.SetState(new ConcreteStateFin());
                return "ErrString:" + str;
            }
            return "String:" + str;
        }

    }

    public class ConcreteStateComm : State
    {
        Context ct;
        int index;
        public ConcreteStateComm(Context ct, int index)
        {
            this.ct = ct;
            this.index = index;
        }
        public override string GetNextToken()
        {
            string str = "";

            while (ct.GetCharAt(index) != '.')
            {
                int k = 0;
                if (ct.GetCharAt(index) == '}') {
                    k = 1;
                    ct.SetState( new ConcreteStateNormal(ct, index + 1) );
                    break;
                }
                if(k == 0)
                    str = str + ct.GetCharAt(index);
                index++;
            }
            if (ct.GetCharAt(index) == '.') {
                    ct.SetState(new ConcreteStateFin());
                    return "ErrComm:" + str;
                }
            return "Comm:" + str;
        }
    }

    public class ConcreteStateFin : State
    {
        public ConcreteStateFin() {}
        public override string GetNextToken()
        {
            return "";
        }
    }

        // Implement the Context class

    public class Context
    {
        State currentState;
        string text;
        public Context(string str)
        {
            this.text = str;
        }
        public char GetCharAt(int index)
        {
            return text[index];
        }

        public void SetState(State newState)
        {
            this.currentState = newState;
        }
        public string GetNextToken()
        {
            return currentState.GetNextToken();
        }
    }

        public static void Solve()
        {
            Task("OOP3Behav10");
            string str = GetString();
            string s ;
            Context ct = new Context(str);
            ct.SetState(new ConcreteStateNormal(ct, 0));

            while((s = ct.GetNextToken()) != "")
            {
                Put(s);
                ShowLine(s);
            }
        }
    }
}
